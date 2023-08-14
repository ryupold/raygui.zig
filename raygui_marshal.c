#include "raygui.h"

void mGuiEnable(void)
{
	GuiEnable();
}

void mGuiDisable(void)
{
	GuiDisable();
}

void mGuiLock(void)
{
	GuiLock();
}

void mGuiUnlock(void)
{
	GuiUnlock();
}

bool mGuiIsLocked(void)
{
	return GuiIsLocked();
}

void mGuiSetAlpha(float alpha)
{
	GuiSetAlpha(alpha);
}

void mGuiSetState(int state)
{
	GuiSetState(state);
}

int mGuiGetState(void)
{
	return GuiGetState();
}

void mGuiSetFont(Font *font)
{
	GuiSetFont(*font);
}

void mGuiGetFont(Font *out)
{
	*out = GuiGetFont();
}

void mGuiSetStyle(int control, int property, int value)
{
	GuiSetStyle(control, property, value);
}

int mGuiGetStyle(int control, int property)
{
	return GuiGetStyle(control, property);
}

void mGuiLoadStyle(const char * fileName)
{
	GuiLoadStyle(fileName);
}

void mGuiLoadStyleDefault(void)
{
	GuiLoadStyleDefault();
}

void mGuiEnableTooltip(void)
{
	GuiEnableTooltip();
}

void mGuiDisableTooltip(void)
{
	GuiDisableTooltip();
}

void mGuiSetTooltip(const char * tooltip)
{
	GuiSetTooltip(tooltip);
}

const char * mGuiIconText(int iconId, const char * text)
{
	return GuiIconText(iconId, text);
}

void mGuiSetIconScale(int scale)
{
	GuiSetIconScale(scale);
}

unsigned int * mGuiGetIcons(void)
{
	return GuiGetIcons();
}

char ** mGuiLoadIcons(const char * fileName, bool loadIconsName)
{
	return GuiLoadIcons(fileName, loadIconsName);
}

int mGuiWindowBox(Rectangle *bounds, const char * title)
{
	return GuiWindowBox(*bounds, title);
}

int mGuiGroupBox(Rectangle *bounds, const char * text)
{
	return GuiGroupBox(*bounds, text);
}

int mGuiLine(Rectangle *bounds, const char * text)
{
	return GuiLine(*bounds, text);
}

int mGuiPanel(Rectangle *bounds, const char * text)
{
	return GuiPanel(*bounds, text);
}

int mGuiTabBar(Rectangle *bounds, const char ** text, int count, int * active)
{
	return GuiTabBar(*bounds, text, count, active);
}

int mGuiScrollPanel(Rectangle *bounds, const char * text, Rectangle *content, Vector2 * scroll, Rectangle * view)
{
	return GuiScrollPanel(*bounds, text, *content, scroll, view);
}

int mGuiLabel(Rectangle *bounds, const char * text)
{
	return GuiLabel(*bounds, text);
}

int mGuiButton(Rectangle *bounds, const char * text)
{
	return GuiButton(*bounds, text);
}

int mGuiLabelButton(Rectangle *bounds, const char * text)
{
	return GuiLabelButton(*bounds, text);
}

int mGuiToggle(Rectangle *bounds, const char * text, bool * active)
{
	return GuiToggle(*bounds, text, active);
}

int mGuiToggleGroup(Rectangle *bounds, const char * text, int * active)
{
	return GuiToggleGroup(*bounds, text, active);
}

int mGuiToggleSlider(Rectangle *bounds, const char * text, int * active)
{
	return GuiToggleSlider(*bounds, text, active);
}

int mGuiCheckBox(Rectangle *bounds, const char * text, bool * checked)
{
	return GuiCheckBox(*bounds, text, checked);
}

int mGuiComboBox(Rectangle *bounds, const char * text, int * active)
{
	return GuiComboBox(*bounds, text, active);
}

int mGuiDropdownBox(Rectangle *bounds, const char * text, int * active, bool editMode)
{
	return GuiDropdownBox(*bounds, text, active, editMode);
}

int mGuiSpinner(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode)
{
	return GuiSpinner(*bounds, text, value, minValue, maxValue, editMode);
}

int mGuiValueBox(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode)
{
	return GuiValueBox(*bounds, text, value, minValue, maxValue, editMode);
}

int mGuiTextBox(Rectangle *bounds, char * text, int textSize, bool editMode)
{
	return GuiTextBox(*bounds, text, textSize, editMode);
}

int mGuiSlider(Rectangle *bounds, const char * textLeft, const char * textRight, float * value, float minValue, float maxValue)
{
	return GuiSlider(*bounds, textLeft, textRight, value, minValue, maxValue);
}

int mGuiSliderBar(Rectangle *bounds, const char * textLeft, const char * textRight, float * value, float minValue, float maxValue)
{
	return GuiSliderBar(*bounds, textLeft, textRight, value, minValue, maxValue);
}

int mGuiProgressBar(Rectangle *bounds, const char * textLeft, const char * textRight, float * value, float minValue, float maxValue)
{
	return GuiProgressBar(*bounds, textLeft, textRight, value, minValue, maxValue);
}

int mGuiStatusBar(Rectangle *bounds, const char * text)
{
	return GuiStatusBar(*bounds, text);
}

int mGuiDummyRec(Rectangle *bounds, const char * text)
{
	return GuiDummyRec(*bounds, text);
}

int mGuiGrid(Rectangle *bounds, const char * text, float spacing, int subdivs, Vector2 * mouseCell)
{
	return GuiGrid(*bounds, text, spacing, subdivs, mouseCell);
}

int mGuiListView(Rectangle *bounds, const char * text, int * scrollIndex, int * active)
{
	return GuiListView(*bounds, text, scrollIndex, active);
}

int mGuiListViewEx(Rectangle *bounds, const char ** text, int count, int * scrollIndex, int * active, int * focus)
{
	return GuiListViewEx(*bounds, text, count, scrollIndex, active, focus);
}

int mGuiMessageBox(Rectangle *bounds, const char * title, const char * message, const char * buttons)
{
	return GuiMessageBox(*bounds, title, message, buttons);
}

int mGuiTextInputBox(Rectangle *bounds, const char * title, const char * message, const char * buttons, char * text, int textMaxSize, bool * secretViewActive)
{
	return GuiTextInputBox(*bounds, title, message, buttons, text, textMaxSize, secretViewActive);
}

int mGuiColorPicker(Rectangle *bounds, const char * text, Color * color)
{
	return GuiColorPicker(*bounds, text, color);
}

int mGuiColorPanel(Rectangle *bounds, const char * text, Color * color)
{
	return GuiColorPanel(*bounds, text, color);
}

int mGuiColorBarAlpha(Rectangle *bounds, const char * text, float * alpha)
{
	return GuiColorBarAlpha(*bounds, text, alpha);
}

int mGuiColorBarHue(Rectangle *bounds, const char * text, float * value)
{
	return GuiColorBarHue(*bounds, text, value);
}

int mGuiColorPickerHSV(Rectangle *bounds, const char * text, Vector3 * colorHsv)
{
	return GuiColorPickerHSV(*bounds, text, colorHsv);
}

int mGuiColorPanelHSV(Rectangle *bounds, const char * text, Vector3 * colorHsv)
{
	return GuiColorPanelHSV(*bounds, text, colorHsv);
}

