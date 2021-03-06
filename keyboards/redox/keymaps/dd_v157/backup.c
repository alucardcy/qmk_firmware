#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  C_COPY = SAFE_RANGE,
  C_PASTE,
  C_CUT,
  
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case C_COPY:
        SEND_STRING(SS_LCTL("c"));
        return false;
    case C_PASTE:
        SEND_STRING(SS_LCTL("v"));
        return false;
    case C_CUT:
        SEND_STRING(SS_LCTL("x"));
        return false;

    //   case COLEMAKDHMK_MAC:
    //     if (record->event.pressed) {
    //       set_single_persistent_default_layer(_COLEMAKDHMK_MAC);
    //     }
        return false;
        break;
    }
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, LT(3,KC_BSLS), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, TG(1), TG(2), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, MO(2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LT(1,KC_SPC), KC_ENT, KC_HOME, LT(1,KC_END), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_GRV, KC_CAPS, LALT_T(KC_PAST), LCTL_T(KC_MINS), KC_BSPC, KC_DEL, KC_ENT, KC_SPC, KC_RCTL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

	[_SYMB] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_NO, KC_P7, KC_P8, KC_P9, KC_NO, KC_F12, KC_TRNS, KC_HASH, KC_DLR, KC_LBRC, KC_RBRC, KC_GRV, KC_TRNS, KC_TRNS, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO, KC_TRNS, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_PAST, KC_PSLS),

	[_NAV] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO, KC_TRNS, KC_TRNS, KC_NO, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), KC_NO, KC_PSCR, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_LSFT, KC_WH_L, C_CUT, C_COPY, C_PASTE, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

	[_ADJUST] = LAYOUT(KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, RESET, RGB_M_P, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_VOLD, KC_MPRV, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_MSTP, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {

    case _SYMB:
        rgblight_setrgb (RGB_PURPLE);
        break;
    case _NAV:
        rgblight_setrgb (RGB_TEAL);
        break;
    case _ADJUST:
        rgblight_setrgb (RGB_RED);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (RGB_GREEN);
        break;
    }
  return state;
}