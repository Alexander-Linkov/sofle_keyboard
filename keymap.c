// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _JCUKEN,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD, // next word
    KC_LSTRT, // home
    KC_LEND,  // end
    LI_COMMA, // ,
    LI_DOT,   // .
    LI_QUES,  // ?
    LI_QUOT,  // '
    LI_DQUO,  // "
    LI_COLN,  // :
    LI_SCLN,  // ;
    LI_LBRC,  // [
    LI_RBRC,  // ]
    LI_LCBR,  // {
    LI_RCBR,  // }
    LI_BSLS,  // backslash
    LI_SLSH,  // forward slash
    LI_LT,    // <
    LI_GT,    // >
    LI_CIRC,  // ^
    LI_AT,    // @
    LI_AMPR,  // &
    LI_HASH,  // #
    LI_DLR,   // $
    LI_TILD,  // ~
    LI_GRAVE, // `
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_JCUKEN PDF(_JCUKEN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TGLOWR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GUI/]}|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |RGUI/[|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtr/`|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RCtr/'|
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |LAlt/\|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RAlt/-|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Switch | Del | LOWER | LShift| /RAISE  /       \RAISE \  |RShift | LOWER |      |      |
 *            |language|     |  Tab  | Space |/ Enter /         \ Esc  \ | Bspc  | Del   |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,          KC_1,      KC_2,   KC_3,          KC_4,           KC_5,                     KC_6,          KC_7,            KC_8,          KC_9,   KC_0,    TG(1),
  LGUI_T(KC_RBRC), KC_Q,      KC_W,   KC_E,          KC_R,           KC_T,                     KC_Y,          KC_U,            KC_I,          KC_O,   KC_P,    RGUI_T(KC_LBRC),
  LCTL_T(KC_GRV),  KC_A,      KC_S,   KC_D,          KC_F,           KC_G,                     KC_H,          KC_J,            KC_K,          KC_L,   KC_SCLN, RCTL_T(KC_QUOT),
  LALT_T(KC_BSLS), KC_Z,      KC_X,   KC_C,          KC_V,           KC_B,   KC_MUTE, KC_MPLY, KC_N,          KC_M,            KC_COMM,       KC_DOT, KC_SLSH, RALT_T(KC_MINS),
                   KC_JCUKEN, KC_DEL, LT(2, KC_TAB), LSFT_T(KC_SPC), LT(1, KC_ENT),            LT(1, KC_ESC), RSFT_T(KC_BSPC), LT(2, KC_DEL), KC_NO,  KC_NO
),

/*
 * ЙЦУКЕН
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TGLOWR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GUI/Ъ |   Й  |   Ц  |   У  |   К  |   Е  |                    |   Н  |   Г  |   Ш  |   Щ  |   З  |RGUI/Х|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtr/Ё|   Ф  |   Ы  |   В  |   А  |   П  |-------.    ,-------|   Р  |   О  |   Л  |   Д  |   Ж  |RCtr/Э|
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |LAlt/\|   Я  |   Ч  |   С  |   М  |   И  |-------|    |-------|   Т  |   Ь  |   Б  |   Ю  |   /  |RAlt/-|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Switch | Del | LOWER | LShift| /RAISE  /       \RAISE \  |RShift | LOWER |      |      |
 *            |language|     |  Tab  | Space |/ Enter /         \ Esc  \ | Bspc  | Del   |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [_JCUKEN] = LAYOUT( 
    KC_ESC,                          KC_1,                    KC_2,                    KC_3,                    KC_4,                    KC_5,                                      KC_6,                    KC_7,                    KC_8,                    KC_9,                    KC_0,                    TG(1),  
    LGUI_T(UP(0x044A, 0x042A)/*ъ*/), UP(0x0439, 0x0419)/*й*/, UP(0x0446, 0x0426)/*ц*/, UP(0x0443, 0x0423)/*у*/, UP(0x043A, 0x041A)/*к*/, UP(0x0435, 0x0415)/*е*/,                   UP(0x043D, 0x041D)/*н*/, UP(0x0433, 0x0413)/*г*/, UP(0x0448, 0x0428)/*ш*/, UP(0x0449, 0x0429)/*щ*/, UP(0x0437, 0x0417)/*з*/, RGUI_T(UP(0x0445, 0x0425)/*х*/),  
    LCTL_T(UP(0x0451, 0x0401)/*ё*/), UP(0x0444, 0x0424)/*ф*/, UP(0x044B, 0x042B)/*ы*/, UP(0x0432, 0x0412)/*в*/, UP(0x0430, 0x0410)/*а*/, UP(0x043F, 0x041F)/*п*/,                   UP(0x0440, 0x0420)/*р*/, UP(0x043E, 0x041E)/*о*/, UP(0x043B, 0x041B)/*л*/, UP(0x0434, 0x0414)/*д*/, UP(0x0436, 0x0416)/*ж*/, RCTL_T(UP(0x044D, 0x042D)/*э*/),  
    LALT_T(KC_BSLS),                 UP(0x044F, 0x042F)/*я*/, UP(0x0447, 0x0427)/*ч*/, UP(0x0441, 0x0421)/*с*/, UP(0x043C, 0x041C)/*м*/, UP(0x0438, 0x0418)/*и*/, KC_MUTE, KC_MPLY, UP(0x0442, 0x0422)/*т*/, UP(0x044C, 0x042C)/*ь*/, UP(0x0431, 0x0411)/*б*/, UP(0x044E, 0x042E)/*ю*/, KC_SLSH, RALT_T(KC_MINS),  
                                     KC_QWERTY,               KC_DEL,                  LT(2, KC_TAB),           LSFT_T(KC_SPC),          LT(1, KC_ENT),                             LT(1, KC_ESC),           RSFT_T(KC_BSPC),         LT(2, KC_DEL),           KC_NO,                   KC_NO  
 ),

/*
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   ~  |   `  |      |      |   [  |                    |   ]  |   *  |   /  |      | NmLc |TGLOWR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GUI/]}|   '  |   "  |   :  |   ;  |   {  |                    |   }  |   7  |   8  |   9  |   +  |RGUI/[|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtr/`|   !  |   ?  |   .  |   ,  |   (  |-------.    ,-------|   )  |   4  |   5  |   6  |   -  |RCtr/'|
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |LAlt/\|   \  |   /  |   =  |   -  |   <  |-------|    |-------|   >  |   1  |   2  |   3  |   0  |RAlt/-|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Switch |      | LOWER |LShift| /RAISE /       \RAISE \  |RShift| LOWER |  .  |  ,  |
 *            |Language|      | Tab   |Space |/ Enter/         \ Esc  \ | Bspc | Del   |     |     |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, LI_TILD, LI_GRAVE,   KC_NO,   KC_NO,   LI_LBRC,                       LI_RBRC,   KC_PAST, KC_PSLS, KC_NO, KC_NUM, _______,
  _______, LI_QUOT, LI_DQUO, LI_COLN, LI_SCLN,  LI_LCBR,                       LI_RCBR, KC_P7,   KC_P8,   KC_P9, KC_PPLS, _______,
  _______, KC_EXLM, LI_QUES, LI_DOT,  LI_COMMA, KC_LPRN,                       KC_RPRN, KC_P4,   KC_P5,   KC_P6, KC_PMNS, _______,
  _______, LI_BSLS, LI_SLSH, KC_EQL,  KC_MINS,  LI_LT,   KC_BTN1,       KC_BTN2, LI_GT, KC_P1,   KC_P2,   KC_P3, KC_P0, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, KC_PDOT, KC_PCMM
),
/*
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GUI/]}|Insert|   *  |   ^  |   %  | Apps |                    | PgUp |PrvWrd|  Up  |NxtWrd|DelWrd|  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtr/`|   @  |   &  |   #  |   $  |CpsLck|-------.    ,-------| PgDw | Left | Down | Right|Delete|      |
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |LAlt/\|Ctrl+z|Ctrl+x|Ctrl+c|Ctrl+v|Ctrl+b|-------|    |-------|      | Home |      | End  |      | Calc |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | LOWER |LShift| /RAISE /       \RAISE \  |RShift| LOWER |     | Prt |
 *            |      |      | Tab   |Space |/ Enter/         \ Esc  \ | Bspc | Del   |     | Scr |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_F1,   KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5,                         KC_F6,    KC_F7 ,   KC_F8,   KC_F9,    KC_F10,     KC_F11,
  _______, KC_INS,  KC_ASTR, LI_CIRC, KC_PERC, KC_APP,                        KC_PGUP,  KC_PRVWD, KC_UP,   KC_NXTWD, C(KC_BSPC), KC_F12,
  _______, LI_AT,   LI_AMPR, LI_HASH, LI_DLR,  KC_CAPS,                       KC_PGDN,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_DEL,     KC_NO,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_B),  _______,       _______, KC_NO, KC_LSTRT, KC_NO,   KC_LEND,  KC_NO,      KC_CALC,
                _______, _______, _______, _______, _______,       _______, _______, _______, KC_NO, KC_PSCR
)
};
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
 [_ADJUST] = LAYOUT(
    XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                     _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    )
  };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case LI_COMMA:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P4);
                tap_code(KC_P4);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_DOT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P4);
                tap_code(KC_P6);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_QUES:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P6);
                tap_code(KC_P3);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_QUOT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P3);
                tap_code(KC_P9);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_DQUO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P3);
                tap_code(KC_P4);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_COLN:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P5);
                tap_code(KC_P8);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_SCLN:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P5);
                tap_code(KC_P9);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_LBRC:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P9);
                tap_code(KC_P1);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_RBRC:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P9);
                tap_code(KC_P3);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_LCBR:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P1);
                tap_code(KC_P2);
                tap_code(KC_P3);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_RCBR:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P1);
                tap_code(KC_P2);
                tap_code(KC_P5);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_BSLS:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P9);
                tap_code(KC_P2);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_SLSH:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P4);
                tap_code(KC_P7);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_LT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P6);
                tap_code(KC_P0);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_GT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P6);
                tap_code(KC_P2);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_CIRC:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P9);
                tap_code(KC_P4);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_AT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P6);
                tap_code(KC_P4);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_AMPR:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P3);
                tap_code(KC_P8);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_HASH:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P3);
                tap_code(KC_P5);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_DLR:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P3);
                tap_code(KC_P6);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_TILD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P1);
                tap_code(KC_P2);
                tap_code(KC_P6);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
        case LI_GRAVE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LALT));
                tap_code(KC_P9);
                tap_code(KC_P6);
                unregister_mods(mod_config(MOD_LALT));
            } else {
                //release the key
            }
            break;
    }
    return true;
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [1] =   { ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [2] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)  }
};
#endif
