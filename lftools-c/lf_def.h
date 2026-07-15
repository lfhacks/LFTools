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
#include <signal.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "foreign.h"

int doDepsChk(void);
int doDirChk(void);
void crashHandler(int sig);
void mountDevice(int deviceType);
void ejectDevice(int deviceType);

#define VERSION "2.0-alpha1"
#define PATH_LENGTH 1024

// LFTools C rewrite by awes145