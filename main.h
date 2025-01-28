
#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "clcd.h"
#include "adc.h"
#include "mkp.h"
#include "ext_eeprom.h"
#include "uart.h"
#include "ds1307.h"
#include "i2c.h"


typedef enum{
    e_view_log,   
    e_download_log,
    e_clear_log,
    e_set_time,
    e_dashboard,
    e_menu        
};

void car_menu();
void dashboard();
void view_log();
void clear_log();
void download_log();
void set_time();
#endif	/* MAIN_H */

