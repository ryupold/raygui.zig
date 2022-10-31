const std = @import("std");
const raygui = @cImport({
    @cInclude("raygui.h");
    @cInclude("raygui_marshal.h");
});
const raylib = @import("../raylib/raylib.zig");

pub const Rectangle = raylib.Rectangle;
pub const Vector2 = raylib.Vector2;
pub const Color = raylib.Color;
pub const RICON_SIZE = 32;
pub const RICON_DATA_ELEMENTS = 255;

/// Load style from file (.rgs)
pub fn LoadGuiStyle(_: [*:0]const u8) u32 {
    // return raygui.LoadGuiStyle(fileName);
    return 0;
}

/// Unload style
pub fn UnloadGuiStyle(_: u32) void {
    // raygui.UnloadGuiStyle(style);
}

/// Text Box control with multiple lines
pub fn GuiTextBoxMulti(_: Rectangle, _: [*]u8, _: i32, _: bool) bool {
    @panic("this gets translated wrong with cImport");
}

/// List View with extended parameters
pub fn GuiListViewEx(
    _: Rectangle,
    _: [*]const [*:0]const u8,
    _: i32,
    _: [*]i32,
    _: [*]i32,
    _: i32,
) i32 {
    @panic("TODO: link with raygui somehow");
}

pub fn textAlignPixelOffset(h: i32) i32 {
    return h % 2;
}

fn bitCheck(a: u32, b: u32) bool {
    var r: u32 = undefined;
    _ = @shlWithOverflow(u32, 1, @truncate(u5, b), &r);
    return (a & (r)) != 0;
}

/// Draw selected icon using rectangles pixel-by-pixel
pub fn GuiDrawIcon(
    icon: raygui.GuiIconName,
    posX: i32,
    posY: i32,
    pixelSize: i32,
    color: raylib.Color,
) void {
    const iconId = @enumToInt(icon);

    var i: i32 = 0;
    var y: i32 = 0;
    while (i < RICON_SIZE * RICON_SIZE / 32) : (i += 1) {
        var k: u32 = 0;
        while (k < 32) : (k += 1) {
            if (bitCheck(raygui.guiIcons[@intCast(usize, iconId * RICON_DATA_ELEMENTS + i)], k)) {
                _ = raylib.DrawRectangle(
                    posX + @intCast(i32, k % RICON_SIZE) * pixelSize,
                    posY + y * pixelSize,
                    pixelSize,
                    pixelSize,
                    color,
                );
            }

            if ((k == 15) or (k == 31)) {
                y += 1;
            }
        }
    }
}

/// Draw button with icon centered
pub fn GuiDrawIconButton(bounds: raylib.Rectangle, icon: GuiIconName, iconTint: raylib.Color) bool {
    const pressed = GuiButton(bounds, "");
    GuiDrawIcon(
        icon,
        @floatToInt(i32, bounds.x + bounds.width / 2 - @intToFloat(f32, RICON_SIZE) / 2),
        @floatToInt(i32, bounds.y + (bounds.height / 2) - @intToFloat(f32, RICON_SIZE) / 2),
        1,
        iconTint,
    );
    return pressed;
}
