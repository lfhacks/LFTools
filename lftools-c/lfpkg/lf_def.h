//////////////////////////////////////
//
// LFPkg (macOS) Header
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

#include "foreign.h"

void dlPkg(char *pkg);

#define VERSION "1.0"
#define PATH_LENGTH 1024

// LFPkg (macOS) by awes145