#include "raygui.h"

// Enable gui controls (global state)
void mGuiEnable(void);

// Disable gui controls (global state)
void mGuiDisable(void);

// Lock gui controls (global state)
void mGuiLock(void);

// Unlock gui controls (global state)
void mGuiUnlock(void);

// Check if gui is locked (global state)
bool mGuiIsLocked(void);

// Set gui controls alpha (global state), alpha goes from 0.0f to 1.0f
void mGuiSetAlpha(float alpha);

// Set gui state (global state)
void mGuiSetState(int state);

// Get gui state (global state)
int mGuiGetState(void);

// Set gui custom font (global state)
void mGuiSetFont(Font *font);

// Get gui custom font (global state)
void mGuiGetFont(Font *out);

// Set one style property
void mGuiSetStyle(int control, int property, int value);

// Get one style property
int mGuiGetStyle(int control, int property);

// Load style file over global style variable (.rgs)
void mGuiLoadStyle(const char * fileName);

// Load style default over global style
void mGuiLoadStyleDefault(void);

// Enable gui tooltips (global state)
void mGuiEnableTooltip(void);

// Disable gui tooltips (global state)
void mGuiDisableTooltip(void);

// Set tooltip string
void mGuiSetTooltip(const char * tooltip);

// Get text with icon id prepended (if supported)
const char * mGuiIconText(int iconId, const char * text);

// Set default icon drawing size
void mGuiSetIconScale(int scale);

// Get raygui icons data pointer
unsigned int * mGuiGetIcons(void);

// Load raygui icons file (.rgi) into internal icons data
char ** mGuiLoadIcons(const char * fileName, bool loadIconsName);

// Window Box control, shows a window that can be closed
int mGuiWindowBox(Rectangle *bounds, const char * title);

// Group Box control with text name
int mGuiGroupBox(Rectangle *bounds, const char * text);

// Line separator control, could contain text
int mGuiLine(Rectangle *bounds, const char * text);

// Panel control, useful to group controls
int mGuiPanel(Rectangle *bounds, const char * text);

// Tab Bar control, returns TAB to be closed or -1
int mGuiTabBar(Rectangle *bounds, const char ** text, int count, int * active);

// Scroll Panel control
int mGuiScrollPanel(Rectangle *bounds, const char * text, Rectangle *content, Vector2 * scroll, Rectangle * view);

// Label control, shows text
int mGuiLabel(Rectangle *bounds, const char * text);

// Button control, returns true when clicked
int mGuiButton(Rectangle *bounds, const char * text);

// Label button control, show true when clicked
int mGuiLabelButton(Rectangle *bounds, const char * text);

// Toggle Button control, returns true when active
int mGuiToggle(Rectangle *bounds, const char * text, bool * active);

// Toggle Group control, returns active toggle index
int mGuiToggleGroup(Rectangle *bounds, const char * text, int * active);

// Check Box control, returns true when active
int mGuiCheckBox(Rectangle *bounds, const char * text, bool * checked);

// Combo Box control, returns selected item index
int mGuiComboBox(Rectangle *bounds, const char * text, int * active);

// Dropdown Box control, returns selected item
int mGuiDropdownBox(Rectangle *bounds, const char * text, int * active, bool editMode);

// Spinner control, returns selected value
int mGuiSpinner(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode);

// Value Box control, updates input text with numbers
int mGuiValueBox(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode);

// Text Box control, updates input text
int mGuiTextBox(Rectangle *bounds, char * text, int textSize, bool editMode);

// Slider control, returns selected value
int mGuiSlider(Rectangle *bounds, const char * textLeft, const char * textRight, float * value, float minValue, float maxValue);

// Slider Bar control, returns selected value
int mGuiSliderBar(Rectangle *bounds, const char * textLeft, const char * textRight, float * value, float minValue, float maxValue);

// Progress Bar control, shows current progress value
int mGuiProgressBar(Rectangle *bounds, const char * textLeft, const char * textRight, float * value, float minValue, float maxValue);

// Status Bar control, shows info text
int mGuiStatusBar(Rectangle *bounds, const char * text);

// Dummy control for placeholders
int mGuiDummyRec(Rectangle *bounds, const char * text);

// Grid control, returns mouse cell position
int mGuiGrid(Rectangle *bounds, const char * text, float spacing, int subdivs, Vector2 * mouseCell);

// List View control, returns selected list item index
int mGuiListView(Rectangle *bounds, const char * text, int * scrollIndex, int * active);

// List View with extended parameters
int mGuiListViewEx(Rectangle *bounds, const char ** text, int count, int * scrollIndex, int * active, int * focus);

// Message Box control, displays a message
int mGuiMessageBox(Rectangle *bounds, const char * title, const char * message, const char * buttons);

// Text Input Box control, ask for text, supports secret
int mGuiTextInputBox(Rectangle *bounds, const char * title, const char * message, const char * buttons, char * text, int textMaxSize, bool * secretViewActive);

// Color Picker control (multiple color controls)
int mGuiColorPicker(Rectangle *bounds, const char * text, Color * color);

// Color Panel control
int mGuiColorPanel(Rectangle *bounds, const char * text, Color * color);

// Color Bar Alpha control
int mGuiColorBarAlpha(Rectangle *bounds, const char * text, float * alpha);

// Color Bar Hue control
int mGuiColorBarHue(Rectangle *bounds, const char * text, float * value);

// Color Picker control that avoids conversion to RGB on each call (multiple color controls)
int mGuiColorPickerHSV(Rectangle *bounds, const char * text, Vector3 * colorHsv);

// Color Panel control that returns HSV color value, used by GuiColorPickerHSV()
int mGuiColorPanelHSV(Rectangle *bounds, const char * text, Vector3 * colorHsv);

