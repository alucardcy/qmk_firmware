// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layer {
    _MAIN,
    _MAC,
    _GAMING,
    _FN3,
    _FN4,
    _FN5
};

// https://docs.qmk.fm/feature_macros
enum custom_keycodes {
      ARROW_DSH = SAFE_RANGE,
      ARROW_EQL,
      JS_FUNC,
      ELX_PIP,
      RARROW_DSH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ARROW_DSH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("->");
        } else {
            // when keycode QMKBEST is released
        }
        break;
      case ARROW_EQL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("=>");
        } else {
            // when keycode QMKBEST is released
        }
        break;
      case JS_FUNC:
         if (record->event.pressed) {
               // when keycode QMKBEST is pressed
               SEND_STRING("() => { }");
         } else {
               // when keycode QMKBEST is released
         }
         break;
      case ELX_PIP:
         if (record->event.pressed) {
               // when keycode QMKBEST is pressed
               SEND_STRING("|>");
         } else {
               // when keycode QMKBEST is released
         }
         break;
      case RARROW_DSH:
         if (record->event.pressed) {
               // when keycode QMKBEST is pressed
               SEND_STRING("<-");
         } else {
               // when keycode QMKBEST is released
         }
         break;
    }
    return true;
};


// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)


// other definitions
#define LT_GUI LT(4, KC_LGUI)
#define SFT_EQL LSFT_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     LT_GUI,   GUI_A,    ALT_S,  SFT_D,   CTL_F,  KC_G,                               KC_H,    CTL_J,   SFT_K,    ALT_L,  GUI_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    TT(4),             TT(3),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_EQL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL, KC_ENT,                    KC_SPC,  KC_LALT, KC_LCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MAC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, GUI_A,    ALT_S,    SFT_D,  CTL_F,  KC_G,                               KC_H,    CTL_J,   SFT_K,    ALT_L,  GUI_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     TT(4),             TT(3),   KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, SFT_EQL,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_LGUI, KC_ENT,                    KC_SPC,  KC_LGUI, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAMING] =LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TT(4),             KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, KC_SPC,                    KC_SPC,  TT(3),    KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
   [_FN3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_EXLM, KC_MINUS, KC_BSLS,KC_LBRC, KC_RBRC,                            KC_NUM,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, ARROW_DSH, ARROW_EQL, KC_GRV, KC_NO,    KC_NO,                          KC_PLUS, KC_P4,    KC_P5,   KC_P6,   KC_PAST, TT(5),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, JS_FUNC, JS_FUNC, ELX_PIP,RARROW_DSH, KC_NO,  TT(5),           KC_TRNS, KC_MINUS, KC_P1,   KC_P2,   KC_P3,  KC_PSLS, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS,KC_TRNS,   KC_TRNS,                  KC_TRNS, KC_PDOT, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
   [_FN4] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS,  MO(3),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, MS_BTN1, MS_UP,   MS_BTN2, MS_WHLU,  KC_HOME,                            KC_HOME, KC_END,   KC_NO,   KC_NO,   KC_NO, KC_PSCR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, KC_END,                             KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT, KC_NO, KC_LCAP,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, MS_WHLL, KC_NO,     KC_NO,   TT(5),  MS_WHLR, KC_TRNS,          TT(5),   MS_ACL0, MS_ACL1 ,MS_ACL2,KC_PGUP, KC_PGDN, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
   [_FN5] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS,  DF(0),   DF(1),   DF(2),   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                              KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   TT(5),   KC_MPLY, KC_MNXT,          KC_VOLU, KC_MUTE,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_MPRV,                   KC_VOLD, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

         case LGUI_T(KC_A):
         case LALT_T(KC_S):
         case LSFT_T(KC_D):
         case LCTL_T(KC_F):
         case RCTL_T(KC_J):
         case RSFT_T(KC_K):
         case LALT_T(KC_L):
         case RGUI_T(KC_SCLN):
         return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}


bool rgb_matrix_indicators_user(void) {
    //Get the current active layer
    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _FN3:  // Layer 3: purple at 50% brightness
            rgb_matrix_set_color_all(64, 0, 61);   // purple
            break;

        case _FN4:  // Layer 4: teal at 50% brightness

            rgb_matrix_set_color_all(0, 64, 64);   // teal
            break;

        case _FN5:  // Layer 5: Red

            rgb_matrix_set_color_all(128, 0, 0);   // Red
            break;

        default:  // Default layer: Let RGB be managed by VIA
            // Do nothing, VIA will manage the RGB settings
            break;
    }
   return true;
}