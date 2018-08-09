// *** Hardwarespecific defines ***
#define cbi(reg, bitmask) HWREG((uint32_t)reg + 0x3FC) &= ~bitmask
#define sbi(reg, bitmask) HWREG((uint32_t)reg + 0x3FC) |= bitmask
#define pulse_high(reg, bitmask) sbi(reg, bitmask); cbi(reg, bitmask);
#define pulse_low(reg, bitmask) cbi(reg, bitmask); sbi(reg, bitmask);

#define swap(type, i, j) {type t = i; i = j; j = t;}

#define fontbyte(x) cfont.font[x]  

#if !defined(pgm_read_word)
#define pgm_read_word(data) *data
#endif
#define bitmapdatatype unsigned short*

#define regtype volatile uint32_t
#define regsize uint8_t
