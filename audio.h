#ifndef AUDIO_H
#define AUDIO_H
#ifdef USE_LIBUSB
#include <libusb.h>
#ifdef __ANDROID__
int init_audio(libusb_device_handle *devh, int device_id, int buffer_size);
#else
int init_audio(libusb_device_handle *devh);
#endif
int close_audio(libusb_device_handle *devh);
#endif
#endif
