#ifndef _INTERFACE_CMD_H_
#define _INTERFACE_CMD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define CMD_MAX_LIST 20
#define CMD_MAX_CHAR 100

typedef struct
{
  char gcode[CMD_MAX_CHAR];
  uint8_t port_index;  // 0: for SERIAL_PORT, 1: for SERIAL_PORT_2 etc...
} GCODE;

typedef struct
{
  GCODE   queue[CMD_MAX_LIST];
  uint8_t index_r;  // Ring buffer read position
  uint8_t index_w;  // Ring buffer write position
  uint8_t count;    // Count of commands in the queue
} GCODE_QUEUE;

extern GCODE_QUEUE infoCmd;
extern GCODE_QUEUE infoCacheCmd;

bool isFullCmdQueue(void);      // condition callback for loopProcessToCondition()
bool isNotEmptyCmdQueue(void);  // condition callback for loopProcessToCondition()
bool isEnqueued(const char *cmd);

bool storeCmd(const char * format,...);
void mustStoreCmd(const char * format,...);
void mustStoreScript(const char * format,...);
bool storeCmdFromUART(uint8_t portIndex, const char * gcode);
void mustStoreCacheCmd(const char * format,...);
bool moveCacheToCmd(void);
void clearCmdQueue(void);
void sendQueueCmd(void);

#ifdef __cplusplus
}
#endif

#endif
