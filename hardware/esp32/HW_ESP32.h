// 8-bit mode
// #define DB0	23
// #define DB1	22
// #define DB2	21//13
// #define DB3	19
// #define DB4	18
// #define DB5	17
// #define DB6	16
// #define DB7	4

#define DB0	13
#define DB1	15
#define DB2	2
#define DB3	0
#define DB4	4
#define DB5	16
#define DB6	17
#define DB7	5

void UTFT::_hw_special_init()
{
}

static inline void _char(char c) {
	digitalWrite(DB0, c & 0x01);
	digitalWrite(DB1, c & 0x02);
	digitalWrite(DB2, c & 0x04);
	digitalWrite(DB3, c & 0x08);
	digitalWrite(DB4, c & 0x10);
	digitalWrite(DB5, c & 0x20);
	digitalWrite(DB6, c & 0x40);
	digitalWrite(DB7, c & 0x80);
}

void UTFT::LCD_Writ_Bus(char VH, char VL, byte mode)
{
	switch(mode) {
	case 8:
		_char(VH);
		pulse_low(P_WR, B_WR);
		_char(VL);
		pulse_low(P_WR, B_WR);
		break;
	default:
		Serial.print("LCD_Writ_Bus ");
		Serial.println(mode);
	}
}

void UTFT::LCD_Write_Bus_8(char VL)
{
	Serial.println("LCD_Writ_Bus_8");
}

void UTFT::_set_direction_registers(byte mode)
{
	if (mode == 8) {
		pinMode(DB0, OUTPUT);
		pinMode(DB1, OUTPUT);
		pinMode(DB2, OUTPUT);
		pinMode(DB3, OUTPUT);
		pinMode(DB4, OUTPUT);
		pinMode(DB5, OUTPUT);
		pinMode(DB6, OUTPUT);
		pinMode(DB7, OUTPUT);
	}
}

void UTFT::_fast_fill_16(int ch, int cl, long pix)
{
	Serial.println("_fast_fill_16");
}

void UTFT::_fast_fill_8(int ch, long pix)
{
	_char(ch);

	long blocks = pix/16;
	for (int i=0; i<blocks; i++)
	{
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
	}
	if ((pix % 16) != 0)
		for (int i=0; i<(pix % 16)+1; i++)
		{
			pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		}
}
