/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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

/* 	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K212, K014, \
 *	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,       K114, \
 *	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213,       K214, \
 *	K300, K404, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
 *	K400, K401, K402,       K403,       K405,       K407,       K409, K410,       K411, K413, K414  \
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_DEFAULT] = LAYOUT_all(
	KC_ESC,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,  KC_DEL,
	KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, KC_GRV,
	TG(LAYER_POE),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
	KC_LSFT,        KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
	KC_LCTL,        KC_LGUI, KC_LALT,          KC_SPC,           LY_UTIL,           LY_EMOJI,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [LAYER_POE] = LAYOUT_all(
	_______, _______,   FLASK2,   FLASK3,   FLASK4,  _______, _______, _______, _______, _______, _______, _______,          _______,          _______,   _______,   _______,
	_______, _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,          _______,  _______,    _______,
	_______, _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,  _______,  _______,
	_______, _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,          _______,          _______,          _______,
	_______, _______,  _______,            _______,           LY_POE_UTIL,               _______,          _______, _______,              _______,          _______, _______
  ),
  [LAYER_POE_UTIL] = LAYOUT_all(
	_______, FLASK1,  FLASK2,    FLASK3,   FLASK4,   KC_F5,   KC_BSPC,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   X(THUMBSDOWN),   X(THUMBSDOWN),   X(FIST),
	KC_CAPS, KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,  KC_I, _______, _______, _______, _______, _______,           XP(AA, SHIFTAA),    _______,    _______, _______,
	_______, KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  KC_P, _______, _______, _______, _______,  XP(AE, SHIFTAE),  XP(OE, SHIFTOE),  X(THUMBSUP),  _______,
	_______, _______,  KC_MUTE,  _______,  _______,  HIDEOUT, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, _______,
	_______, _______, _______,             _______,           _______,          _______,          _______, _______,          KC_HOME, KC_PGDN, KC_END
  ),
  [LAYER_UTIL] = LAYOUT_all(
	KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_BSPC,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   X(THUMBSDOWN),   X(THUMBSDOWN),   X(FIST),
	KC_CAPS, KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,  _______, _______, _______, _______, _______, _______,          XP(AA, SHIFTAA),    _______,    _______, _______,
	_______, KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  _______, _______, _______, _______, _______,  XP(AE, SHIFTAE),  XP(OE, SHIFTOE),  X(THUMBSUP),  _______,
	_______, _______,  KC_MUTE,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, _______,
	_______, _______, _______,          _______,          _______,          _______,          _______, _______,          KC_HOME, KC_PGDN, KC_END
  ),
  [LAYER_EMOJI] = LAYOUT_all(
	UNICODE_MODE_WINC,  KC_KP_1,   KC_KP_2,   KC_KP_3,   KC_KP_4,  KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, _______,          _______,          _______,   _______,   RESET,
	UNICODE_MODE_OSX,   X(ANGRY),    X(SMIRK),     X(SWEATSMILE),  X(JOY),         X(HEARTEYES),  _______, _______, _______, _______, _______,          _______,  _______,    _______, _______,
	_______,            X(TOUNGUE),  X(SCARED),    X(FLUSHED),     X(MOAN),        X(STRONK),     _______, _______, _______, _______, _______,  _______,  _______,  _______,
	_______,            KC_TRNS,     X(XD),        X(KISS),        X(THUMBSUP),    X(THUMBSDOWN), _______, _______, _______, _______, _______,          _______,          _______,          _______, _______,
	_______,            _______,  _______,            _______,           LY_POE_UTIL,               _______,          _______, _______,              _______,          _______, _______
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
