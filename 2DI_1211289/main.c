#include <stdio.h>
#include <stdlib.h>

#include "device_info.h"
#include "device_max.h"
#include "global_max.h"

int main() {
  int x = 3;
  device_info *devices = malloc(sizeof(device_info)*x);

  devices[0].id = 1;
  devices[0].n_readings = 3;
  unsigned int readings1[] = { 0xc009180f, 0xc010f001, 0xc018c805 };
  devices[0].dev_readings = readings1;

  devices[1].id = 2;
  devices[1].n_readings = 2;
  unsigned int readings2[] = { 0x8009401e, 0x80096820 };
  devices[1].dev_readings = readings2;

  devices[2].id = 3;
  devices[2].n_readings = 1;
  unsigned int readings3[] = { 0x00105003 };
  devices[2].dev_readings = readings3;

  for (int i = 0; i < x; i++)
  {
    printf("global_max(devices, x, 1) = %d\n", global_max(devices, x, 1));
    printf("global_max(devices, x, 2) = %d\n", global_max(devices, x, 2));
  }

  free(devices);
  
  return 0;
}
