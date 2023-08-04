![logo](logo.png)

# raygui.zig
Idiomatic [raygui](https://github.com/raysan5/raygui) **RAYGUIAPI** (raygui.h) bindings for [Zig](https://ziglang.org/) (master).

## usage

The easy way would be adding this as submodule directly in your source folder.
Thats what I do until there is an official package manager for Zig.

```sh
cd $YOUR_SRC_FOLDER
git submodule add https://github.com/ryupold/raygui.zig raygui
git submodule update --init --recursive
```

The bindings have been prebuilt so you just need to add raylib as module

build.zig:
```zig
const raylib = @import("path/to/raylib.zig/build.zig");
const raygui = @import("path/to/raygui.zig/build.zig");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardOptimizeOption(.{});
    const exe = ...;
    raylib.addTo(b, exe, target, mode);
    raygui.addTo(b, exe, target, mode);
}
```

and import in main.zig:
```zig
const raylib = @import("raylib");
const raygui = @import("raygui");

pub fn main() void {
    raylib.InitWindow(800, 800, "hello world!");
    raylib.SetConfigFlags(.FLAG_WINDOW_RESIZABLE);
    raylib.SetTargetFPS(60);

    defer raylib.CloseWindow();

    while (!raylib.WindowShouldClose()) {
        raylib.BeginDrawing();
        defer raylib.EndDrawing();
        
        raylib.ClearBackground(raylib.BLACK);
        raylib.DrawFPS(10, 10);

        if (raygui.GuiButton(.{ .x = 100, .y = 100, .width = 200, .height = 100 }, "press me!")) {
            std.debug.print("pressed\n", .{});
        }
    }
}
```

> See `build.zig` in [examples-raylib.zig](https://github.com/ryupold/examples-raylib.zig) for how to build.

> Note: you only need the files `raygui.zig`, `raygui_marshal.h` and `raygui_marshal.c` for this to work
> 
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
