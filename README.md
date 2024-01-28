![logo](logo.png)

# raygui.zig
Idiomatic [raygui](https://github.com/raysan5/raygui) **RAYGUIAPI** (raygui.h) bindings for [Zig](https://ziglang.org/) (master).

## <a id="usage">usage</a>

Add this as a dependency to your `build.zig.zon`
```zig
.{
    .name = "example",
    .version = "1.0.0",
    .paths = ...,
    .dependencies = .{
        .raylib_zig = .{
            .url = "https://github.com/ryupold/raygui.zig/archive/<commit>.tar.gz",
            .hash = "<hash>",
        },
    },
}
```

Then add the raygui module to your compile step in your `build.zig`. Note that module has a dependency on [`raygui.zig`](https://github.com/ryupold/raygui.zig), so you should probably configure your compile step with that.
```zig
const std = @import("std");

pub fn build(b: *std.Build) !void
{
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});
    const compile = ...;

    const raygui_zig = b.dependency("raygui_zig", .{
        .target = target,
        .optimize = optimize,
    });
    compile.root_module.addImport("raygui", raygui_zig.module("raygui"));
}
```

and import in main.zig:
```zig
const raylib = @import("raylib");
const raygui = @import("raygui");

pub fn main() void {
    raylib.SetConfigFlags(raylib.ConfigFlags{ .FLAG_WINDOW_RESIZABLE = true });
    raylib.InitWindow(800, 800, "hello world!");
    raylib.SetTargetFPS(60);

    defer raylib.CloseWindow();

    while (!raylib.WindowShouldClose()) {
        raylib.BeginDrawing();
        defer raylib.EndDrawing();

        raylib.ClearBackground(raylib.BLACK);
        if (raygui.GuiButton(.{ .x = 100, .y = 100, .width = 200, .height = 100 }, "press me!") != 0) {
            std.debug.print("pressed\n", .{});
        }
    }
}
```

> See `build.zig` in [examples-raylib.zig](https://github.com/ryupold/examples-raylib.zig) for how to build.

This weird workaround with `raygui_marshal.h/raygui_marshal.c` I actually had to make for Webassembly builds to work, because passing structs as function parameters or returning them cannot be done on the Zig side somehow. If I try it, I get a runtime error "index out of bounds". This happens only in WebAssembly builds. So `raygui_marshal.c` must be compiled with `emcc`. See [build.zig](https://github.com/ryupold/examples-raylib.zig/blob/main/build.zig) in the examples.

## custom definitions
An easy way to fix binding mistakes is to edit them in `bindings.json` and setting the custom flag to true. This way the binding will not be overriden when calling `zig build intermediate`. 
Additionally you can add custom definitions into `inject.zig, inject.h, inject.c` these files will be prepended accordingly.

## disclaimer
I have NOT tested most of the generated functions, so there might be bugs. Especially when it comes to pointers as it is not decidable (for the generator) what a pointer to C means. Could be single item, array, sentinel terminated and/or nullable. If you run into crashes using one of the functions or types in `raygui.zig` feel free to [create an issue](https://github.com/ryupold/raygui.zig/issues) and I will look into it.

## generate bindings 
for current raygui source (submodule)

```sh
zig build parse # create JSON files with raylib_parser
zig build intermediate # generate bindings.json (keeps definitions with custom=true)
zig build bindings # write all intermediate bindings to raylib.zig
```

For easier diffing and to follow changes to the raygui repository I commit also the generated json files.
