#ifndef DEVICE_INFO_H
#define DEVICE_INFO_H
typedef struct {
  int id;
  short temp_max, hum_max, press_max;
  unsigned char n_readings;
  unsigned int *dev_readings;
} device_info;
#endif
