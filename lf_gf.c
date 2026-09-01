//////////////////////////////////////
//
// LFTools General Functions
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

// this could've been a header but idrc

#include "lf_def.h"

void waitForUserInput(char *wfuiGet)
{
    fgets(wfuiGet, sizeof(wfuiGet), stdin);
    wfuiGet[strcspn(wfuiGet, "\n")] = 0; // get rid of the dumbass newline
}