#include QMK_KEYBOARD_H

enum layer {
    LAYER_DEFAULT,
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
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  |     |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |   Space    |  FN  |      RSh      | FN | RAlt  |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------'
   */

    [LAYER_DEFAULT] = LAYOUT_directional(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DEL,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(LAYER_UTIL), KC_RSFT, MO(LAYER_EMOJI), KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
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

    [LAYER_UTIL] = LAYOUT_directional(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
        _______, KC_MPLY, KC_VOLU, KC_MSTP, _______, KC_I,    _______, _______, _______, _______, _______, XP(AA, SHIFTAA), _______, KC_GRAVE,
        KC_CAPS, KC_MPRV, KC_VOLD, KC_MNXT, _______, KC_P,    _______, _______, _______, _______, XP(AE, SHIFTAE), XP(OE, SHIFTOE),  X(THUMBSUP),
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, X(UP), _______,
        _______, _______, _______, _______, _______, _______, _______, _______, X(LEFT),         X(DOWN),          X(RIGHT)
    ),

    [LAYER_EMOJI] = LAYOUT_directional(
        UNICODE_MODE_WINC,   X(FIRE),     X(HEARTEYES), _______,        _______,        _______,            _______,    _______,    _______,    _______,    _______,  _______,  _______,  RESET,  RESET,
        UNICODE_MODE_OSX,    X(ANGRY),    X(SMIRK),     X(SWEATSMILE),  X(JOY),         X(HEARTEYES),       _______,    _______,    _______,    _______,    _______,  _______,  _______,  _______,
        _______,             X(TOUNGUE),  X(SCARED),    X(FLUSHED),     X(MOAN),        X(STRONK),          _______,    _______,    _______,    _______,    _______,  _______,  _______,
        _______,             _______,     X(XD),        X(KISS),        X(THUMBSUP),    X(THUMBSDOWN),      _______,    _______,    _______,    _______,    _______,  _______, X(UP), _______,
        _______,             _______,     _______,      _______,        _______,        _______,    _______,    _______,    X(LEFT),  X(DOWN),  X(RIGHT)
    )
};

uint32_t layer_state_set_user(uint32_t state)
{
  switch (biton32(state))
  {
    case LAYER_EMOJI:
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL+5);
      break;
    case LAYER_UTIL:
      rgblight_mode(RGBLIGHT_MODE_SNAKE+3);
      // rgblight_sethsv(12, 255, 255);
      rgblight_sethsv(HSV_TEAL);
      break;
    default:
    case LAYER_DEFAULT:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      // rgblight_sethsv(12, 255, 255);
      rgblight_sethsv(HSV_TEAL);
      break;
  }
  return state;
}
