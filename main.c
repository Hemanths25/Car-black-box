#include "main.h"
char time[9] = "00:00:00";

void init_config(){
    init_clcd();
    init_adc();
    init_mkp();
    init_uart();
    init_i2c();
    init_ds1307();
}

char k,s_f,state = e_dashboard,key;
void car_menu(){
    char menu[][17]={"View log    ","Download log","Clear log   ","Set time    "};
    if(k<3){
      clcd_print(menu[k],LINE1(2));
      clcd_print(menu[k+1],LINE2(2));  
    }
     
    if(s_f == 0)
    {
        clcd_print("*",LINE1(0));
        clcd_print(" ",LINE2(0));
    }
    else
    {
        clcd_print(" ",LINE1(0));
        clcd_print("*",LINE2(0));
    }
    
    if(key == SW2){
        if(s_f == 0)
        s_f = 1;
        else if(k<2)
        k++;
    }
    else if(key == SW1){
        if(s_f == 1)
        s_f = 0;
        else if(k>0)
        k--;
    }
    if(key == SW4){
        CLEAR_DISP_SCREEN;
        if(k+s_f == 0) state = e_view_log;
        else if(k+s_f == 1) state = e_download_log;
        else if(k+s_f == 2) state = e_clear_log;
        else if(k+s_f == 3) state = e_set_time;
    }
    else if(key == SW5){
        CLEAR_DISP_SCREEN;
        state = e_dashboard;
    }
}

void main(void) {  
    init_config();
    
    while(1){
        key = read_matrix_keypad(STATE);
        switch(state){
        case e_dashboard : dashboard(); 
        break;
        case e_menu : car_menu();
        break; 
        case e_view_log : view_log();
        break;
        case e_download_log : download_log();
        break;
        case e_clear_log : clear_log();
        break;
        case e_set_time : set_time();
        break;
    }
  }
}
