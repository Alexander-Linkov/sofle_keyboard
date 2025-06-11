// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _JCUKEN,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum unicode_map {
    RU_HARD_SIGN_L, RU_HARD_SIGN_U,  // Ъ, Ъ (строчная/заглавная)
    RU_YI_L,        RU_YI_U,         // Й, Й
    RU_TS_L,        RU_TS_U,         // Ц, Ц
    RU_U_L,         RU_U_U,          // У, У
    RU_K_L,         RU_K_U,          // К, К
    RU_E_L,         RU_E_U,          // Е, Е
    RU_N_L,         RU_N_U,          // Н, Н
    RU_G_L,         RU_G_U,          // Г, Г
    RU_SH_L,        RU_SH_U,         // Ш, Ш
    RU_SC_L,        RU_SC_U,         // Щ, Щ
    RU_Z_L,         RU_Z_U,          // З, З
    RU_H_L,         RU_H_U,          // Х, Х
    RU_YO_L,        RU_YO_U,         // Ё, Ё
    RU_F_L,         RU_F_U,          // Ф, Ф
    RU_Y_L,         RU_Y_U,          // Ы, Ы
    RU_V_L,         RU_V_U,          // В, В
    RU_A_L,         RU_A_U,          // А, А
    RU_P_L,         RU_P_U,          // П, П
    RU_R_L,         RU_R_U,          // Р, Р
    RU_O_L,         RU_O_U,          // О, О
    RU_L_L,         RU_L_U,          // Л, Л
    RU_D_L,         RU_D_U,          // Д, Д
    RU_J_L,         RU_J_U,          // Ж, Ж
    RU_EA_L,        RU_EA_U,         // Э, Э
    RU_YA_L,        RU_YA_U,         // Я, Я
    RU_CH_L,        RU_CH_U,         // Ч, Ч
    RU_S_L,         RU_S_U,          // С, С
    RU_M_L,         RU_M_U,          // М, М
    RU_I_L,         RU_I_U,          // И, И
    RU_T_L,         RU_T_U,          // Т, Т
    RU_SOFT_SIGN_L, RU_SOFT_SIGN_U,  // Ь, Ь
    RU_B_L,         RU_B_U,          // Б, Б
    RU_YU_L,        RU_YU_U,          // Ю, Ю
    APOSTROPHE,                  // '
    QUOTE,                        // "
    L_PPOINT_DOUBLE_ANGLE_QUOTE,  // «
    R_PPOINT_DOUBLE_ANGLE_QUOTE,  // »
};

const uint32_t unicode_map[] = {
    [RU_HARD_SIGN_L] = 0x044A, [RU_HARD_SIGN_U] = 0x042A,
    [RU_YI_L]        = 0x0439, [RU_YI_U]        = 0x0419,
    [RU_TS_L]        = 0x0446, [RU_TS_U]        = 0x0426,
    [RU_U_L]         = 0x0443, [RU_U_U]         = 0x0423,
    [RU_K_L]         = 0x043A, [RU_K_U]         = 0x041A,
    [RU_E_L]         = 0x0435, [RU_E_U]         = 0x0415,
    [RU_N_L]         = 0x043D, [RU_N_U]         = 0x041D,
    [RU_G_L]         = 0x0433, [RU_G_U]         = 0x0413,
    [RU_SH_L]        = 0x0448, [RU_SH_U]        = 0x0428,
    [RU_SC_L]        = 0x0449, [RU_SC_U]        = 0x0429,
    [RU_Z_L]         = 0x0437, [RU_Z_U]         = 0x0417,
    [RU_H_L]         = 0x0445, [RU_H_U]         = 0x0425,
    [RU_YO_L]        = 0x0451, [RU_YO_U]        = 0x0401,
    [RU_F_L]         = 0x0444, [RU_F_U]         = 0x0424,
    [RU_Y_L]         = 0x044B, [RU_Y_U]         = 0x042B,
    [RU_V_L]         = 0x0432, [RU_V_U]         = 0x0412,
    [RU_A_L]         = 0x0430, [RU_A_U]         = 0x0410,
    [RU_P_L]         = 0x043F, [RU_P_U]         = 0x041F,
    [RU_R_L]         = 0x0440, [RU_R_U]         = 0x0420,
    [RU_O_L]         = 0x043E, [RU_O_U]         = 0x041E,
    [RU_L_L]         = 0x043B, [RU_L_U]         = 0x041B,
    [RU_D_L]         = 0x0434, [RU_D_U]         = 0x0414,
    [RU_J_L]         = 0x0436, [RU_J_U]         = 0x0416,
    [RU_EA_L]        = 0x044D, [RU_EA_U]        = 0x042D,
    [RU_YA_L]        = 0x044F, [RU_YA_U]        = 0x042F,
    [RU_CH_L]        = 0x0447, [RU_CH_U]        = 0x0427,
    [RU_S_L]         = 0x0441, [RU_S_U]         = 0x0421,
    [RU_M_L]         = 0x043C, [RU_M_U]         = 0x041C,
    [RU_I_L]         = 0x0438, [RU_I_U]         = 0x0418,
    [RU_T_L]         = 0x0442, [RU_T_U]         = 0x0422,
    [RU_SOFT_SIGN_L] = 0x044C, [RU_SOFT_SIGN_U] = 0x042C,
    [RU_B_L]         = 0x0431, [RU_B_U]         = 0x0411,
    [RU_YU_L]        = 0x044E, [RU_YU_U]        = 0x042E,
    [APOSTROPHE]  = 0x0027,                  // '
    [QUOTE] = 0x0022,                        // "
    [L_PPOINT_DOUBLE_ANGLE_QUOTE]  = 0x00AB, // «
    [R_PPOINT_DOUBLE_ANGLE_QUOTE]  = 0x00BB, // 
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD, // next word
    KC_LSTRT, // home
    KC_LEND,  // end
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_JCUKEN PDF(_JCUKEN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RUSL |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TGLOWR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ]   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |LAlt/\|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RAlt/-|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI|LCTRl| LOWER | LShift| /RAISE  /       \RAISE \  |RShift | LOWER | RCtrl | RGUI |
 *            |     |     |  Tab  | Space |/ Enter /         \ Esc  \ | Bspc  | Del   |       |      |
 *            `----------------------------------'            '------''-------------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_JCUKEN,          KC_1, KC_2,    KC_3,    KC_4,          KC_5,                                         KC_6,            KC_7,          KC_8,    KC_9,    KC_0,    TG(1),
  KC_RBRC,            KC_Q, KC_W,    KC_E,    KC_R,          KC_T,                                         KC_Y,            KC_U,          KC_I,    KC_O,    KC_P,    KC_LBRC,
  KC_GRV,             KC_A, KC_S,    KC_D,    KC_F,          KC_G,                                         KC_H,            KC_J,          KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  LALT_T(KC_BSLS),    KC_Z, KC_X,    KC_C,    KC_V,          KC_B,           KC_MUTE,       KC_MPLY,       KC_N,            KC_M,          KC_COMM, KC_DOT,  KC_SLSH, RALT_T(KC_MINS),
                            KC_LGUI, KC_LCTL, LT(3, KC_TAB), LSFT_T(KC_SPC), LT(2, KC_ENT), LT(2, KC_ESC), RSFT_T(KC_BSPC), LT(3, KC_DEL), KC_RCTL, KC_RGUI
),

/*
 * ЙЦУКЕН
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ENGL |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |TGLOWR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Ъ   |   Й  |   Ц  |   У  |   К  |   Е  |                    |   Н  |   Г  |   Ш  |   Щ  |   З  |  Х   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Ё   |   Ф  |   Ы  |   В  |   А  |   П  |-------.    ,-------|   Р  |   О  |   Л  |   Д  |   Ж  |  Э   |
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |LAlt/\|   Я  |   Ч  |   С  |   М  |   И  |-------|    |-------|   Т  |   Ь  |   Б  |   Ю  |   /  |RAlt/-|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *          | LGUI | LCTRL | LOWER | LShift| /RAISE  /       \RAISE \  |RShift | LOWER | RCTRL | RGUI |
 *          |      |       |  Tab  | Space |/ Enter /         \ Esc  \ | Bspc  | Del   |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */

 [_JCUKEN] = LAYOUT(  
    KC_QWERTY,
    KC_1,
    KC_2,
    KC_3,
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
    KC_0,
    TG(1),
    UP(RU_HARD_SIGN_L, RU_HARD_SIGN_U), //second row
    UP(RU_YI_L, RU_YI_U),
    UP(RU_TS_L, RU_TS_U),
    UP(RU_U_L, RU_U_U),
    UP(RU_K_L, RU_K_U),
    UP(RU_E_L, RU_E_U),   
    UP(RU_N_L, RU_N_U),
    UP(RU_G_L, RU_G_U),
    UP(RU_SH_L, RU_SH_U),
    UP(RU_SC_L, RU_SC_U),
    UP(RU_Z_L, RU_Z_U),
    UP(RU_H_L, RU_H_U),
    UP(RU_YO_L, RU_YO_U),               // third row
    UP(RU_F_L, RU_F_U),
    UP(RU_Y_L, RU_Y_U),
    UP(RU_V_L, RU_V_U),
    UP(RU_A_L, RU_A_U),
    UP(RU_P_L, RU_P_U),   
    UP(RU_R_L, RU_R_U),
    UP(RU_O_L, RU_O_U),
    UP(RU_L_L, RU_L_U),
    UP(RU_D_L, RU_D_U),
    UP(RU_J_L, RU_J_U),
    UP(RU_EA_L, RU_EA_U), 
    LALT_T(KC_BSLS),                           // fourth row
    UP(RU_YA_L, RU_YA_U),
    UP(RU_CH_L, RU_CH_U),
    UP(RU_S_L, RU_S_U),
    UP(RU_M_L, RU_M_U),
    UP(RU_I_L, RU_I_U),
    KC_MUTE, KC_MPLY,                          //encoders
    UP(RU_T_L, RU_T_U),
    UP(RU_SOFT_SIGN_L, RU_SOFT_SIGN_U),
    UP(RU_B_L, RU_B_U),
    UP(RU_YU_L, RU_YU_U),
    KC_SLSH,
    RALT_T(KC_MINS),  
    KC_LGUI,                                // fifth row
    KC_LCTL,
    LT(3, KC_TAB),
    LSFT_T(KC_SPC),
    LT(2, KC_ENT),
    LT(2, KC_ESC),
    RSFT_T(KC_BSPC),
    LT(3, KC_DEL),
    KC_RCTL,
    KC_RGUI  
),

/*
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | TGLL |   ~  |   `  |      |      |   {  |                    |   }  |   *  |   /  |      | NmLc |TGLOWR|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  }   |   '  |   "  |   :  |   ;  |   [  |                    |   ]  |   7  |   8  |   9  |   +  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   !  |   ?  |   .  |   ,  |   (  |-------.    ,-------|   )  |   4  |   5  |   6  |   -  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |  \   |   \  |   /  |   =  |   -  |   <  |-------|    |-------|   >  |   1  |   2  |   3  |   0  |  -   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LCTRL | LOWER |LShift| /RAISE /       \RAISE \  |RShift| LOWER |  .  |  ,  |
 *           |      |       | Tab   |Space |/ Enter/         \ Esc  \ | Bspc | Del   |     |     |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, UC(0x007E),                                  UC(0x0060),                             KC_NO,      KC_NO,      UC(0x007B),                      UC(0x007D), KC_PAST, KC_PSLS, KC_CALC, KC_NUM,  _______,
  _______, UP(APOSTROPHE, L_PPOINT_DOUBLE_ANGLE_QUOTE), UP(QUOTE, R_PPOINT_DOUBLE_ANGLE_QUOTE), UC(0x003A), UC(0x003B), UC(0x005B),                      UC(0x005D), KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  _______, KC_EXLM,                                     UC(0x003F),                             UC(0x002E), UC(0x002C), KC_LPRN,                         KC_RPRN,    KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,
  _______, UC(0x005C),                                  UC(0x002F),                             KC_EQL,     KC_MINS,    UC(0x003C), KC_BTN1,    KC_BTN2, UC(0x003E), KC_P1,   KC_P2,   KC_P3,   KC_P0,   _______,
                                                        _______,                                _______,    _______,    _______,    _______,    _______, _______,    _______, KC_PDOT, KC_PCMM
),
/*
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | TGLL |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  }   |Insert|   *  |   ^  |   %  | Apps |                    | PgUp |PrvWrd|  Up  |NxtWrd|DelWrd|  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   @  |   &  |   #  |   $  |CpsLck|-------.    ,-------| PgDw | Left | Down | Right|Delete| PrSc |
 * |------+------+------+------+------+------|  MUTE |    | Play  |------+------+------+------+------+------|
 * |  \   |Ctrl+z|Ctrl+x|Ctrl+c|Ctrl+v|Ctrl+b|-------|    |-------|      | Home |      | End  | UC_N | Calc |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *           | LGUI | LCTRL | LOWER |LShift| /RAISE /       \RAISE \  |RShift| LOWER | RCTRL | RGUI |
 *           |      |       | Tab   |Space |/ Enter/         \ Esc  \ | Bspc | Del   |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_F1,      KC_F2 ,     KC_F3 ,     KC_F4 ,     KC_F5,                        KC_F6,   KC_F7 ,   KC_F8,   KC_F9,    KC_F10,     KC_F11,
  _______, KC_INS,     KC_ASTR,    UC(0x005E), KC_PERC,    KC_APP,                       KC_PGUP, KC_PRVWD, KC_UP,   KC_NXTWD, C(KC_BSPC), KC_F12,
  _______, UC(0x0040), UC(0x0026), UC(0x0023), UC(0x0024), KC_CAPS,                      KC_PGDN, KC_LEFT,  KC_DOWN, KC_RGHT,  KC_DEL,     KC_PSCR,
  _______, C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    C(KC_B), KC_BTN1,    KC_BTN2, KC_NO,   KC_LSTRT, KC_NO,   KC_LEND,  KC_NO,    UC_NEXT,
                       _______,    _______,    _______,    _______, _______,    _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Lin  | Mac  | WinC |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
 [_ADJUST] = LAYOUT(
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX , XXXXXXX, UC_LINX, UC_MAC,  UC_WINC, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
              _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______
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
    }
    return true;
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [1] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [2] =   { ENCODER_CCW_CW(KC_MS_L, KC_MS_R),  ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [3] =   { ENCODER_CCW_CW(KC_MS_L, KC_MS_R),  ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [4] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  }
};
#endif

#ifdef OLED_ENABLE
static void render_status(void) {
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("ENG"), false);
            break;
        case _JCUKEN:
            oled_write_ln_P(PSTR("RUS"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 3:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 4:
            oled_write_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("NMLCK"), led_usb_state.num_lock);
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_P(PSTR("\n"), false);
    switch (get_unicode_input_mode()) {
        case UNICODE_MODE_WINCOMPOSE:
            oled_write_P(PSTR("WIN\n"), false);
            break;
        case UNICODE_MODE_MACOS:
            oled_write_P(PSTR("MacOS\n"), false);
            break;       
        case UNICODE_MODE_LINUX:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("UndOS\n"), false);
    }
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();  // Renders a static logo
        //oled_scroll_left();  // Turns on scrolling
    }
    
    return false;
}
#endif