#include <pebble.h>
#include "standby.h"
#include "work.h"
#include "rest.h"


// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_28_bold;
static TextLayer *modoName;
static TextLayer *left_time;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorClear);
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // modoName
  modoName = text_layer_create(GRect(28, 22, 90, 30));
  text_layer_set_background_color(modoName, GColorClear);
  text_layer_set_text(modoName, "STAND BY");
  text_layer_set_text_alignment(modoName, GTextAlignmentCenter);
  text_layer_set_font(modoName, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)modoName);
  
  // left_time
  left_time = text_layer_create(GRect(22, 91, 100, 20));
  text_layer_set_background_color(left_time, GColorClear);
  text_layer_set_text(left_time, "00");
  text_layer_set_text_alignment(left_time, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)left_time);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(modoName);
  text_layer_destroy(left_time);
}
// END AUTO-GENERATED UI CODE

static void up_click_handler(ClickRecognizerRef recognizer, void *context)
{
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
	show_work();
	hide_standby();
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context)
{
}

static void click_config_provider(void *context)
{
	window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
	window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
	window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_standby(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_set_click_config_provider(s_window, click_config_provider);
  window_set_background_color(s_window, GColorBlue);
  window_stack_push(s_window, true);
}

void hide_standby(void) {
  window_stack_remove(s_window, true);
}
