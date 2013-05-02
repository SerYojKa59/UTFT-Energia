// *** Hardwarespecific functions ***
#define portOutputRegister(x)	(regtype)portBASERegister(x)

void UTFT::_hw_special_init()
{
	sbi(P_CS, B_CS);
	sbi(P_RS, B_RS);
	sbi(P_WR, B_WR);
}

inline void write_byte_lo(unsigned char ch)
{
/*
	digitalWrite(PB_0, ch & 0x01);
	digitalWrite(PB_1, ch & 0x02);
	digitalWrite(PB_2, ch & 0x04);
	digitalWrite(PB_3, ch & 0x08);
	digitalWrite(PB_4, ch & 0x10);
	digitalWrite(PB_5, ch & 0x20);
	digitalWrite(PB_6, ch & 0x40);
	digitalWrite(PB_7, ch & 0x80);
*/
	ROM_GPIOPinWrite(GPIO_PORTB_BASE, 0xff, ch);
}

inline void write_byte_hi(unsigned char ch)
{
	ROM_GPIOPinWrite(GPIO_PORTF_BASE, BV(2) | BV(3), (ch & 0x03) << 2);
	ROM_GPIOPinWrite(GPIO_PORTD_BASE, BV(2) | BV(3), (ch & 0x0c));
	ROM_GPIOPinWrite(GPIO_PORTE_BASE, BV(0) | BV(1) | BV(2) | BV(3), (ch & 0xf0) >> 4); 

/*
	digitalWrite(PF_2, ch & 0x01);
	digitalWrite(PF_3, ch & 0x02);

	digitalWrite(PD_2, ch & 0x04);
	digitalWrite(PD_3, ch & 0x08);

	digitalWrite(PE_0, ch & 0x10);
	digitalWrite(PE_1, ch & 0x20);
	digitalWrite(PE_2, ch & 0x40);
	digitalWrite(PE_3, ch & 0x80);
*/
}

void UTFT::LCD_Writ_Bus(char VH,char VL, byte mode)
{   
	switch (mode)
	{
	case 1:
		if (display_serial_mode==SERIAL_4PIN)
		{
		if (VH==1)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		}
		else
		{
		if (VH==1)
			sbi(P_RS, B_RS);
		else
			cbi(P_RS, B_RS);
		}

		if (VL & 0x80)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x40)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x20)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x10)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x08)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x04)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x02)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		if (VL & 0x01)
			sbi(P_SDA, B_SDA);
		else
			cbi(P_SDA, B_SDA);
			pulse_low(P_SCL, B_SCL);
		break;
	case 8:
		write_byte_lo(VH);
		pulse_low(P_WR, B_WR);
		write_byte_lo(VL);
		pulse_low(P_WR, B_WR);
		break;
	case 16:
		write_byte_hi(VH);
		write_byte_lo(VL);
		pulse_low(P_WR, B_WR);
		break;
	case LATCHED_16:
		asm("nop");		// Mode is unsupported
		break;
	}
}

void UTFT::_set_direction_registers(byte mode)
{
	if (mode!=LATCHED_16)
	{
		pinMode(PB_0, OUTPUT);
		pinMode(PB_1, OUTPUT);
		pinMode(PB_2, OUTPUT);
		pinMode(PB_3, OUTPUT);
		pinMode(PB_4, OUTPUT);
		pinMode(PB_5, OUTPUT);
		pinMode(PB_6, OUTPUT);
		pinMode(PB_7, OUTPUT);

		if (mode == 16) {
			pinMode(PF_2, OUTPUT);
			pinMode(PF_3, OUTPUT);
			pinMode(PD_2, OUTPUT);
			pinMode(PD_3, OUTPUT);
			pinMode(PE_0, OUTPUT);
			pinMode(PE_1, OUTPUT);
			pinMode(PE_2, OUTPUT);
			pinMode(PE_3, OUTPUT);
		}
	}
}

void UTFT::_fast_fill_16(int ch, int cl, long pix)
{
	long blocks;

	write_byte_lo(cl);
	write_byte_hi(ch);

	blocks = pix/16;
	for (int i=0; i<blocks; i++)
	{
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
		pulse_low(P_WR, B_WR);
	}
	if ((pix % 16) != 0)
		for (int i=0; i<(pix % 16); i++)
		{
			pulse_low(P_WR, B_WR);
		}
}

void UTFT::_fast_fill_8(int ch, long pix)
{
	long blocks;
	write_byte_lo(ch);

	blocks = pix/16;
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
		for (int i=0; i<(pix % 16); i++)
		{
			pulse_low(P_WR, B_WR);pulse_low(P_WR, B_WR);
		}
}
