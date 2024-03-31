/* 
 * File:   main.h
 * Author: Shredan Abdullah
 *
 * Created on March 16, 2024, 3:52 PM
 */

#ifndef MAIN_H
#define	MAIN_H


#define WASHING_PROGRAM_DISPLAY                             0x01
#define WATCH_LEVEL                                         0x02
#define START_STOP_SCREEN                                   0x03
#define START_PROGRAM                                       0x04
#define PAUSE                                               0x05


#define WASHING_PROGRAM_DISPLAY_RESET                       0x10

#define RESET_NOTHING                                       0x00
 
 void power_on_screen(void);
 void washing_program_display(unsigned char key);

#endif	/* MAIN_H */

