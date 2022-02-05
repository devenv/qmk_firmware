#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "keymap_us_international.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum tap_dance_codes {
  DANCE_QUESTION,
  DANCE_STAR,
  DANCE_MEDIA,
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
    KC_TRANSPARENT, KC_Q,               KC_W,               KC_E,               KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,                   KC_O,                 KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LSFT, KC_A), KC_S,               KC_D,               KC_F,           KC_G,           KC_H,           KC_J,           KC_K,                   KC_L,                 MT(MOD_LSFT, KC_QUOTE),KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LCTL, KC_Z), MT(MOD_LGUI, KC_X), MT(MOD_LALT, KC_C), KC_V,           KC_B,           KC_N,           KC_M,           MT(MOD_LALT, KC_COMMA), MT(MOD_LGUI, KC_DOT), MT(MOD_LCTL, KC_SLASH),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,     MO(_MOUSE),              LT(_EXTRA,KC_SPACE), MO(_SYMBOLS),          KC_NO,          KC_BSPACE,      KC_ENTER,               KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_MOUSE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_UP,       KC_MS_BTN1,     KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN5,     KC_MS_BTN3,     KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,          KC_NO,          MO(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SYMBOLS] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,    KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_TRANSPARENT,
    KC_TRANSPARENT, TD(DANCE_QUESTION),    KC_UNDS,        KC_MINUS,       KC_COLN,        KC_LPRN,        KC_RPRN,        KC_4,           KC_5,           KC_6,           MT(MOD_LSFT, KC_0),KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LCTL, KC_GRAVE),MT(MOD_LGUI, KC_BSLASH),TD(DANCE_STAR),    KC_SCOLON,      KC_LBRACKET,    KC_RBRACKET,    KC_1,           MT(MOD_LALT, KC_2),MT(MOD_LGUI, KC_3),MT(MOD_LCTL, LSFT(KC_AMPR)),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_EXTRA] = LAYOUT_planck_grid(
    KC_TRANSPARENT, LCTL(KC_2),     LCTL(KC_2),     LCTL(KC_3),     LCTL(KC_4),     MO(_SYSTEM),          KC_INSERT,      KC_HOME,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_LEAD,      KC_AUDIO_VOL_UP, KC_TRANSPARENT,     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MT(MOD_LCTL, KC_AUDIO_MUTE),KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_VOL_DOWN,TD(DANCE_MEDIA),    KC_TRANSPARENT, KC_PGDOWN,      MT(MOD_LALT, KC_PGUP),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(_GAMING),          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_SYSTEM] = LAYOUT_planck_grid(
    KC_TRANSPARENT, RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GAMING] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R, KC_T, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LALT,        KC_A,           KC_S,           KC_D,           KC_F, KC_G, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V, KC_B, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(_GAMNUM),          KC_LCTRL,       KC_SPACE,       KC_NO,          TO(_BASE),          KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_GAMNUM] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_KP_MINUS,    KC_7,           KC_8,           KC_9,           KC_LEAD,        KC_TRANSPARENT, KC_HOME, KC_END, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_PLUS,     KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_UP, KC_LEFT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
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
    [_GAMNUM] = { {0,0,0}, {128,161,253}, {168,218,204}, {168,218,204}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {128,161,253}, {168,218,204}, {168,218,204}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
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
    case _GAMNUM:
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

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[5];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_question(qk_tap_dance_state_t *state, void *user_data);
void dance_question_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_question_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_question(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUES);
        tap_code16(KC_QUES);
        tap_code16(KC_QUES);
    }
    if(state->count > 3) {
        tap_code16(KC_QUES);
    }
}

void dance_question_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_QUES); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_QUES); register_code16(KC_QUES); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUES); register_code16(KC_QUES);
    }
}

void dance_question_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_QUES); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_QUES); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUES); break;
    }
    dance_state[1].step = 0;
}
void on_dance_star(qk_tap_dance_state_t *state, void *user_data);
void dance_star_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_star_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_star(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ASTR);
        tap_code16(KC_ASTR);
        tap_code16(KC_ASTR);
    }
    if(state->count > 3) {
        tap_code16(KC_ASTR);
    }
}

void dance_star_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_ASTR); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_ASTR); register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ASTR); register_code16(KC_ASTR);
    }
}

void dance_star_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ASTR); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ASTR); break;
    }
    dance_state[2].step = 0;
}
void on_dance_media(qk_tap_dance_state_t *state, void *user_data);
void dance_media_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_media_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_media(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_media_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_media_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[4].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_QUESTION] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_question, dance_question_finished, dance_question_reset),
        [DANCE_STAR] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_star, dance_star_finished, dance_star_reset),
        [DANCE_MEDIA] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_media, dance_media_finished, dance_media_reset),
};

const key_override_t alt_tab_key_override = ko_make_basic(MOD_MASK_ALT, KC_Q, LALT(KC_TAB));
const key_override_t ctrl_tab_key_override = ko_make_basic(MOD_MASK_CTRL, KC_Q, LCTL(KC_TAB));
const key_override_t alt_shift_key_override = ko_make_basic(MOD_MASK_ALT, KC_V, LALT(KC_LEFT_SHIFT));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]) {
    &alt_tab_key_override,
    &ctrl_tab_key_override,
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
    SEQ_ONE_KEY(KC_5) {
      SEND_STRING(SS_TAP(X_ENTER) "..." SS_TAP(X_ENTER));
    }
    SEQ_ONE_KEY(KC_4) {
      SEND_STRING(SS_TAP(X_ENTER) "lol" SS_TAP(X_ENTER));
    }
    SEQ_ONE_KEY(KC_9) {
      SEND_STRING(SS_TAP(X_ENTER) "gg" SS_TAP(X_ENTER));
    }
    SEQ_ONE_KEY(KC_2) {
      SEND_STRING(SS_TAP(X_ENTER) "chill it's just qp" SS_TAP(X_ENTER));
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
