/*
 * Bean: personal keymap based on hasu's template
 *
 * Function keys
 * Fn0  default layer (not used)
 * Fn1  HHKB layer w/ multi-tap toggle
 * Fn2  Vi navigation layer
 * Fn3  Mouse-key layer (semi-colon)
 * Fn4  Matias layer with Space
 * Fn5  ALT_TAB
 * Fn6  RControl with Enter
 * Fn7  LShift with tap '('
 * Fn8  RShift with tap ')'
 * Fn9  Numkey later with Tab
 * Fn10 Oneshot shift
 *
 * Fn20 Vi action 'w'
 * Fn21 Vi action 'b'
 */
#include "keymap_common.h"


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |NmTab|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Fn6     |
     * |-----------------------------------------------------------|
     * |Fn7     |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|Fn2| Fn8  |Fn1|
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Fn4           |Gui  |Caps|
     *       `-------------------------------------------'
     */
    [0] = \
    KEYMAP(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV, \
           FN9, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   FN3, QUOT,FN6, \
           FN7, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, FN2, FN8,FN1, \
                LALT,LGUI,          FN4,                RGUI, CAPS),

    /* Layer 1: HHKB mode[HHKB Fn]
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow|Shift |   |
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Space         |Gui  |Alt|
     *       `-------------------------------------------'
     */
    [1] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS, UP,  NO,  BSPC, \
           LCTL,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,ENT, \
           LSFT,NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,RSFT,TRNS, \
                LALT,LGUI,          SPC,                RGUI,RALT),

    /* Layer 2: Mouse mode(HJKL)[Slash]
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |MwL|MwD|McU|MwU|MwR|Wbk|Wfr|Alt-T|
     * |-----------------------------------------------------------|
     * |Contro|   |   |   |   |   |Mb2|McL|McD|McR|Fn |   |Return  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |Mb3|Mb2|Mb1|Mb4|Mb5|   |Shift |   |
     * `-----------------------------------------------------------'
     *      |Alt |Gui  |          Mb1          |Fn   |Fn |
     *      `--------------------------------------------'
     * Mc: Mouse Cursor / Mb: Mouse Button / Mw: Mouse Wheel8
     */
    [2] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  HOME, F11, F12, INS, DEL, \
           FN8, NO,  NO,  NO,  NO,  NO,  WH_L,WH_D,MS_U,WH_U,WH_R,WBAK,WFWD,FN8, \
           LCTL,ACL0,ACL1,ACL2,ACL2,NO,  MS_L,MS_D,MS_U,MS_R,NO,NO,  ENT, \
           LSFT,NO,  NO,  NO,  NO,  BTN3,BTN2,BTN1,BTN4,BTN5,TRNS, RSFT,NO, \
                LALT,LGUI,          BTN1,                TRNS,TRNS),

    /* Layer 3: Vi mode + media[Semicolon]
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|Hom|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |Hom|WRD|Up |PgU|End|Hom|F12|PgUlEnd|   |   |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|Stp|Ply|Prv|Nxt|   |Lef|Dow|Up |Rig|   |   |Return  |
     * |-----------------------------------------------------------|
     * |Shift   |   |DEL|   |   |BCK|Hom|PgD|PgUlEnd|Fn0|Shift |   |
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |          Space        |Gui  |Alt|
     *       `-------------------------------------------'
     */
    [3] = \
    KEYMAP(GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           TAB, HOME,FN20,UP,  PGUP,END, HOME, F12,PGUP,END, NO,  NO,  NO,  BSPC, \
           LCTL,MSTP, MPLY,MPRV,MNXT,NO,  LEFT,DOWN,UP,  RGHT,TRNS,  NO,  ENT, \
           LSFT,NO, DEL,  NO,  NO,FN21,  HOME,PGDN,PGUP,END, NO,RSFT,NO, \
                LALT,LGUI,          SPC,                RGUI,RALT),

    /* Layer 4: Matias half-qwerty keyboard style[Space]
     * ,-----------------------------------------------------------.
     * |  -|  0|  9|  8|  7|  6|  5|  4|  3|  2|  1|   |   |   |Esc|
     * |-----------------------------------------------------------|
     * |Backs|  P|  O|  I|  U|  Y|  T|  R|  E|  W|  Q|   |   |Tab  |
     * |-----------------------------------------------------------|
     * |Contro|  ;|  L|  K|  J|  H|  G|  F|  D|  S|  A|Con|Control |
     * |-----------------------------------------------------------|
     * |Shift   |  /|  .|  ,|  M|  N|  B|  V|  C|  X|  Z|Shift |   |
     * `-----------------------------------------------------------'
     *      |Gui |Alt  |          Fn0          |Alt  |Gui|
     *      `--------------------------------------------'
     */
    [4] = \
    KEYMAP(MINS,0,   9,   8,   7,   6,   5,   4,   3,   2,   1,   NO,  NO,  NO,  ESC, \
           BSPC,P,   O,   I,   U,   Y,   T,   R,   E,   W,   Q,   NO,  NO,  TAB, \
           LCTL,SCLN,L,   K,   J,   H,   G,   F,   D,   S,   A,   RCTL,RCTL, \
           LSFT,SLSH,DOT, COMM,M,   N,   B,   V,   C,   X,   Z,   RSFT,NO, \
                LGUI,LALT,          TRNS,               RALT,RGUI),

    /* Layer 5: Numpad with Tab Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|   |   |   |   |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |  4|  5|  6|BACKS|  [|  ]|   |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |  1|  2|  3|ENT|  '|Fn6     |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  0|  0|  ,|  .|Fn2|Shift |Fn1|
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    [5] = \
    KEYMAP(ESC ,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,TRNS,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   4,   5,   6,BSPC,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   1,   2,   3, ENT,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   0,   0,   COMM,DOT,TRNS,TRNS,TRNS, \
                TRNS,TRNS,            TRNS,                TRNS,TRNS),
};



/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
    RSHIFT_RPAREN,
};

enum macro_id {
    VOLUP,
    ALT_TAB,
    VI_WORD,
    VI_BACK,
};


/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
    [1] = ACTION_LAYER_TAP_TOGGLE(1),                 // HHKB layer(toggle with 5 taps)
    [2] = ACTION_LAYER_TAP_KEY(2, KC_SLASH),          // Cursor layer with Slash*
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),           // Mousekey layer with Semicolon*
    [4] = ACTION_LAYER_TAP_KEY(4, KC_SPC),            // Matias layer with Space
    [5] = ACTION_MACRO(ALT_TAB),                      // Application switching
    [6] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),      // RControl with tap Enter
    [7] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),           // Function: LShift with tap '('
    [8] = ACTION_FUNCTION_TAP(RSHIFT_RPAREN),         // RShift with tap ')'
    [9] = ACTION_LAYER_TAP_KEY(5, KC_TAB),
//  [10] = ACTION_MODS_ONESHOT(MOD_RSFT),              // Oneshot Shift

//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),        // LControl with tap Backspace
//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),         // LControl with tap Esc
    [20] = ACTION_MACRO(VI_WORD),                          // Macro: vi navigation 'w'
    [21] = ACTION_MACRO(VI_BACK),                          // Macro: vi navigation 'b'
};


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        //case HELLO:
            //return (record->event.pressed ?
                    //MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    //MACRO_NONE );
        case VOLUP:
            return (record->event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), U(LALT), END ));
        case VI_WORD:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(RGHT), END ) :
                    MACRO( U(RGHT), U(LCTL), END ));
        case VI_BACK:
            return (record->event.pressed ?
                    MACRO( D(LCTL), D(LEFT), END ) :
                    MACRO( U(LEFT), U(LCTL), END ));
    }
    return MACRO_NONE;
}



/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");

    switch (id) {
        case LSHIFT_LPAREN:
            // Shift parentheses example: LShft + tap '('
            // http://stevelosh.com/blog/2012/10/a-modern-space-cadet/#shift-parentheses
            // http://geekhack.org/index.php?topic=41989.msg1304899#msg1304899
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_LSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            break;
        case RSHIFT_RPAREN:
            // Shift parentheses example: RShft + tap ')'
            // http://stevelosh.com/blog/2012/10/a-modern-space-cadet/#shift-parentheses
            // http://geekhack.org/index.php?topic=41989.msg1304899#msg1304899
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_RSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_RSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    register_code(KC_0);
                    unregister_code(KC_0);
                    del_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_RSHIFT));
                }
            }
            break;
    }
}
