#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "keymap_us_international.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _MOUSE,
  _SYMBOLS,
  _EXTRA,
  _SYSTEM,
  _GAMING,
  _GAMNUM,
};

#define COMBO_ONLY_FROM_LAYER _BASE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, MT(MOD_LALT, KC_Q),     KC_W,                    KC_E,               KC_R,                KC_T,           KC_Y,                 KC_U,              KC_I,                   KC_O,                 MT(MOD_LALT, KC_P),     KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LSFT, KC_A),     KC_S,                    KC_D,               KC_F,                KC_G,           KC_H,                 KC_J,              KC_K,                   KC_L,                 MT(MOD_LSFT, KC_QUOTE), KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LCTL, KC_Z),     MT(MOD_LGUI, KC_X),      KC_C,               KC_V,                KC_B,           KC_N,                 KC_M,              KC_COMMA,               MT(MOD_LGUI, KC_DOT), MT(MOD_LCTL, KC_SLASH), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          MO(_MOUSE),         LT(_EXTRA,KC_SPACE), MO(_SYMBOLS),   KC_NO,                KC_BSPACE,         MO(_EXTRA),             KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_MS_BTN2,              KC_MS_UP,           KC_MS_BTN1,          KC_MS_WH_UP,    KC_TRANSPARENT,       KC_TRANSPARENT,    KC_TRANSPARENT,         KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_MS_LEFT,              KC_MS_DOWN,         KC_MS_RIGHT,         KC_MS_WH_DOWN,  KC_TRANSPARENT,       KC_TRANSPARENT,    KC_TRANSPARENT,         KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_MS_BTN5,              KC_MS_BTN3,         KC_MS_WH_LEFT,       KC_MS_WH_RIGHT, KC_TRANSPARENT,       KC_TRANSPARENT,    KC_TRANSPARENT,         KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,                KC_TRANSPARENT,    KC_TRANSPARENT,         KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT
  ),

  [_SYMBOLS] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_EXLM,                KC_AT,                   KC_HASH,            KC_DLR,              KC_PERC,        KC_CIRC,              KC_7,               KC_8,                  KC_9,                 MT(MOD_LALT, KC_MINUS), KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LSFT, KC_GRAVE), KC_EQUAL,                KC_UNDS,            KC_COLN,             KC_LPRN,        KC_RPRN,              KC_4,               KC_5,                  KC_6,                 MT(MOD_LSFT, KC_0),     KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_Z),             MT(MOD_LGUI, KC_BSLASH), KC_ASTR,            KC_SCOLON,           KC_LBRACKET,    KC_RBRACKET,          KC_1,               KC_2,                  MT(MOD_LGUI, KC_3),   MT(MOD_LCTL, KC_DOT),   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_NO,                KC_TRANSPARENT,     KC_TRANSPARENT,        KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT
  ),

  [_EXTRA] = LAYOUT_planck_grid(
    KC_TRANSPARENT, LCTL(KC_1),             LCTL(KC_2),              LCTL(KC_3),         LCTL(KC_4),          MO(_SYSTEM),    KC_INSERT,            KC_HOME,            KC_END,                KC_PAGEUP,            KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LSHIFT,              KC_TAB,                  KC_ENTER,           KC_ESCAPE,           KC_TRANSPARENT, KC_LEFT,              KC_DOWN,            KC_UP,                 KC_RIGHT,             KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCTL,                LCTL(KC_Z),              KC_MPLY,            KC_MNXT,             KC_TRANSPARENT, KS_TAB,               KC_ENTER,           KC_ESC,                KC_PAGEDOWN,          KC_TRANSPARENT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      TO(_GAMING),    KC_NO,                KC_DELETE,          KC_TRANSPARENT,        KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT
  ),

  [_SYSTEM] = LAYOUT_planck_grid(
    KC_TRANSPARENT, RESET,                  KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,       KC_F1,              KC_F2,                 KC_F3,                KC_F10,                 KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,       KC_F4,              KC_F5,                 KC_F6,                KC_F11,                 KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,       KC_F7,              KC_F8,                 KC_F9,                KC_F12,                 KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_TRANSPARENT,      KC_TRANSPARENT, KC_TRANSPARENT,       KC_NO,              KC_TRANSPARENT,        KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT
  ),

  [_GAMING] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TAB,                 KC_Q,                    KC_W,               KC_E,                KC_R,           KC_T,                 KC_7,               KC_8,                  KC_9,                 KC_MINUS,               KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LSHIFT,              KC_A,                    KC_S,               KC_D,                KC_F,           KC_G,                 KC_4,               KC_5,                  KC_6,                 KC_0,                   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LALT,                KC_Z,                    KC_X,               KC_C,                KC_V,           KC_B,                 KC_1,               KC_2,                  KC_3,                 KC_DOT,                 KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,          KC_TRANSPARENT,     KC_LCTL,             KC_SPACE,       KC_NO,                TO(_BASE),          KC_TRANSPARENT,        KC_TRANSPARENT,       KC_TRANSPARENT,         KC_TRANSPARENT
  ),
};

extern rgb_config_t rgb_matrix_config;
void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_MOUSE] = { {0,0,0}, {0,0,0}, {230,218,204}, {230,218,204}, {230,218,204}, {97,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {230,218,204}, {230,218,204}, {230,218,204}, {97,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,218,204}, {230,218,204}, {97,218,204}, {97,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {47,199,215}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [_SYMBOLS] = { {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {105,255,255}, {105,255,255}, {105,255,255}, {169,120,255}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {123,59,210}, {123,59,210}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {105,255,255}, {105,255,255}, {105,255,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [_EXTRA] = { {0,0,0}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {0,218,204}, {146,224,255}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {123,59,210}, {0,0,0}, {243,222,234}, {123,59,210}, {97,119,198}, {97,119,198}, {97,119,198}, {97,119,198}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {123,59,210}, {123,59,210}, {243,222,234}, {243,222,234}, {0,0,0}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {230,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [_SYSTEM] = { {0,0,0}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [_GAMING] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {230,218,204}, {0,0,0}, {0,0,0}, {47,199,215}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case _MOUSE:
    case _SYMBOLS:
    case _EXTRA:
    case _SYSTEM:
    case _GAMING:
      set_layer_color(biton32(layer_state));
      break;
   default:
     if (rgb_matrix_get_flags() == LED_FLAG_NONE)
       rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

const key_override_t alt_shift_key_override = ko_make_basic(MOD_MASK_ALT, KC_V, LALT(KC_LEFT_SHIFT));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]) {
    &alt_shift_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM esc_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_L, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(enter_combo, KC_ENTER),
    COMBO(tab_combo, KC_TAB),
    COMBO(capslock_combo, KC_CAPSLOCK),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_E) {
      SEND_STRING("boris.churzin@gmail.com");
    }
    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("boris.churzin@fundbox.com");
    }
    SEQ_ONE_KEY(KC_O) {
      SEND_STRING(":+1:");
    }
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING(":confounded:");
    }
    SEQ_ONE_KEY(KC_J) {
      SEND_STRING(":joy:");
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(":thanks:");
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (get_highest_layer(state)) {
      case _GAMING:
        combo_disable();
        break;
      default:
        combo_enable();
        break;
    }
    return state;
};
