/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * UVC protocol handling
 *
 * Copyright (C) 2010-2018 Laurent Pinchart
 *
 * Contact: Laurent Pinchart <laurent.pinchart@ideasonboard.com>
 */

#ifndef __UVC_H__
#define __UVC_H__

struct events;
struct v4l2_device;
struct uvc_device;
struct uvc_function_config;
struct uvc_stream;

struct uvc_device *uvc_open(const char *devname, struct uvc_stream *stream);
void uvc_close(struct uvc_device *dev);
void uvc_events_init(struct uvc_device *dev, struct events *events);
void uvc_set_config(struct uvc_device *dev, struct uvc_function_config *fc);
int uvc_set_format(struct uvc_device *dev, struct v4l2_pix_format *format);
struct v4l2_device *uvc_v4l2_device(struct uvc_device *dev);


/* UVC commands */
#define UVC_EU_PROGRAM_AFE                 0x01
#define UVC_EU_PROGRAM_AFE_SET_TX_SIZE     0x02
#define UVC_EU_DUMMY_RQST                  0x03
#define UVC_EU_READ_AFE_REG                0x04
#define UVC_EU_SET_READ_ADDR               0x05
#define UVC_EU_SET_FPS                     0x06
#define UVC_EU_PROGRAM_SENSOR_RAM          0x07
#define UVC_EU_START_SENSOR                0x08
#define UVC_EU_PWR_MON                     0x09
#define UVC_EU_SENSOR_FLASH                0x0A
#define UVC_EU_I2C                         0x0B
#define UVC_EU_GPIO                        0x0C
#define UVC_EU_MODULE_I2C                  0x0D
#define UVC_EU_GET_FRAME                   0x0E
#define UVC_EU_FLASH_CE                    0x0F
#define UVC_EU_FLASH_SET_GET_CMD           0x10
#define UVC_EU_SYNC_MODE                   0x11
#define UVC_EU_FW_UPDATE                   0x12
#define UVC_EU_MIO_TRI_CTRL                0x13
#define UVC_EU_GET_VER_NUM                 0x14
#define UVC_EU_GET_GIT_COMMIT_ID           0x15


#endif /* __UVC_H__ */
