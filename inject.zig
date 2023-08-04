const std = @import("std");
const raygui = @cImport({
    @cInclude("raygui.h");
    @cInclude("raygui_marshal.h");
});
const raylib = @import("raylib");

pub const Rectangle = raylib.Rectangle;
pub const Vector2 = raylib.Vector2;
pub const Color = raylib.Color;
pub const RICON_SIZE = 32;
pub const RICON_DATA_ELEMENTS = 255;

pub fn textAlignPixelOffset(h: i32) i32 {
    return h % 2;
}

fn bitCheck(a: u32, b: u32) bool {
    const r = @shlWithOverflow(1, @as(u5, @truncate(b)));
    return (a & (r[0])) != 0;
}

/// Draw selected icon using rectangles pixel-by-pixel
pub fn GuiDrawIcon(
    icon: raygui.GuiIconName,
    posX: i32,
    posY: i32,
    pixelSize: i32,
    color: raylib.Color,
) void {
    const iconId = @intFromEnum(icon);

    var i: i32 = 0;
    var y: i32 = 0;
    while (i < RICON_SIZE * RICON_SIZE / 32) : (i += 1) {
        var k: u32 = 0;
        while (k < 32) : (k += 1) {
            if (bitCheck(raygui.guiIcons[@as(usize, @intCast(iconId * RICON_DATA_ELEMENTS + i))], k)) {
                _ = raylib.DrawRectangle(
                    posX + @as(i32, @intCast(k % RICON_SIZE)) * pixelSize,
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
        @as(i32, @intFromFloat(bounds.x + bounds.width / 2 - @as(f32, @floatFromInt(RICON_SIZE)) / 2)),
        @as(i32, @intFromFloat(bounds.y + (bounds.height / 2) - @as(f32, @floatFromInt(RICON_SIZE)) / 2)),
        1,
        iconTint,
    );
    return pressed;
}
