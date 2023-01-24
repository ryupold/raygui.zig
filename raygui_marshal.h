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
void mGuiFade(float alpha);

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

// Window Box control, shows a window that can be closed
bool mGuiWindowBox(Rectangle *bounds, const char * title);

// Group Box control with text name
void mGuiGroupBox(Rectangle *bounds, const char * text);

// Line separator control, could contain text
void mGuiLine(Rectangle *bounds, const char * text);

// Panel control, useful to group controls
void mGuiPanel(Rectangle *bounds, const char * text);

// Tab Bar control, returns TAB to be closed or -1
int mGuiTabBar(Rectangle *bounds, const char ** text, int count, int * active);

// Scroll Panel control
void mGuiScrollPanel(Rectangle *out, Rectangle *bounds, const char * text, Rectangle *content, Vector2 * scroll);

// Label control, shows text
void mGuiLabel(Rectangle *bounds, const char * text);

// Button control, returns true when clicked
bool mGuiButton(Rectangle *bounds, const char * text);

// Label button control, show true when clicked
bool mGuiLabelButton(Rectangle *bounds, const char * text);

// Toggle Button control, returns true when active
bool mGuiToggle(Rectangle *bounds, const char * text, bool active);

// Toggle Group control, returns active toggle index
int mGuiToggleGroup(Rectangle *bounds, const char * text, int active);

// Check Box control, returns true when active
bool mGuiCheckBox(Rectangle *bounds, const char * text, bool checked);

// Combo Box control, returns selected item index
int mGuiComboBox(Rectangle *bounds, const char * text, int active);

// Dropdown Box control, returns selected item
bool mGuiDropdownBox(Rectangle *bounds, const char * text, int * active, bool editMode);

// Spinner control, returns selected value
bool mGuiSpinner(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode);

// Value Box control, updates input text with numbers
bool mGuiValueBox(Rectangle *bounds, const char * text, int * value, int minValue, int maxValue, bool editMode);

// Text Box control, updates input text
bool mGuiTextBox(Rectangle *bounds, char * text, int textSize, bool editMode);

// Text Box control with multiple lines
bool mGuiTextBoxMulti(Rectangle *bounds, char * text, int textSize, bool editMode);

// Slider control, returns selected value
float mGuiSlider(Rectangle *bounds, const char * textLeft, const char * textRight, float value, float minValue, float maxValue);

// Slider Bar control, returns selected value
float mGuiSliderBar(Rectangle *bounds, const char * textLeft, const char * textRight, float value, float minValue, float maxValue);

// Progress Bar control, shows current progress value
float mGuiProgressBar(Rectangle *bounds, const char * textLeft, const char * textRight, float value, float minValue, float maxValue);

// Status Bar control, shows info text
void mGuiStatusBar(Rectangle *bounds, const char * text);

// Dummy control for placeholders
void mGuiDummyRec(Rectangle *bounds, const char * text);

// Grid control, returns mouse cell position
void mGuiGrid(Vector2 *out, Rectangle *bounds, const char * text, float spacing, int subdivs);

// List View control, returns selected list item index
int mGuiListView(Rectangle *bounds, const char * text, int * scrollIndex, int active);

// List View with extended parameters
int mGuiListViewEx(Rectangle *bounds, const char ** text, int count, int * focus, int * scrollIndex, int active);

// Message Box control, displays a message
int mGuiMessageBox(Rectangle *bounds, const char * title, const char * message, const char * buttons);

// Text Input Box control, ask for text, supports secret
int mGuiTextInputBox(Rectangle *bounds, const char * title, const char * message, const char * buttons, char * text, int textMaxSize, int * secretViewActive);

// Color Picker control (multiple color controls)
void mGuiColorPicker(Color *out, Rectangle *bounds, const char * text, Color *color);

// Color Panel control
void mGuiColorPanel(Color *out, Rectangle *bounds, const char * text, Color *color);

// Color Bar Alpha control
float mGuiColorBarAlpha(Rectangle *bounds, const char * text, float alpha);

// Color Bar Hue control
float mGuiColorBarHue(Rectangle *bounds, const char * text, float value);

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

// Get raygui icons data pointer
unsigned int * mGuiGetIcons(void);

// Load raygui icons file (.rgi) into internal icons data
char ** mGuiLoadIcons(const char * fileName, bool loadIconsName);

// Set icon drawing size
void mGuiSetIconScale(int scale);

