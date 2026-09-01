//////////////////////////////////////
//
// LFTools Device Manager
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"


void mountDevice(int deviceType)
{
    switch(deviceType) {
        case 1: { // Didj
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan -i 2>/dev/null | grep -B 1 Didj | head -n 1 | tr -d ' ' | cut -d ':' -f 1", "r");
            if (fp == NULL) {
                printf(SCANERR "\n");
                exit(1);
            }
            char path[PATH_LENGTH];
            if (fgets(path, sizeof(path), fp) == NULL) {
                printf(CONNERR "\n");
                pclose(fp);
                exit(1);
            }
            pclose(fp);
            path[strcspn(path, "\n")] = 0;
            printf("Found device!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            snprintf(cmd, sizeof(cmd), "sg_raw %s C2 00 00 00 00 00 00 00 00 00", path);
            system(cmd);
            printf("Mounted Didj!\n");
            exit(0);
        }
        case 2: { // Leapster2
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan -i 2>/dev/null | grep -B 1 SD | head -n 1 | tr -d ' ' | cut -d ':' -f 1", "r");
            if (fp == NULL) {
                printf(SCANERR "\n");
                exit(1);
            }
            char path[PATH_LENGTH];
            if (fgets(path, sizeof(path), fp) == NULL) {
                printf(CONNERR "\n");
                pclose(fp);
                exit(1);
            }
            pclose(fp);
            path[strcspn(path, "\n")] = 0;
            printf("Found device!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            printf("running command: %s\n", cmd);
            snprintf(cmd, sizeof(cmd), "sg_raw %s C2 00 00 00 00 00 00 00 00 00", path);
            system(cmd);
            printf("Mounted Leapster2!\n");
            exit(0);
        }
        default:
            printf("Unknown device type!\n");
            exit(1);
    }
}

void ejectDevice(int deviceType)
{
    switch(deviceType) {
        case 1: { // Didj
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan -i 2>/dev/null | grep -B 1 Didj | head -n 1 | tr -d ' ' | cut -d ':' -f 1", "r");
            if (fp == NULL) {
                printf(SCANERR "\n");
                exit(1);
            }
            char path[PATH_LENGTH];
            if (fgets(path, sizeof(path), fp) == NULL) {
                printf(CONNERR "\n");
                pclose(fp);
                exit(1);
            }
            pclose(fp);
            path[strcspn(path, "\n")] = 0;
            printf("Found device!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            snprintf(cmd, sizeof(cmd), "sg_raw %s C6 00 00 00 00 00 00 00 00 00", path);
            system(cmd);
            printf("Ejected Didj!\n");
            exit(0);
        }
        case 2: { // Leapster2
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan -i 2>/dev/null | grep -B 1 SD | head -n 1 | tr -d ' ' | cut -d ':' -f 1", "r");
            if (fp == NULL) {
                printf(SCANERR "\n");
                exit(1);
            }
            char path[PATH_LENGTH];
            if (fgets(path, sizeof(path), fp) == NULL) {
                printf(CONNERR "\n");
                pclose(fp);
                exit(1);
            }
            pclose(fp);
            path[strcspn(path, "\n")] = 0;
            printf("Found device at: %s\n", path);
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            printf("running command: %s\n", cmd);
            snprintf(cmd, sizeof(cmd), "sg_raw %s C6 00 00 00 00 00 00 00 00 00", path);
            system(cmd);
            printf("Ejected Leapster2!\n");
            exit(0);
        }
        default:
            printf("Unknown device type!\n");
            exit(1);
    }
}

// crammer support maybe in the future? it'd only be for music management though