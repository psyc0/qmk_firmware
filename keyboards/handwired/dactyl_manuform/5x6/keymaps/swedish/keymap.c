/* A Swedish XMonad layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum dactyl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 900) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define TERM   LCTL(LALT(KC_T))
//#define ALTTAB LALT(KC_TAB)
#define INSERT LSFT(KC_INS)
#define KILL   LGUI(LSFT(KC_C))
#define OPEN   LALT(KC_F2)
#define KC_QSM LSFT(SE_PLUS)
#define KC_AA  SE_AA
#define KC_AE  SE_AE
#define KC_OE  SE_OSLH



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , SE_APOS,
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_AA  ,
     KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_OE  , KC_AE  ,
     KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , SE_SLSH, SE_MINS,
                       KC_EXLM, KC_QSM ,                                                            SE_PLUS, SE_EQL ,
                                                  RAISE  , KC_SPC ,      KC_ENT , LOWER  ,
                                                  KC_LALT, KC_LGUI,      KC_DEL , KC_BSPC ,
                                                  ALT_TAB, TERM   ,      OPEN   , INSERT
  ),

  [_LOWER] = LAYOUT_5x6(
     SE_TILD, KC_EXLM,  SE_AT , KC_HASH, SE_DLR , KC_PERC,                        SE_CIRC, SE_AMPR, SE_ASTR, SE_SLSH, SE_LPRN, SE_RPRN,
     SE_ACUT, _______, _______, _______, _______, _______,                        KC_HOME, KC_PGUP, KC_UP  , KC_PGDN, SE_LCBR, SE_RCBR,
     _______, _______, _______, _______, _______, _______,                        KC_END , KC_LEFT, KC_DOWN, KC_RGHT, SE_LBRC, SE_RBRC,
     SE_PIPE, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, SE_LESS, SE_GRTR,
                       _______, _______,                                                            _______, _______,
                                                  KC_F12 , _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______

  ),

  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     _______, _______, _______, _______, _______, _______,                        KC_MPLY, KC_VOLU, KC_MPRV, KC_MNXT, KC_MUTE, SE_PIPE,
     _______, _______, _______, _______, _______, _______,                        _______, KC_VOLD, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, SE_BSLS, _______,
                       _______, _______,                                                            _______, _______, 
                                                  _______, _______,      _______, KC_PSCR,
                                                  _______, _______,      _______, KC_INS , 
                                                  _______, _______,      _______, _______
  ),
};
