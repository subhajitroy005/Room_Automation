EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Home Automation Basic Version"
Date "2020-07-13"
Rev "1.0"
Comp "SR005"
Comment1 "Base Board "
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7800 5150 7700 5150
$Comp
L power:GND #PWR0101
U 1 1 5F0DF791
P 7800 5150
F 0 "#PWR0101" H 7800 4900 50  0001 C CNN
F 1 "GND" H 7805 4977 50  0000 C CNN
F 2 "" H 7800 5150 50  0001 C CNN
F 3 "" H 7800 5150 50  0001 C CNN
	1    7800 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 5150 7700 5050
Connection ~ 7700 5050
Wire Wire Line
	7550 5050 7700 5050
Wire Wire Line
	7700 5050 7850 5050
Wire Wire Line
	7850 4750 7850 4600
Wire Wire Line
	7550 4750 7550 4600
$Comp
L Device:C C2
U 1 1 5F0DECE8
P 7850 4900
F 0 "C2" V 7598 4900 50  0000 C CNN
F 1 "22pF" V 7689 4900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 7888 4750 50  0001 C CNN
F 3 "~" H 7850 4900 50  0001 C CNN
	1    7850 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5F0DE508
P 7550 4900
F 0 "C1" V 7298 4900 50  0000 C CNN
F 1 "22pF" V 7389 4900 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 7588 4750 50  0001 C CNN
F 3 "~" H 7550 4900 50  0001 C CNN
	1    7550 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal XT1
U 1 1 5F0DD00C
P 7700 4600
F 0 "XT1" V 7654 4731 50  0000 L CNN
F 1 "Crystal" V 7745 4731 50  0000 L CNN
F 2 "Crystal:Crystal_HC52-U_Vertical" H 7700 4600 50  0001 C CNN
F 3 "~" H 7700 4600 50  0001 C CNN
	1    7700 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5F0E7D76
P 1450 2450
F 0 "C6" H 1300 2550 50  0000 L CNN
F 1 "1000uF" V 1300 2250 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 1488 2300 50  0001 C CNN
F 3 "~" H 1450 2450 50  0001 C CNN
	1    1450 2450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5F0EB453
P 1100 2950
F 0 "#PWR0104" H 1100 2700 50  0001 C CNN
F 1 "GND" H 1105 2777 50  0000 C CNN
F 2 "" H 1100 2950 50  0001 C CNN
F 3 "" H 1100 2950 50  0001 C CNN
	1    1100 2950
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C5
U 1 1 5F0E3C3C
P 1450 2750
F 0 "C5" H 1300 2850 50  0000 L CNN
F 1 "1000uF" V 1300 2550 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 1488 2600 50  0001 C CNN
F 3 "~" H 1450 2750 50  0001 C CNN
	1    1450 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1050 2850 1100 2850
Wire Wire Line
	1100 2850 1100 2950
Wire Wire Line
	1050 2750 1300 2750
Wire Wire Line
	1300 2650 1300 2450
$Comp
L power:GND #PWR0107
U 1 1 5F10C464
P 1750 2600
F 0 "#PWR0107" H 1750 2350 50  0001 C CNN
F 1 "GND" H 1755 2427 50  0000 C CNN
F 2 "" H 1750 2600 50  0001 C CNN
F 3 "" H 1750 2600 50  0001 C CNN
	1    1750 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1600 2750 1750 2750
Wire Wire Line
	1750 2750 1750 2600
Wire Wire Line
	1600 2450 1750 2450
Wire Wire Line
	1750 2450 1750 2600
Connection ~ 1750 2600
Text GLabel 1050 2700 1    50   Input ~ 0
5V-P
Text GLabel 1200 2450 1    50   Input ~ 0
12V-P
Wire Wire Line
	1050 2700 1050 2750
Wire Wire Line
	1050 2650 1200 2650
Wire Wire Line
	1200 2450 1200 2650
Connection ~ 1200 2650
Wire Wire Line
	1200 2650 1300 2650
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 5F0FE4DD
P 7100 3400
F 0 "U1" H 6456 3354 50  0000 R CNN
F 1 "ATmega328P-PU" H 6456 3445 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 7100 3400 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 7100 3400 50  0001 C CNN
	1    7100 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 4000 7600 4350
Wire Wire Line
	7600 4350 7550 4350
Wire Wire Line
	7550 4350 7550 4600
Connection ~ 7550 4600
Wire Wire Line
	7700 4000 7700 4350
Wire Wire Line
	7700 4350 7850 4350
Wire Wire Line
	7850 4350 7850 4600
Connection ~ 7850 4600
$Comp
L Connector:Conn_01x06_Female J2
U 1 1 5F112A42
P 700 1400
F 0 "J2" H 592 875 50  0000 C CNN
F 1 "CAN_Module" H 592 966 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 700 1400 50  0001 C CNN
F 3 "~" H 700 1400 50  0001 C CNN
	1    700  1400
	-1   0    0    1   
$EndComp
Text GLabel 1100 1600 2    50   Input ~ 0
5V-P
$Comp
L power:GND #PWR?
U 1 1 5F1152CF
P 1500 1550
F 0 "#PWR?" H 1500 1300 50  0001 C CNN
F 1 "GND" H 1505 1377 50  0000 C CNN
F 2 "" H 1500 1550 50  0001 C CNN
F 3 "" H 1500 1550 50  0001 C CNN
	1    1500 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  1600 1100 1600
Wire Wire Line
	900  1500 1500 1500
Wire Wire Line
	1500 1500 1500 1550
Text GLabel 1100 1400 2    50   Input ~ 0
CAN_CS
Wire Wire Line
	900  1400 1100 1400
Text GLabel 1100 1300 2    50   Input ~ 0
CAN_SO
Wire Wire Line
	900  1300 1100 1300
Text GLabel 1100 1200 2    50   Input ~ 0
CAN_SI
Wire Wire Line
	900  1200 1100 1200
Text GLabel 1100 1100 2    50   Input ~ 0
CAN_SCK
Wire Wire Line
	900  1100 1100 1100
Text GLabel 8850 3450 2    50   Input ~ 0
5V-P
Wire Wire Line
	8600 3400 8750 3400
Wire Wire Line
	8750 3400 8750 3450
Wire Wire Line
	8750 3450 8850 3450
Wire Wire Line
	8600 3500 8750 3500
Wire Wire Line
	8750 3500 8750 3450
Connection ~ 8750 3450
Text GLabel 8300 2600 1    50   Input ~ 0
5V-P
Wire Wire Line
	8300 2800 8300 2600
$Comp
L Connector:Screw_Terminal_01x02 J5
U 1 1 5F121A0A
P 4150 1100
F 0 "J5" H 4230 1092 50  0000 L CNN
F 1 "Start Button" H 4230 1001 50  0000 L CNN
F 2 "Connector_TE-Connectivity:TE_826576-2_1x02_P3.96mm_Vertical" H 4150 1100 50  0001 C CNN
F 3 "~" H 4150 1100 50  0001 C CNN
	1    4150 1100
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J6
U 1 1 5F1224C8
P 4400 1100
F 0 "J6" H 4480 1092 50  0000 L CNN
F 1 "Stop Button" H 4480 1001 50  0000 L CNN
F 2 "Connector_TE-Connectivity:TE_826576-2_1x02_P3.96mm_Vertical" H 4400 1100 50  0001 C CNN
F 3 "~" H 4400 1100 50  0001 C CNN
	1    4400 1100
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x17_Female J7
U 1 1 5F12452E
P 8900 1000
F 0 "J7" V 9065 980 50  0000 C CNN
F 1 "LCD Module" V 8974 980 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Vertical" H 8900 1000 50  0001 C CNN
F 3 "~" H 8900 1000 50  0001 C CNN
	1    8900 1000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F1289A2
P 5450 3650
F 0 "#PWR?" H 5450 3400 50  0001 C CNN
F 1 "GND" H 5455 3477 50  0000 C CNN
F 2 "" H 5450 3650 50  0001 C CNN
F 3 "" H 5450 3650 50  0001 C CNN
	1    5450 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3650 5450 3400
Wire Wire Line
	5450 3400 5600 3400
$Comp
L Connector:Screw_Terminal_01x02 J8
U 1 1 5F12B15B
P 4950 1100
F 0 "J8" H 5030 1092 50  0000 L CNN
F 1 "RED LED" H 5030 1001 50  0000 L CNN
F 2 "Connector_TE-Connectivity:TE_826576-2_1x02_P3.96mm_Vertical" H 4950 1100 50  0001 C CNN
F 3 "~" H 4950 1100 50  0001 C CNN
	1    4950 1100
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J9
U 1 1 5F12B161
P 5200 1100
F 0 "J9" H 5280 1092 50  0000 L CNN
F 1 "GREEN LED" H 5280 1001 50  0000 L CNN
F 2 "Connector_TE-Connectivity:TE_826576-2_1x02_P3.96mm_Vertical" H 5200 1100 50  0001 C CNN
F 3 "~" H 5200 1100 50  0001 C CNN
	1    5200 1100
	0    -1   -1   0   
$EndComp
Connection ~ 1050 2750
$Comp
L Connector:Screw_Terminal_01x03 J1
U 1 1 5F0E1A22
P 850 2750
F 0 "J1" V 850 2550 50  0000 C CNN
F 1 "POWER IN" V 950 2650 50  0000 C CNN
F 2 "Connector_TE-Connectivity:TE_826576-3_1x03_P3.96mm_Vertical" H 850 2750 50  0001 C CNN
F 3 "~" H 850 2750 50  0001 C CNN
	1    850  2750
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J10
U 1 1 5F1325D5
P 850 3700
F 0 "J10" V 850 3500 50  0000 C CNN
F 1 "POWER OUT" V 950 3600 50  0000 C CNN
F 2 "Connector_TE-Connectivity:TE_826576-3_1x03_P3.96mm_Vertical" H 850 3700 50  0001 C CNN
F 3 "~" H 850 3700 50  0001 C CNN
	1    850  3700
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5F0E5F3C
P 1200 6300
F 0 "J3" H 1280 6292 50  0000 L CNN
F 1 "Safety_Relay" H 1280 6201 50  0000 L CNN
F 2 "Connector_TE-Connectivity:TE_826576-2_1x02_P3.96mm_Vertical" H 1200 6300 50  0001 C CNN
F 3 "~" H 1200 6300 50  0001 C CNN
	1    1200 6300
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5F0E7AE9
P 1200 5850
F 0 "J4" H 1280 5842 50  0000 L CNN
F 1 "Main_Relay" H 1280 5751 50  0000 L CNN
F 2 "Connector_TE-Connectivity:TE_826576-2_1x02_P3.96mm_Vertical" H 1200 5850 50  0001 C CNN
F 3 "~" H 1200 5850 50  0001 C CNN
	1    1200 5850
	-1   0    0    1   
$EndComp
Text GLabel 1200 3700 2    50   Input ~ 0
12V-P
Text GLabel 1200 3600 2    50   Input ~ 0
5V-P
$Comp
L power:GND #PWR?
U 1 1 5F136D1D
P 1200 3850
F 0 "#PWR?" H 1200 3600 50  0001 C CNN
F 1 "GND" H 1205 3677 50  0000 C CNN
F 2 "" H 1200 3850 50  0001 C CNN
F 3 "" H 1200 3850 50  0001 C CNN
	1    1200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3800 1200 3800
Wire Wire Line
	1200 3800 1200 3850
Wire Wire Line
	1200 3700 1050 3700
Wire Wire Line
	1200 3600 1050 3600
$EndSCHEMATC
