const std = @import("std");

const generate = @import("generate.zig");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const raylib_zig = b.dependency("raylib_zig", .{
        .target = target,
        .optimize = optimize,
    });
    const raylib = raylib_zig.builder.dependency("raylib", .{
        .target = target,
        .optimize = optimize,
    });
    const raygui = b.dependency("raygui", .{
        .target = target,
        .optimize = optimize,
    });

    const module = b.addModule("raygui", .{
        .root_source_file = .{ .path = "raygui.zig" },
        .target = target,
        .optimize = optimize,
        .imports = &.{
            .{ .name = "raylib", .module = raylib_zig.module("raylib") },
        },
    });
    module.addIncludePath(.{ .path = "." });
    module.addIncludePath(raygui.path("src"));
    module.addIncludePath(raylib.path("src"));
    // TODO: relative path doesn't work here when used as a dependency, not sure why...
    const marshal_c_path = try b.build_root.join(b.allocator, &.{"raygui_marshal.c"});
    module.addCSourceFile(.{ .file = .{.path = marshal_c_path}, .flags = &.{"-DRAYGUI_IMPLEMENTATION"} });
    module.link_libc = true;
    if (target.result.os.tag == .emscripten) {
        if (b.sysroot == null) {
            @panic("Pass '--sysroot \"$EMSDK/upstream/emscripten\"'");
        }
        const emscripten_include_path = try std.fs.path.join(b.allocator, &.{ b.sysroot.?, "cache", "sysroot", "include" });
        module.addIncludePath(.{ .path = emscripten_include_path });
    }

    // Set up binding generation library & exes.
    //--- parse raygui and generate JSONs for all signatures --------------------------------------
    const jsons = b.step("parse", "parse raygui headers and generate raylib parser output as json");
    const raylib_parser_build = b.addExecutable(.{
        .name = "raylib_parser",
        .root_source_file = .{.path = "raylib_parser.zig"},
        .target = target,
        .optimize = optimize,
    });
    raylib_parser_build.addCSourceFile(.{ .file = raylib.path("parser/raylib_parser.c"), .flags = &.{} });
    raylib_parser_build.linkLibC();

    //raygui
    const raygui_H = b.addRunArtifact(raylib_parser_build);
    const path_raygui_H = try b.allocator.dupe(u8, raygui.path("src/raygui.h").getPath(b));
    raygui_H.addArgs(&.{
        "-i", path_raygui_H,
        "-o", "raygui.json",
        "-f", "JSON",
        "-d", "RAYGUIAPI",
    });
    jsons.dependOn(&raygui_H.step);

    //--- Generate intermediate -------------------------------------------------------------------
    const intermediate = b.step("intermediate", "generate intermediate representation of the results from 'zig build parse' (keep custom=true)");
    var intermediateZig = b.addRunArtifact(b.addExecutable(.{
        .name = "intermediate",
        .root_source_file = .{.path = "intermediate.zig"},
        .target = target,
    }));
    intermediate.dependOn(&intermediateZig.step);

    //--- Generate bindings -----------------------------------------------------------------------
    const bindings = b.step("bindings", "generate bindings in from bindings.json");
    var generateZig = b.addRunArtifact(b.addExecutable(.{
        .name = "generate",
        .root_source_file = .{.path = "generate.zig"},
        .target = target,
    }));
    const fmt = b.addFmt(.{ .paths = &.{generate.outputFile} });
    fmt.step.dependOn(&generateZig.step);
    bindings.dependOn(&fmt.step);

    //--- just build raylib_parser.exe ------------------------------------------------------------
    const raylib_parser_install = b.step("raylib_parser", "build ./zig-out/bin/raylib_parser.exe");
    const generateBindings_install = b.addInstallArtifact(raylib_parser_build, .{});
    raylib_parser_install.dependOn(&generateBindings_install.step);
}
