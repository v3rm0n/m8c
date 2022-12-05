// Copyright 2021 Jonne Kokkonen
// Released under the MIT licence, https://opensource.org/licenses/MIT

// Contains portions of code from libserialport's examples released to the
// public domain

#include <SDL2/SDL_log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "serial.h"


static int detect_m8_serial_device(struct sp_port *port) {
//TODO:
  return 0;
}

// Checks for connected devices and whether the specified device still exists
int check_serial_port(struct sp_port *m8_port) {

  int device_found = 0;

  return device_found;

}

struct sp_port *init_serial(int verbose) {
  /* A pointer to a null-terminated array of pointers to
   * struct sp_port, which will contain the ports found.*/
  struct sp_port *m8_port = NULL;
  return (m8_port);
}

