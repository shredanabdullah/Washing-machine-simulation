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


/*initially operation mode WASHING PROGRAM */
unsigned char operation_mode= WASHING_PROGRAM_DISPLAY;
unsigned char reset_flag= 0 ;
unsigned char program_num= 0 ;
unsigned char* washing_prog[]={"Daily", "Heavy" , "Dedicates", "Whites", "Stainwash" , "Eco cottons", "Woolens" , "Bed sheets", "Rinse+Dry" , "Dry only","Wash only" , "Aqua store"}; 

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

void washing_program_display(unsigned char key){
    //code to be only first time when function called 
    if(reset_flag==WASHING_PROGRAM_DISPLAY_RESET) {
        
        clear_screen();
        program_num = 0;
    
    }
     
    /*to check if SW4 is pressed increment the index of program*/
    if(key==SW4){
        program_num++;
        clear_screen();
        if(program_num==12){
             program_num = 0;
        }
    }
    
    clcd_print("Washing Programs",  LINE1(0));
    clcd_print("*",  LINE2(0)); 
  if(program_num<=9){
      
    clcd_print(washing_prog[program_num],LINE2(2));
    clcd_print(washing_prog[program_num+1],LINE3(2));
    clcd_print(washing_prog[program_num+2],LINE4(2));
  }
  else if(program_num==10) {
     
      clcd_print(washing_prog[program_num],LINE2(2));
      clcd_print(washing_prog[program_num+1],LINE3(2));
      clcd_print(washing_prog[0],LINE4(2));
  }
  else if(program_num==11) {
     
      clcd_print(washing_prog[program_num],LINE2(2));
      clcd_print(washing_prog[0],LINE3(2));
      clcd_print(washing_prog[1],LINE4(2));
  }
}

void main(void) {
    init_config(); 
    unsigned char key = read_digital_keypad(STATE);
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
        
        key = read_digital_keypad(STATE);
        
        switch(operation_mode){
            case WASHING_PROGRAM_DISPLAY: washing_program_display(key); break;
//            case:break;
//            case:break;
//            case:break;
        
        }
        reset_flag=RESET_NOTHING;
    // clcd_print("Washing program", LINE3(1));
    }
    return;
}

