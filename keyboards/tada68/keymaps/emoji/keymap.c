#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _EMOJILAYER 2

// supply this with uppercase letters and
// returns the index in unicode_map
// of the emoji
// const int KEY(char name)
// {
//   return (int)(name - 'A');
// }

#define KEY(X) ((int)(X - 'A'))

// unicode mapping table
// from regional indicator a to regional indicator z
const uint32_t PROGMEM unicode_map[] = {
 //0x1F1E6, 0x1F1E7, 0x1F1E8, 0x1F1E9, 0x1F1EA, 0x1F1EB,
 0x1F1E6, 0x1F171, 0x1F1E8, 0x1F1E9, 0x1F1EA, 0x1F1EB,
 0x1F1EC, 0x1F1ED, 0x1F1EE, 0x1F1EF, 0x1F1F0, 0x1F1F1,
 0x1F1F2, 0x1F1F3, 0x1F1F4, 0x1F1F5, 0x1F1F6, 0x1F1F7,
 0x1F1F8, 0x1F1F9, 0x1F1FA, 0x1F1FB, 0x1F1FC, 0x1F1FD,
 0x1F1FE, 0x1F1FF,
};

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Home|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_HOME,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_END, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |ins|   |   |   |   |     |PGUP|
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |   |   |   |hme|pgp|        |PGDN|
   * |----------------------------------------------------------------|
   * |        |   |app |Bl-|BL |BL+|VU-|VU+|MUT|end|pgdn|  McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  TO(_EMOJILAYER), KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,KC_INS,_______,_______,_______,_______, _______,KC_PGUP, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,_______,_______,KC_HOME,KC_PGUP,        _______,KC_PGDN, \
  _______,_______,KC_APP ,BL_DEC, BL_TOGG,BL_INC,KC_VOLD,KC_VOLU,KC_MUTE, KC_END,KC_PGDN,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),

  [_EMOJILAYER] = KEYMAP_ANSI(
    TO(_BL), _______ ,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, _______ ,  \
    _______, X(KEY('Q')), X(KEY('W')),X(KEY('E')),X(KEY('R')), X(KEY('T')),X(KEY('Y')),X(KEY('U')),X(KEY('I')),X(KEY('O')), X(KEY('P')) ,_______,_______, _______,_______, \
    _______,X(KEY('A')),X(KEY('S')),X(KEY('D')),X(KEY('F')),X(KEY('G')),X(KEY('H')),X(KEY('J')),X(KEY('K')),X(KEY('L')),_______,_______,        _______,_______, \
    _______,X(KEY('Z')),X(KEY('X')) ,X(KEY('C')),X(KEY('V')),X(KEY('B')),X(KEY('N')),X(KEY('M')),_______, _______,_______,_______, _______, _______, \
    _______,_______,_______,                 KC_SPC,               _______,_______,_______,_______,_______, _______),
  };

// init stuff
void matrix_init_user(void) {
    // setup unicode to work under linux
    set_unicode_input_mode(UC_LNX);
}
