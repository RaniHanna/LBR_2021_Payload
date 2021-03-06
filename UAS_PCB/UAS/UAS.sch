EESchema Schematic File Version 4
LIBS:UAS-cache
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev "1"
Comp ""
Comment1 "Design for JLCPCB 1-2 Layer Service"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L UAS-rescue:500mA-5V-Converter-UAS-cache U3
U 1 1 60360C06
P 6100 2650
F 0 "U3" H 6100 2725 50  0000 C CNN
F 1 "500mA-5V-Converter" H 6100 2634 50  0000 C CNN
F 2 "UAS:Pololu_5V_500mA_Step_Down_Regulator" H 6100 2750 50  0001 C CNN
F 3 "" H 6100 2750 50  0001 C CNN
	1    6100 2650
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:7.5V-2.4A-Converter-UAS-cache U1
U 1 1 60361E55
P 6100 3250
F 0 "U1" H 6100 3315 50  0000 C CNN
F 1 "7.5V-2.4A-Converter" H 6100 3224 50  0000 C CNN
F 2 "UAS:Pololu_7.75V_2.4A_Step_Down_Regulator" H 6100 3350 50  0001 C CNN
F 3 "" H 6100 3350 50  0001 C CNN
	1    6100 3250
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:TB6612FNG-Dual-Motor-Driver-UAS-cache U5
U 1 1 60364756
P 6150 4150
F 0 "U5" H 6150 4226 50  0000 C CNN
F 1 "TB6612FNG-Dual-Motor-Driver" H 6150 4135 50  0000 C CNN
F 2 "UAS:Pololu_TB6612_Dual_Motor_Driver_Carrier" H 6150 4250 50  0001 C CNN
F 3 "" H 6150 4250 50  0001 C CNN
	1    6150 4150
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:SM02B-PASS-TBT(LF)(SN)-SM02B-PASS-TBT_LF__SN_ J1
U 1 1 60366780
P 4850 2150
F 0 "J1" H 5080 2146 50  0000 L CNN
F 1 "SM02B-PASS-TBT(LF)(SN)" H 5080 2055 50  0000 L CNN
F 2 "JST_SM02B-PASS-TBT(LF)(SN)" H 4850 2150 50  0001 L BNN
F 3 "" H 4850 2150 50  0001 L BNN
F 4 "N/A" H 4850 2150 50  0001 L BNN "PARTREV"
F 5 "JST" H 4850 2150 50  0001 L BNN "MANUFACTURER"
F 6 "Manufacturer Recommendations" H 4850 2150 50  0001 L BNN "STANDARD"
F 7 "5.7 mm" H 4850 2150 50  0001 L BNN "MAXIMUM_PACKAGE_HEIGHT"
	1    4850 2150
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:12V-StepUp-Converter-UAS-cache U4
U 1 1 60363213
P 6100 3700
F 0 "U4" H 6100 3776 50  0000 C CNN
F 1 "12V-StepUp-Converter" H 6100 3685 50  0000 C CNN
F 2 "UAS:Pololu_12V_Step_Up_Voltage_Regulator" H 6100 3800 50  0001 C CNN
F 3 "" H 6100 3800 50  0001 C CNN
	1    6100 3700
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:5A-5V-Converter-UAS-cache U2
U 1 1 6035F82F
P 6100 1950
F 0 "U2" H 6075 2025 50  0000 C CNN
F 1 "5A-5V-Converter" H 6075 1934 50  0000 C CNN
F 2 "UAS:Pololu_5V_5A_Step_Down_Regulator" H 6100 1950 50  0001 C CNN
F 3 "" H 6100 1950 50  0001 C CNN
	1    6100 1950
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:JST-3-Pin-UAS-cache U?
U 1 1 6035FF82
P 4150 2900
F 0 "U?" H 4150 2975 50  0000 C CNN
F 1 "JST-3-Pin" H 4150 2884 50  0000 C CNN
F 2 "" H 4150 3000 50  0001 C CNN
F 3 "" H 4150 3000 50  0001 C CNN
	1    4150 2900
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:JST-4-Pin-UAS-cache U?
U 1 1 60360427
P 4900 3150
F 0 "U?" H 4900 3225 50  0000 C CNN
F 1 "JST-4-Pin" H 4900 3134 50  0000 C CNN
F 2 "" H 4900 3250 50  0001 C CNN
F 3 "" H 4900 3250 50  0001 C CNN
	1    4900 3150
	1    0    0    -1  
$EndComp
$Comp
L UAS-rescue:JST-7-Pin-UAS-cache U?
U 1 1 6036088A
P 4450 3850
F 0 "U?" H 4450 3925 50  0000 C CNN
F 1 "JST-7-Pin" H 4450 3834 50  0000 C CNN
F 2 "" H 4450 3950 50  0001 C CNN
F 3 "" H 4450 3950 50  0001 C CNN
	1    4450 3850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
