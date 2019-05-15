/* The following array is taken from 
 http://www.osdever.net/bkerndev/Docs/keyboard.htm
 All credits where due
*/

// ESC : 1
// CTRL : 29
// MAJ : 42 et 54
// ALT / ALTGR : 56
// VERRMAJ : 56

unsigned char keyboard_map_lower[128] =
{
     0,   0,  '&', 'é', '"',  '\'', '(', '-', 'è', '_',
    'ç', 'à', ')', '=', '\b', '\t', 'a', 'z', 'e', 'r',
    't', 'y', 'u', 'i', 'o',  'p',  '^', '$', '\n', 0,
    'q', 's', 'd', 'f', 'g',  'h',  'j', 'k', 'l', 'm',
    'ù',  0,   0,  '*', 'w',  'x',  'c', 'v', 'b', 'n',
    ',', ';', ':', '!',  0,    0,    0,  ' ',  0,

    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* F1 - F10 keys */
    0, /* 69 - Num lock*/
    0, /* Scroll Lock */
    0, /* Home key */
    0, /* Up Arrow : 72 */
    0, /* Page Up */
    0,
    0, /* Left Arrow: 75 */
    0,
    0, /* Right Arrow : 77 */
    0,
    0, /* 79 - End key*/
    0, /* Down Arrow : 80 */
    0, /* Page Down */
    0, /* Insert Key */
    0, /* Delete Key */
    0, 0, 0,
    0, /* F11 Key */
    0, /* F12 Key */
    0, /* All other keys are undefined */
};


unsigned char keyboard_map_upper[128] =
{
     0,   0,  '1', '2', '3',  '4', '5', '6', '7', '8',
    '9', '0', '°', '+', '\b', '\t', 'A', 'Z', 'E', 'R',
    'T', 'Y', 'U', 'I', 'O',  'P',  '"', '£', '\n', 0,
    'Q', 'S', 'D', 'F', 'G',  'H',  'J', 'K', 'L', 'M',
    '%',  0,   0,  'µ', 'W',  'X',  'C', 'V', 'B', 'N',
    '?', '.', '/', '§',  0,    0,    0,  ' ',  0,

    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* F1 - F10 keys */
    0, /* 69 - Num lock*/
    0, /* Scroll Lock */
    0, /* Home key */
    0, /* Up Arrow : 72 */
    0, /* Page Up */
    0,
    0, /* Left Arrow: 75 */
    0,
    0, /* Right Arrow : 77 */
    0,
    0, /* 79 - End key*/
    0, /* Down Arrow : 80 */
    0, /* Page Down */
    0, /* Insert Key */
    0, /* Delete Key */
    0, 0, 0,
    0, /* F11 Key */
    0, /* F12 Key */
    0, /* All other keys are undefined */
};
