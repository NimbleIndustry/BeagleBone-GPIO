#ifndef _AM335X_H_
#define _AM335X_H_

#define MMAP_OFFSET (0x44E0F000)
#define MMAP_SIZE   (0x481AEFFF-MMAP_OFFSET)

#define GPIO_REGISTER_SIZE (4)

#define GPIO0 		(0x44E07000)
#define GPIO1		(0x4804C000)
#define GPIO2		(0x481AC000)
#define GPIO3		(0x481AE000)

#define GPIO_CLEARDATAOUT (0x190)
#define GPIO_SETDATAOUT   (0x194)
#define GPIO_OE			  (0x134)

typedef struct s_PWM {
	char muxmode; /*!< mux mode, 0-7, see am335x technical manual */
	char *name;   /*!< name of pwm pin, i.e.: "EHRPWM2B" */
	char *path;   /*!< path to the pwm, i.e.: "ehrpwm.2:1" */
} PWM;

typedef struct s_PIN {
	char *name;   /*!< readable name of pin, i.e.: "GPIO1_21", see beaglebone user guide */
	unsigned int gpio_bank; /*!< which of the four gpio banks is this pin in, i.e.: GPIO1, r 0x4804C000 */
	uint8_t gpio; /*!< pin number on the am335x processor */
	uint8_t bank_id; /*!< pin number within each bank, should be 0-31 */
	char *mux;    /*!< file name for setting mux */
	uint8_t eeprom; /*!< position in eeprom */
	unsigned char pwm_present; /*!< whether or not this pin can be used for PWM */
	PWM pwm;      /*!< pwm struct if pwm_present is true */

} PIN;

#define TRUE 1
#define FALSE 0

#define USR0  ((PIN){	"GPIO1_21",	   GPIO1,     0,   21,   "",				0,     FALSE, 0   })
#define USR1  ((PIN){	"GPIO1_22",	   GPIO1,     0,   22,   "",				0,     FALSE, 0   })
#define USR2  ((PIN){	"GPIO1_23",	   GPIO1,     0,   23,   "",				0,     FALSE, 0   })
#define USR3  ((PIN){	"GPIO1_24",	   GPIO1,     0,   24,   "",				0,     FALSE, 0   })
#define P8_3  ((PIN){   "GPIO1_6",	   GPIO1,     38, 	6,	 "gpmc_ad6",        26,    FALSE, 0   })
#define P8_4  ((PIN){   "GPIO1_7",     GPIO1,     39, 	7,	 "gpmc_ad7",        27,    FALSE, 0   })
#define P8_5  ((PIN){   "GPIO1_2",     GPIO1,     34, 	2,	 "gpmc_ad2",        22,    FALSE, 0   })
#define P8_6  ((PIN){   "GPIO1_3",     GPIO1,     35, 	3,	 "gpmc_ad3",        23,    FALSE, 0   })
#define P8_7  ((PIN){   "TIMER4",      GPIO2,     66, 	2, 	 "gpmc_advn_ale",   41,    FALSE, 0   })
#define P8_8  ((PIN){   "TIMER7",      GPIO2,     67, 	3,	 "gpmc_oen_ren",    44,    FALSE, 0   })
#define P8_9  ((PIN){   "TIMER5",      GPIO2,     69, 	5,	 "gpmc_ben0_cle",   42,    FALSE, 0   })
#define P8_10 ((PIN){   "TIMER6",      GPIO2,     68, 	4,	 "gpmc_wen",        43,    FALSE, 0   })
#define P8_11 ((PIN){   "GPIO1_13",    GPIO1,     45, 	13,	 "gpmc_ad13",       29,    FALSE, 0   })
#define P8_12 ((PIN){   "GPIO1_12",    GPIO1,     44, 	12,	 "gpmc_ad12",       28,    FALSE, 0   })
#define P8_13 ((PIN){   "EHRPWM2B",    GPIO0,     23, 	23,	 "gpmc_ad9",        15,    TRUE,  (PWM){4, "EHRPWM2B", "ehrpwm.2:1"}})
#define P8_14 ((PIN){   "GPIO0_26",    GPIO0,     26, 	26,	 "gpmc_ad10",       16,    FALSE, 0   })
#define P8_15 ((PIN){   "GPIO1_15",    GPIO1,     47, 	15,	 "gpmc_ad15",       31,    FALSE, 0   })
#define P8_16 ((PIN){   "GPIO1_14",    GPIO1,     46, 	14,	 "gpmc_ad14",       30,    FALSE, 0   })
#define P8_17 ((PIN){   "GPIO0_27",    GPIO0,     27, 	27,	 "gpmc_ad11",       17,    FALSE, 0   })
#define P8_18 ((PIN){   "GPIO2_1",     GPIO2,     65, 	1,	 "gpmc_clk",        40,    FALSE, 0   })
#define P8_19 ((PIN){   "EHRPWM2A",    GPIO0,     22, 	22,	 "gpmc_ad8",        14,    TRUE,  (PWM){4, "EHRPWM2A", "ehrpwm.2:0"}})
#define P8_20 ((PIN){   "GPIO1_31",    GPIO1,     63, 	31,	 "gpmc_csn2",       39,    FALSE, 0   })
#define P8_21 ((PIN){   "GPIO1_30",    GPIO1,     62, 	30,	 "gpmc_csn1",       38,    FALSE, 0   })
#define P8_22 ((PIN){   "GPIO1_5",     GPIO1,     37, 	5,	 "gpmc_ad5",        25,    FALSE, 0   })
#define P8_23 ((PIN){   "GPIO1_4",     GPIO1,     36, 	4,	 "gpmc_ad4",        24,    FALSE, 0   })
#define P8_24 ((PIN){   "GPIO1_1",     GPIO1,     33, 	1,	 "gpmc_ad1",        21,    FALSE, 0   })
#define P8_25 ((PIN){   "GPIO1_0",     GPIO1,     32, 	0,	 "gpmc_ad0",        20,    FALSE, 0   })
#define P8_26 ((PIN){   "GPIO1_29",    GPIO1,     61, 	29,	 "gpmc_csn0",       37,    FALSE, 0   })
#define P8_27 ((PIN){   "GPIO2_22",    GPIO2,     86, 	22,	 "lcd_vsync",       57,    FALSE, 0   })
#define P8_28 ((PIN){   "GPIO2_24",    GPIO2,     88, 	24,	 "lcd_pclk",        59,    FALSE, 0   })
#define P8_29 ((PIN){   "GPIO2_23",    GPIO2,     87, 	23,	 "lcd_hsync",       58,    FALSE, 0   })
#define P8_30 ((PIN){   "GPIO2_25",    GPIO2,     89, 	25,	 "lcd_ac_bias_en",  60,    FALSE, 0   })
#define P8_31 ((PIN){   "UART5_CTSN",  GPIO0,     10, 	10,	 "lcd_data14",       7,    FALSE, 0   })
#define P8_32 ((PIN){   "UART5_RTSN",  GPIO0,     11, 	11,	 "lcd_data15",       8,    FALSE, 0   })
#define P8_33 ((PIN){   "UART4_RTSN",  GPIO0,     9,  	9,	 "lcd_data13",       6,    FALSE, 0   })
#define P8_34 ((PIN){   "UART3_RTSN",  GPIO2,     81, 	17,	 "lcd_data11",      56,    TRUE,  (PWM){2, "EHRPWM1B", "ehrpwm.1:1"}})
#define P8_35 ((PIN){   "UART4_CTSN",  GPIO0,     8,  	8,	 "lcd_data12",       5,    FALSE, 0   })
#define P8_36 ((PIN){   "UART3_CTSN",  GPIO2,     80, 	16,	 "lcd_data10",      55,    TRUE,  (PWM){2, "EHRPWM1A", "ehrpwm.1:0"}})
#define P8_37 ((PIN){   "UART5_TXD",   GPIO2,     78, 	14,	 "lcd_data8",       53,    FALSE, 0   })
#define P8_38 ((PIN){   "UART5_RXD",   GPIO2,     79, 	15,	 "lcd_data9",       54,    FALSE, 0   })
#define P8_39 ((PIN){   "GPIO2_12",    GPIO2,     76, 	12,	 "lcd_data6",       51,    FALSE, 0   })
#define P8_40 ((PIN){   "GPIO2_13",    GPIO2,     77, 	13,	 "lcd_data7",       52,    FALSE, 0   })
#define P8_41 ((PIN){   "GPIO2_10",    GPIO2,     74, 	10,	 "lcd_data4",       49,    FALSE, 0   })
#define P8_42 ((PIN){   "GPIO2_11",    GPIO2,     75, 	11,	 "lcd_data5",       50,    FALSE, 0   })
#define P8_43 ((PIN){   "GPIO2_8",     GPIO2,     72, 	8,	 "lcd_data2",       47,    FALSE, 0   })
#define P8_44 ((PIN){   "GPIO2_9",     GPIO2,     73, 	9,	 "lcd_data3",       48,    FALSE, 0   })
#define P8_45 ((PIN){   "GPIO2_6",     GPIO2,     70, 	6,	 "lcd_data0",       45,    TRUE,  (PWM){3, "EHRPWM2A", "ehrpwm.2:0"}})
#define P8_46 ((PIN){   "GPIO2_7",     GPIO2,     71, 	7,	 "lcd_data1",       46,    TRUE,  (PWM){3, "EHRPWM2B", "ehrpwm.2:1"}})

#define INPUT    ((unsigned char)(1))
#define OUTPUT   ((unsigned char)(0))
#define PULLUP   ((unsigned char)(1))
#define PULLDOWN ((unsigned char)(0))
#define DISABLED ((unsigned char)(2))




#endif