#include QMK_KEYBOARD_H

enum layer {
    LAYER_DEFAULT,
    LAYER_POE,
    LAYER_FUNCTION,
    LAYER_EMOJI,
    LAYER_UTIL,
    LAYER_POE_UTIL,
};

enum macro_keys {
    HIDEOUT = SAFE_RANGE,
    FLASK1,
    FLASK2,
    FLASK3,
    FLASK4
};

enum emoji_map {
  JOY, // 😂
  SWEATSMILE, // 😅
  XD, // 😆
  UNAMUSED, // 😒
  HEARTEYES, // 😍
  OK, // 👌
  SMIRK, // 😏
  PRAY, // 🙏
  STRONK, // 💪
  KISS, // 😘
  ANGRY, // 😡
  TOUNGUE, // 😜
  SCARED, // 😱
  FLUSHED, // 😳
  MOAN, // 😩
  FIST, // ✊
  UP, //👆
  DOWN, //👇
  LEFT, //👈
  RIGHT, //👉
  THUMBSUP, //👍
  THUMBSDOWN, //👎
  CLAP, // 👏
  FIRE, // 🔥
  AE, // æ
  AA, // å
  OE, // ø
  SHIFTAE, // Æ
  SHIFTAA, // Å
  SHIFTOE // Ø
};

const uint32_t PROGMEM unicode_map[] = {
  [JOY] = 0x1F602,
  [SWEATSMILE] = 0x1F605,
  [XD] = 0x1F606,
  [UNAMUSED] = 0x1F612,
  [HEARTEYES] = 0x1f60d,
  [OK]   = 0x1F44C,
  [SMIRK] = 0x1F60F,
  [PRAY] = 0x1F64F,
  [STRONK] = 0x1F4AA,
  [KISS] = 0x1F618,
  [ANGRY] = 0x1F621,
  [TOUNGUE] = 0x1F61C,
  [SCARED] = 0x1F631,
  [FLUSHED] = 0x1F633,
  [MOAN] = 0x1F629,
  [FIST] = 0x270A,
  [UP] = 0x1F446,
  [DOWN] = 0x1F447,
  [LEFT] = 0x1F448,
  [RIGHT] = 0x1F449,
  [THUMBSUP] = 0x1F44D,
  [THUMBSDOWN] = 0x1F44E,
  [CLAP] = 0x1F44F,
  [FIRE] = 0x1F525,
  [AE] = 0x00E6,
  [OE] = 0x00F8,
  [AA] = 0x00E5,
  [SHIFTAE] = 0x00C6,
  [SHIFTOE] = 0x00D8,
  [SHIFTAA] = 0x00C5,
};
#define LY_FN MO(LAYER_FUNCTION)
#define LY_UTIL MO(LAYER_UTIL)
#define LY_POE_UTIL MO(LAYER_POE_UTIL)
#define LY_EMOJI MO(LAYER_EMOJI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_DEFAULT] = LAYOUT_65(
        KC_ESC,         KC_1,     KC_2,     KC_3,     KC_4,            KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSPC,   KC_DEL,
        KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,            KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_GRV,
        TG(LAYER_POE),  KC_A,     KC_S,     KC_D,     KC_F,            KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_HOME,
        KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,            KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,        KC_LALT,  KC_LGUI,  KC_SPC,   LY_UTIL,  KC_RSFT, KC_RSFT,    LY_EMOJI,  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [LAYER_POE] = LAYOUT_65(
        KC_TRNS,   KC_TRNS,      FLASK2,       FLASK3,          FLASK4,          KC_KP_5,        KC_KP_6,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
        KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,
        KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,         LY_POE_UTIL,     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [LAYER_FUNCTION] = LAYOUT_65(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   RGB_HUI,
        KC_TRNS,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_U,  KC_TRNS,
        KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_L,  KC_WH_D,  KC_WH_R
    ),

    [LAYER_POE_UTIL] = LAYOUT_65(
        KC_TRNS,  FLASK1,    FLASK2,    FLASK3,     FLASK4,     KC_F5,    KC_BSPC,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   X(THUMBSDOWN),   X(THUMBSDOWN),   X(FIST),
        KC_TRNS,  KC_MPLY,  KC_VOLU,    KC_MSTP,    KC_TRNS,    KC_I,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         XP(AA, SHIFTAA),  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_MPRV,  KC_VOLD,    KC_MNXT,    KC_TRNS,    KC_P,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XP(AE, SHIFTAE), XP(OE, SHIFTOE),  X(THUMBSUP),  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_MUTE,    KC_TRNS,    KC_TRNS,    HIDEOUT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,          X(UP),  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  X(LEFT),         X(DOWN),          X(RIGHT)
    ),

    [LAYER_UTIL] = LAYOUT_65(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_BSPC,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   X(THUMBSDOWN),   X(THUMBSDOWN),   X(FIST),
        KC_TRNS,  KC_MPLY,  KC_VOLU,  KC_MSTP,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         XP(AA, SHIFTAA),  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_MPRV,  KC_VOLD,  KC_MNXT,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  XP(AE, SHIFTAE), XP(OE, SHIFTOE),  X(THUMBSUP),  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,          X(UP),  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  X(LEFT),         X(DOWN),          X(RIGHT)
    ),

    [LAYER_EMOJI] = LAYOUT_65(
        UNICODE_MODE_WINC,   KC_KP_1,     KC_KP_2,      KC_KP_3,        KC_KP_4,        KC_KP_5,            KC_KP_6,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        UNICODE_MODE_OSX,    X(ANGRY),    X(SMIRK),     X(SWEATSMILE),  X(JOY),         X(HEARTEYES),       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,             X(TOUNGUE),  X(SCARED),    X(FLUSHED),     X(MOAN),        X(STRONK),          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,             KC_TRNS,     X(XD),        X(KISS),        X(THUMBSUP),    X(THUMBSDOWN),      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  X(UP),    KC_TRNS,
        KC_TRNS,             KC_TRNS,     KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    X(LEFT),  X(DOWN),  X(RIGHT)
    )

};

uint32_t layer_state_set_user(uint32_t state)
{
  switch (biton32(state))
  {
    case LAYER_EMOJI:
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5);
      break;
    case LAYER_POE:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(HSV_RED);
      break;
    case LAYER_POE_UTIL:
      rgblight_mode(RGBLIGHT_MODE_SNAKE+3);
      rgblight_sethsv(HSV_RED);
    //   rgblight_sethsv(HSV_TEAL);
      break;
    case LAYER_UTIL:
      rgblight_mode(RGBLIGHT_MODE_SNAKE+3);
      rgblight_sethsv(12, 255, 255);
    //   rgblight_sethsv(HSV_TEAL);
      break;
    default:
    case LAYER_DEFAULT:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(12, 255, 255);
    //   rgblight_sethsv(HSV_TEAL);
      break;
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HIDEOUT:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                SEND_STRING("/hideout");
                tap_code(KC_ENT);
            }
            break;
        case FLASK1:
            if (record->event.pressed) {
                tap_code(KC_1);
                tap_code(KC_2);
                tap_code(KC_3);
                tap_code(KC_4);
                tap_code(KC_5);
            }
            break;
        case FLASK2:
            if (record->event.pressed) {
                tap_code(KC_2);
                tap_code(KC_3);
                tap_code(KC_4);
                tap_code(KC_5);
            }
            break;
        case FLASK3:
            if (record->event.pressed) {
                tap_code(KC_3);
                tap_code(KC_4);
                tap_code(KC_5);
            }
            break;
        case FLASK4:
            if (record->event.pressed) {
                tap_code(KC_4);
                tap_code(KC_5);
            }
            break;
    }
    return true;
}
