#include QMK_KEYBOARD_H

enum macro_keys {
    HIDEOUT = SAFE_RANGE,
    FLASK1,
    FLASK2,
    FLASK3,
    FLASK4
};

enum layer {
    LAYER_DEFAULT,
    LAYER_POE,
    LAYER_POE_UTIL,
    LAYER_ARROWS,
    LAYER_ARROWS_ALT,
    LAYER_EMOJI,
    LAYER_UTIL,
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
#define LY_UTIL MO(LAYER_UTIL)
#define LY_EMOJI MO(LAYER_EMOJI)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * │Shift│ app │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │   shift   │ fn  │
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |   Space    |  FN  |     Space     |  FN  | RAlt |  menu |  ctrl  |
   * `-----------------------------------------------------------------------------------------'
*/
    [LAYER_DEFAULT] = LAYOUT_60_ansi_split_space_rshift_lshift(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        TG(LAYER_POE), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,  MO(LAYER_ARROWS),   KC_Z,   KC_X,  KC_C,   KC_V,   KC_B,  KC_N,   KC_M,   KC_COMM,   KC_DOT,  KC_SLSH, KC_RSFT,   MO(LAYER_ARROWS),
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(LAYER_UTIL), KC_SPC, MO(LAYER_EMOJI),  MO(LAYER_ARROWS_ALT), KC_RALT, KC_RCTL
    ),

    [LAYER_POE] = LAYOUT_60_ansi_split_space_rshift_lshift(
        _______,  _______,   _______,   FLASK3,   FLASK4,   _______,   _______,   _______,   _______,   _______,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, MO(LAYER_POE_UTIL), _______, _______, _______,          _______,
    ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   RESET   |
   * |-----------------------------------------------------------------------------------------+
   * |        |RBB T|RGB M| Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         | BL T| BL M| BL+ | BL- |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |     |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

    [LAYER_UTIL] = LAYOUT_60_ansi_split_space_rshift_lshift(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,
        _______, KC_MPLY, KC_VOLU, KC_MSTP, _______, _______, _______, _______, _______, _______, _______, XP(AA, SHIFTAA), _______, KC_GRAVE,
        KC_CAPS, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______, _______, _______, _______, _______, XP(AE, SHIFTAE), XP(OE, SHIFTOE),  X(THUMBSUP),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_UP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [LAYER_POE_UTIL] = LAYOUT_60_ansi_split_space_rshift_lshift(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,
        _______, KC_MPLY, KC_VOLU, KC_MSTP, _______, KC_I,    _______, _______, _______, _______, _______, XP(AA, SHIFTAA), _______, KC_GRAVE,
        KC_CAPS, KC_MPRV, KC_VOLD, KC_MNXT, _______, KC_P,    HIDEOUT, _______, _______, _______, XP(AE, SHIFTAE), XP(OE, SHIFTOE),  X(THUMBSUP),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),


    [LAYER_ARROWS] = LAYOUT_60_ansi_split_space_rshift_lshift(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,
        _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRAVE,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_UP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [LAYER_ARROWS_ALT] = LAYOUT_60_ansi_split_space_rshift_lshift(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,
        _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRAVE,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [LAYER_EMOJI] = LAYOUT_60_ansi_split_space_rshift_lshift(
        UNICODE_MODE_WINC,   KC_KP_1,     KC_KP_2,      KC_KP_3,        KC_KP_4,        KC_KP_5,            KC_KP_6,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,  _______,  _______,  RESET,
        UNICODE_MODE_OSX,    X(ANGRY),    X(SMIRK),     X(SWEATSMILE),  X(JOY),         X(HEARTEYES),       _______,    _______,    _______,    _______,    _______,  _______,  _______,  _______,
        _______,             X(TOUNGUE),  X(SCARED),    X(FLUSHED),     X(MOAN),        X(STRONK),          _______,    _______,    _______,    _______,    _______,  _______,  _______,
        _______,             _______,     X(XD),        X(KISS),        X(THUMBSUP),    X(THUMBSDOWN),      _______,    _______,    _______,    _______,    _______,  _______, _______, _______,
        _______,             _______,     _______,      _______,        _______,        _______,    _______,    _______,    _______,
    )
};


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
