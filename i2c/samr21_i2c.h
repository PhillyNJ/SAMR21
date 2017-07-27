/*
 * samr21_i2c.h
 *
 * Created: 7/27/2017 7:59:21 AM
 *  Author: pvallone
 */ 


#ifndef SAMR21_I2C_H_
#define SAMR21_I2C_H_

#include <asf.h>

#define I2C_TIMEOUT			1000

struct i2c_master_packet scan_packet;
struct i2c_master_packet write_packet;
struct i2c_master_packet read_packet;
struct i2c_master_module i2c_master_instance;

uint8_t read_buffer[9];
uint8_t write_buffer[9];


void samr21_i2c_scan(void);
void samr21_configure_i2c(void);
void samr21_configure_i2c_callbacks(void);
void samr21_i2c_write_complete_callback(struct i2c_master_module *const module);




#endif /* SAMR21_I2C_H_ */