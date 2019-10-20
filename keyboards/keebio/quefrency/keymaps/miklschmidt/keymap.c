#include QMK_KEYBOARD_H

static uint16_t last_rgb;
static uint8_t rgb_state[RGBLED_NUM];

enum layer {
    LAYER_DEFAULT,
    LAYER_FUNCTION,
    LAYER_EMOJI,
    LAYER_UTIL,
};

enum emoji_map {
  JOY, // 😂
  UNAM, // unamused 😒
  HEYE, // smiling face with heart shaped eyes 😍
  OK, // ok hand sign 👌
  SMIR, // smirk 😏
  PRAY, // pray 🙏
  CELE, // celebration 🙌
  COOL, // smile with sunglasses 😎
  EYES, // eyes 👀
  THNK, // BIG THONK
  NAIL, // Nailcare
  SOS, // Vuile sos
  REDB, // Red B
  HNDR, // 100
  MONY,
  FIRE,
  CAR,
  BUTT,
  BNIS,
  DRIP,
  CLAP,
  TRIU, // Fart from nose
  SCRM,
  VOMI,
  DTIV, // Detective
  EXPL, // Brainsplosion
  HAIR, // Haircut
  DANC, // Salsa dancer
  STRN, // Stronk
  LEFT, // Point Left
  RGHT, // Point Right
  AE,
  AA,
  OE,
  SHIFTAE,
  SHIFTAA,
  SHIFTOE
};

const uint32_t PROGMEM unicode_map[] = {
  [JOY] = 0x1F602,
  [UNAM] = 0x1F612,
  [HEYE] = 0x1f60d,
  [OK]   = 0x1F44C,
  [SMIR] = 0x1F60F,
  [PRAY] = 0x1F64F,
  [CELE] = 0x1F64C,
  [COOL] = 0x1F60E,
  [EYES] = 0x1F440,
  [THNK] = 0x1F914,
  [NAIL] = 0x1F485,
  [SOS] = 0x1F198,
  [REDB] = 0x1F171,
  [HNDR] = 0x1F4AF,
  [MONY] = 0x1F480,
  [FIRE] = 0x1F525,
  [CAR] = 0x1F697,
  [BUTT] = 0x1F351,
  [BNIS] = 0x1F346,
  [DRIP] = 0x1F4A6,
  [CLAP] = 0x1F44F,
  [TRIU] = 0x1F624,
  [SCRM] = 0x1F631,
  [VOMI] = 0x1F92E,
  [DTIV] = 0x1F575,
  [EXPL] = 0x1F92F,
  [HAIR] = 0x2640,
  [DANC] = 0x1F483,
  [STRN] = 0x1F4AA,
  [LEFT] = 0x1F448,
  [RGHT] = 0x1F449,
  [AE] = 0x00E6,
  [OE] = 0x00F8,
  [AA] = 0x00E5,
  [SHIFTAE] = 0x00C6,
  [SHIFTOE] = 0x00D8,
  [SHIFTAA] = 0x00C5,
};
#define LY_FN MO(LAYER_FUNCTION)
#define LY_UTIL MO(LAYER_UTIL)
#define LY_EMOJI MO(LAYER_EMOJI)
#define UTIL_OR_FLASKS LT(LY_UTIL, M(0))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_DEFAULT] = LAYOUT_65(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,            KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_BSPC,   KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,            KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_GRV,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,            KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_HOME,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,            KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LALT,  KC_LGUI,  KC_SPC,   LY_UTIL,  LY_EMOJI, LY_FN,    KC_RGUI,  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [LAYER_FUNCTION] = LAYOUT_65(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   RGB_HUI,
        _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  _______,  _______,  _______,  _______,
        _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_U,  _______,
        KC_BTN2,  _______,  _______,  KC_BTN1,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_L,  KC_WH_D,  KC_WH_R
    ),

    [LAYER_UTIL] = LAYOUT_65(
        _______,  _______,  _______,  _______,  _______,  _______,  KC_BSPC,  _______,  _______,  _______,  _______,         _______,          _______,  _______,  _______,   RGB_SAI,
        _______,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,  KC_I,     _______,  _______,  _______,  _______,  _______,         XP(AA, SHIFTAA),  _______,  _______,  RGB_SAD,
        KC_CAPS,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  KC_P,     _______,  _______,  _______,  _______,  XP(AE, SHIFTAE), XP(OE, SHIFTOE),  RGB_TOG,  RGB_HUI,
        _______,  _______,  KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,         _______,          RGB_VAI,  RGB_HUD,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_RMOD,        RGB_VAD,          RGB_MOD
    ),

    [LAYER_EMOJI] = LAYOUT_65(
        UNICODE_MODE_WINC,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,
        UNICODE_MODE_OSX,  X(CLAP),  X(DRIP),  X(BNIS),  X(JOY),  X(CAR) ,  X(FIRE),  X(REDB),  X(MONY),  X(HNDR),  X(SOS) ,  _______,  _______,  _______,   _______,
        _______,           X(CELE),  X(PRAY),  X(NAIL),  X(OK)  ,  X(THNK),  X(UNAM),  X(HEYE),  X(COOL),  X(EYES),  X(SMIR),  _______,  _______,  _______,
        _______,           X(TRIU),  X(SCRM),  X(VOMI),  X(DTIV),  X(EXPL),  X(HAIR),  X(DANC),  X(STRN),  X(LEFT),  X(RGHT),  _______,  _______,  _______,
        _______,           _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),

};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable = false;
    // debug_matrix = false;
    // debug_keyboard=true;
    // debug_mouse=true; s
}

void matrix_init_user(void) {
    last_rgb = timer_read();
    rgblight_setrgb(0, 0, 0);

    for (int i = 0; i < RGBLED_NUM; i++) {
        rgb_state[i] = 0;
    }
}

void matrix_scan_user(void) {
    // Animate the ripple effect at 50Hz (20ms interval):

    if (timer_elapsed(last_rgb) > 20) {
        last_rgb = timer_read();

        uint8_t next_rgb_state[RGBLED_NUM];
        for (int i = 0; i < RGBLED_NUM; i++) {

            // Retain some:
            next_rgb_state[i] = rgb_state[i] * RGB_SUSTAIN;

            // Accept some from neighbors ...

            // Lower neighbor, excluding lower bound of each hand:
            if (i != 0 && i != RGBLED_NUM / 2) {
                next_rgb_state[i] += rgb_state[i - 1] * RGB_PROPAGATE;
            }
            // Upper neighbor, excluding upper bound of each hand:
            if (i != RGBLED_NUM / 2 - 1 && i != RGBLED_NUM - 1) {
                next_rgb_state[i] += rgb_state[i + 1] * RGB_PROPAGATE;
            }
            led[i].r = next_rgb_state[i];
        }
        rgblight_set();
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
            case 0:
                return MACRO( T(2), W(21), T(3), W(36), T(4), W(14), T(5), END );
        }
    }
    return MACRO_NONE;
};

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
};

// RGB Based on layers
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case LAYER_FUNCTION:
        rgblight_mode(1);
        rgblight_setrgb(RGB_CYAN);
        break;
    case LAYER_UTIL:
        rgblight_mode(1);
        rgblight_setrgb(RGB_PINK);
        break;
    case LAYER_EMOJI:
        rgblight_mode(1);
        rgblight_setrgb(RGB_ORANGE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_mode(14);
        break;
    }
  return state;
}
