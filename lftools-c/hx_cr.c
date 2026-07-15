//////////////////////////////////////
//
// LFTools Crash Handler
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"

void crashHandler(int sig)
{
    switch(sig) {
        case SIGSEGV:
            printf("Segmentation violation\nLFTools will now close.");
            break;
        case SIGABRT:
            printf("Abnormal program termination\nLFTools will now close.");
            break;
        case SIGFPE:
            printf("Floating point implosion\nLFTools will now close.");
            break;
        case SIGILL:
            printf("Illegal instruction\nLFTools will now close.");
            break;
        case SIGPIPE:
            printf("Pipe stalled\nLFTools will now close.");
            break;
        default:
            printf("unimplemented\nLFTools will now close.");
            break;
    }
}