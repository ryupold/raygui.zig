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

void mGuiFade(float alpha)
{
	GuiFade(alpha);
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

bool mGuiWindowBox(Rectangle *bounds, const char * title)
{
	return GuiWindowBox(*bounds, title);
}

void mGuiGroupBox(Rectangle *bounds, const char * text)
{
	GuiGroupBox(*bounds, text);
}

void mGuiLine(Rectangle *bounds, const char * text)
{
	GuiLine(*bounds, text);
}

void mGuiPanel(Rectangle *bounds, const char * text)
{
	GuiPanel(*bounds, text);
}

int mGuiTabBar(Rectangle *bounds, const char ** text, int count, int * active)
{
	return GuiTabBar(*bounds, text, count, active);
}

void mGuiScrollPanel(Rectangle *out, Rectangle *bounds, const char * text, Rectangle *content, Vector2 * scroll)
{
	*out = GuiScrollPanel(*bounds, text, *content, scroll);
}

void mGuiLabel(Rectangle *bounds, const char * text)
{
	GuiLabel(*bounds, text);
}

bool mGuiButton(Rectangle *bounds, const char * text)
{
	return GuiButton(*bounds, text);
}

bool mGuiLabelButton(Rectangle *bounds, const char * text)
{
	return GuiLabelButton(*bounds, text);
}

bool mGuiToggle(Rectangle *bounds, const char * text, bool active)
{
	return GuiToggle(*bounds, text, active);
}

int mGuiToggleGroup(Rectangle *bounds, const char * text, int active)
{
	return GuiToggleGroup(*bounds, text, active);
}

bool mGuiCheckBox(Rectangle *bounds, const char * text, bool checked)
{
	return GuiCheckBox(*bounds, text, checked);
}

int mGuiComboBox(Rectangle *bounds, const char * text, int active)
{
	return GuiComboBox(*bounds, text, active);
}

bool mGuiDropdownBox(Rectangle *bounds, const char * text, int * active, bool editMode)
{
	return GuiDropdownBox(*bounds, text, active, editMode);
}

bool mGuiSpinner(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode)
{
	return GuiSpinner(*bounds, text, value, minValue, maxValue, editMode);
}

bool mGuiValueBox(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode)
{
	return GuiValueBox(*bounds, text, value, minValue, maxValue, editMode);
}

bool mGuiTextBox(Rectangle *bounds, char * text, int textSize, bool editMode)
{
	return GuiTextBox(*bounds, text, textSize, editMode);
}

bool mGuiTextBoxMulti(Rectangle *bounds, char * text, int textSize, bool editMode)
{
	return GuiTextBoxMulti(*bounds, text, textSize, editMode);
}

float mGuiSlider(Rectangle *bounds, const char * textLeft, const char * textRight, float value, float minValue, float maxValue)
{
	return GuiSlider(*bounds, textLeft, textRight, value, minValue, maxValue);
}

float mGuiSliderBar(Rectangle *bounds, const char * textLeft, const char * textRight, float value, float minValue, float maxValue)
{
	return GuiSliderBar(*bounds, textLeft, textRight, value, minValue, maxValue);
}

float mGuiProgressBar(Rectangle *bounds, const char * textLeft, const char * textRight, float value, float minValue, float maxValue)
{
	return GuiProgressBar(*bounds, textLeft, textRight, value, minValue, maxValue);
}

void mGuiStatusBar(Rectangle *bounds, const char * text)
{
	GuiStatusBar(*bounds, text);
}

void mGuiDummyRec(Rectangle *bounds, const char * text)
{
	GuiDummyRec(*bounds, text);
}

void mGuiGrid(Vector2 *out, Rectangle *bounds, const char * text, float spacing, int subdivs)
{
	*out = GuiGrid(*bounds, text, spacing, subdivs);
}

int mGuiListView(Rectangle *bounds, const char * text, int * scrollIndex, int active)
{
	return GuiListView(*bounds, text, scrollIndex, active);
}

int mGuiListViewEx(Rectangle *bounds, const char ** text, int count, int * focus, int * scrollIndex, int active)
{
	return GuiListViewEx(*bounds, text, count, focus, scrollIndex, active);
}

int mGuiMessageBox(Rectangle *bounds, const char * title, const char * message, const char * buttons)
{
	return GuiMessageBox(*bounds, title, message, buttons);
}

int mGuiTextInputBox(Rectangle *bounds, const char * title, const char * message, const char * buttons, char * text, int textMaxSize, int * secretViewActive)
{
	return GuiTextInputBox(*bounds, title, message, buttons, text, textMaxSize, secretViewActive);
}

void mGuiColorPicker(Color *out, Rectangle *bounds, const char * text, Color *color)
{
	*out = GuiColorPicker(*bounds, text, *color);
}

void mGuiColorPanel(Color *out, Rectangle *bounds, const char * text, Color *color)
{
	*out = GuiColorPanel(*bounds, text, *color);
}

float mGuiColorBarAlpha(Rectangle *bounds, const char * text, float alpha)
{
	return GuiColorBarAlpha(*bounds, text, alpha);
}

float mGuiColorBarHue(Rectangle *bounds, const char * text, float value)
{
	return GuiColorBarHue(*bounds, text, value);
}

void mGuiLoadStyle(const char * fileName)
{
	GuiLoadStyle(fileName);
}

void mGuiLoadStyleDefault(void)
{
	GuiLoadStyleDefault();
}

const char * mGuiIconText(int iconId, const char * text)
{
	return GuiIconText(iconId, text);
}

unsigned int * mGuiGetIcons(void)
{
	return GuiGetIcons();
}

char ** mGuiLoadIcons(const char * fileName, bool loadIconsName)
{
	return GuiLoadIcons(fileName, loadIconsName);
}

