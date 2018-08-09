# UTFT-Energia

This is a port of Henning Karlsen's 
[UTFT library](http://www.rinkydinkelectronics.com/) to Energia Launchpads
and ESP32.

### Stellaris
Tested on S6D1121 in 8-bit mode and SSD1289 in 16-bit mode.
(Update: now pin-compatible with Daniel Rebollo's boosterpack. See
[here](
http://forum.stellarisiti.com/topic/626-ssd1289-32-320x240-tft-16bit-parallel-interface-touch-libraries/).)

* 8-bit mode:
D0-D7=GND; D8-D15=PD0-3, PA4-7; RS=PC_6; WR=PC_5; CS=PC_7; RST=PC_4; RD=Pullup.

* 16-bit mode:
D0-D7=PB0-PB7; D8-D15=PD0-3, PA4-7; RS=PC_6; WR=PC_5; CS=PC_7; RST=PC_4; RD=Pullup.

### Fraunchpad
* 8-bit mode:
D0-D7=GND; D8-D15=P1.0-P1.7; RS=P2.0; WR=P2.5; CS=P2.6; RST=P2.1; RD=Pullup.

### Launchpad
* 8-bit mode:
D0-D7=GND; D8-D15=P2.0-P2.7; RS=P1.4; WR=P1.5; CS=P1.6; RST=P1.7; RD=Pullup.

### ESP32
* 8-bit mode: D0-D7=23,22,21,19,18,17,16,4; RS=32; WR=33; CS=25; RST=26; RD=Pullup.

# License
[CC BY-NC-SA 3.0](https://github.com/andresv/UTFT-Energia/blob/master/License%20-%20CC%20BY-NC-SA%203.0%20-%20Legal.pdf)
