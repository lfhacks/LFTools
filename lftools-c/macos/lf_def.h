//////////////////////////////////////
//
// LFTools Header
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

// regular includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>
#include <sys/stat.h>

// i have no fucking idea how to use iokit
// i don't have a mac
// i'm just gonna blindly use this and hope it works
#include <iokit/IOKitLib.h>
#include "foreign.h"

int doDepsChk(void);
int doDirChk(void);
void mountDevice(int deviceType);
void ejectDevice(int deviceType);
void dlPkg(char *pkg);

#define VERSION "2.0-alpha1"
#define PATH_LENGTH 1024

// LFTools C rewrite by awes145