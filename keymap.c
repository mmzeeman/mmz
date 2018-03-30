#include QMK_KEYBOARD_H
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"
#include "keymap_nordic.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};


enum {
  TD_LPRN,
  TD_RPRN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = KEYMAP(KC_EQUAL,       KC_1,     KC_2,    KC_3,   KC_4, KC_5, ALL_T(KC_NO),
                  KC_TAB,         KC_Q,     KC_W,    KC_E,   KC_R, KC_T, TG(1),
                  KC_LCTL,        KC_A,     KC_S,    KC_D,   KC_F, KC_G,
                  KC_LSHIFT,      KC_Z,     KC_X,    KC_C,   KC_V, KC_B, TD(TD_LPRN),
                  LT(1,KC_GRAVE), KC_QUOTE, KC_LCTL, KC_LALT,KC_LGUI,
                                                                    KC_TRNS, KC_TRNS,
                                                                             KC_TRNS,
                                                        KC_TAB, KC_BSPACE, KC_ESCAPE,

                  MEH_T(KC_NO), KC_6,    KC_7,     KC_8,        KC_9,        KC_0,            KC_MINUS,
                  TG(1),        KC_Y,    KC_U,     KC_I,        KC_O,        KC_P,            KC_BSLASH,
                                KC_H,    KC_J,     KC_K,        KC_L,        LT(2,KC_SCOLON), KC_QUOTE,
                  TD(TD_RPRN),  KC_N,    KC_M,     KC_COMMA,    KC_DOT,      KC_SLASH,        KC_RSHIFT,
                                         KC_LGUI,  KC_RALT,     KC_LBRACKET, KC_RBRACKET,     MO(1),
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_LEAD, KC_ENTER, KC_SPACE),

  [SYMB] = KEYMAP(KC_ESCAPE, KC_F1,   KC_F2,   KC_F3,       KC_F4,       KC_F5,    KC_TRNS,
                  VRSN,      KC_EXLM, KC_AT,   KC_LCBR,     KC_RCBR,     KC_PIPE,  KC_TRNS,
                  KC_TRNS,   KC_HASH, KC_DLR,  KC_LPRN,     KC_RPRN,     KC_GRAVE,
                  KC_TRNS,   KC_PERC, KC_CIRC, KC_LBRACKET, KC_RBRACKET, KC_TILD,  KC_TRNS,
                  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
                                                                          RGB_MOD, KC_TRNS,
                                                                                   KC_TRNS,
                                                                 RGB_VAD, RGB_VAI, KC_TRNS,

                  KC_TRNS, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
                  KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS,  KC_TRNS, KC_TRNS, KC_F12,
                           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                  RGB_TOG, RGB_SLD,
                  KC_TRNS,
                  KC_TRNS, RGB_HUD, RGB_HUI),

  [MDIA] = KEYMAP(KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1, KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS, KC_TRNS,
                                                                                 KC_TRNS,
                                                               KC_TRNS, KC_TRNS, KC_TRNS,

                  KC_TRNS, KC_TRNS,    KC_TRNS,         KC_TRNS,             KC_TRNS,             KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS,    KC_TRNS,         KC_TRNS,             KC_TRNS,             KC_TRNS, KC_TRNS,
                           KC_MS_LEFT, KC_MS_DOWN,      KC_MS_UP,            KC_MS_RIGHT,         KC_TRNS, KC_MEDIA_PLAY_PAUSE,
                  KC_TRNS, KC_TRNS,    KC_TRNS,         KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRNS, KC_TRNS,
                                       KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN,   KC_AUDIO_MUTE,       KC_TRNS, KC_TRNS,
                  KC_TRNS, KC_TRNS,
                  KC_TRNS,
                  KC_TRNS, KC_TRNS, KC_WWW_BACK),

};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};


static void
td_lbrackets_finished (qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    register_code16(KC_LPRN);
  } else if(state->count == 2) {
    register_code16(KC_LBRC);
  } else {
    register_code16(KC_LCBR);
  }
}

static void
td_rbrackets_finished (qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    register_code16(KC_RPRN);
  } else if(state->count == 2) {
    register_code16(KC_RBRC);
  } else {
    register_code16(KC_RCBR);
  }
}

static void
td_lbrackets_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    unregister_code16(KC_LPRN);
  } else if(state->count == 2) {
    unregister_code16(KC_LBRC);
  } else {
    unregister_code16(KC_LCBR);
  }
}

static void
td_rbrackets_reset (qk_tap_dance_state_t *state, void *user_data) {
  if(state->count == 1) {
    unregister_code16(KC_RPRN);
  } else if(state->count == 2) {
    unregister_code16(KC_RBRC);
  } else {
    unregister_code16(KC_RCBR);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  /*
  [TD_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
  [TD_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN)
  */
  [TD_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lbrackets_finished, td_lbrackets_reset),
  [TD_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_rbrackets_finished, td_rbrackets_reset),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};


// Runs constantly in the background, in a loop.
LEADER_EXTERNS(); // Needed for leader key processing
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    /* Git */
    SEQ_ONE_KEY(KC_G) { SEND_STRING("git"); }
    SEQ_TWO_KEYS(KC_G, KC_S) { SEND_STRING("git status"); }
    SEQ_TWO_KEYS(KC_G, KC_D) { SEND_STRING("git diff"); }

    /* Zotonic and erlang */
    SEQ_TWO_KEYS(KC_Z, KC_M) { SEND_STRING("z:m()."); }
    SEQ_TWO_KEYS(KC_Z, KC_C) { SEND_STRING("Context"); }
    SEQ_TWO_KEYS(KC_R, KC_T) { SEND_STRING("length(recon:tcp())."); }
  }
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
