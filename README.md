# UTFT-Energia

This is [Energia](https://github.com/energia/Energia) port of the Henning Karlsen's [UTFT library](http://henningkarlsen.com/electronics/library.php?id=52).
Currently it is meant for [custom MSP430FR5739](https://github.com/andresv/industrial-switcher/tree/master/hardware/pcb) based board. However with simple modifications it can be ported to Fraunchpad, Launchpad and other boards that are able to use Energia.

Tips about porting it to different platforms can be found [here](http://andresvahter.wordpress.com/2013/04/07/how-to-add-energia-support-to-utft-library/).

## Ported to Stellaris by Stephen Crane. 
Tested on S6D1211 in 8-bit mode and SSD1289 in 16-bit mode.

* 8-bit mode:
D0-D7=GND; D8-D15=PE0-3+PC4-7; RS=PA_5; WR=PA_7; CS=PA_6; RST=PD_6; 
RD=VREF; VCC=VREF.

* 16-bit mode:
D0-D7=PB0-PB7; D8-D15=PE0-3+PC4-7; RS=PA_5; WR=PA_7; CS=PA_6; RST=PD_6; 
RD=VREF; VCC=VREF.

## Modified (from andersv's version) for stock Fraunchpad:
* 8-bit mode:
D0-D7=GND; D8-D15=P1.0-P1.7; RS=P2.0; WR=P2.5; CS=P2.6; RST=P2.1; 
RD=VCC; VCC=VCC

# License
[CC BY-NC-SA 3.0](https://github.com/andresv/UTFT-Energia/blob/master/License%20-%20CC%20BY-NC-SA%203.0%20-%20Legal.pdf)
