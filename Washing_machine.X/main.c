/*
 * File:   main.c
 * Author: Shredan Abdullah
 *
 * Created on March 16, 2024, 3:50 PM
 */


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "timers.h"
#include "clcd.h"

#pragma config WDTE = OFF

void init_config(void){
    init_digital_keypad();
    init_clcd();
}

void power_on_screen(void){
    /*to print BLOCK*/
    for (unsigned char i=0;i<16;i++){
         clcd_putch(BLOCK, LINE1(i));
    } 
   
    clcd_print("Powering ON",  LINE2(2));
    clcd_print("Washing Machine",  LINE3(1));
    
    /*to print BLOCK*/
    for (unsigned char i=0;i<16;i++){
         clcd_putch(BLOCK, LINE4(i));
    } 
    /*delay*/
    __delay_ms(1000);
    
    clear_screen();

    
}
void main(void) {
    init_config(); 
    do{
         clcd_print("Press key5 To", LINE1(1));
         clcd_print("Power ON", LINE2(4));
         clcd_print("Washing Machine", LINE3(1));
    }while(read_digital_keypad(STATE)!=SW5); 
    
    
//         clcd_print("Press key5 To", LINE1(1));
//         clcd_print("Power ON", LINE2(4));
//         clcd_print("Washing Machine", LINE3(1));
//    
//         while(read_digital_keypad(STATE)!=SW5){
//               /*delay*/
////               for (unsigned int wait = 1000;wait--;);
//              __delay_us(1000);
//         }
    clear_screen();
    power_on_screen();
    
   
    
    while(1){
     clcd_print("Washing program", LINE3(1));
    }
    return;
}

