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
            doMntChk(1);
            printf("Scanning for device...\n");
            // windows command
            FILE *fp = popen("sg_scan.exe | findstr Didj", "r");
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
            // remove anything after the first space (we should just be left with a PD#)
            path[strcspn(path, " ")] = 0;
            pclose(fp);
            printf("Found Didj!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            snprintf(cmd, sizeof(cmd), "sg_raw.exe %s C2 00 00 00 00 00 00 00 00 00 > nul 2>&1", path);
            system(cmd);
            printf("Mounted!\n");
            placeMntFile();
            exit(0);
        }
        case 2: { // Leapster2
            doMntChk(1);
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan.exe | findstr 2-SD", "r");
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
            path[strcspn(path, " ")] = 0;
            printf("Found Leapster2!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            snprintf(cmd, sizeof(cmd), "sg_raw.exe %s C2 00 00 00 00 00 00 00 00 00 > nul 2>&1", path);
            system(cmd);
            printf("Mounted!\n");
            placeMntFile();
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
            doMntChk(2);
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan.exe | findstr Didj", "r");
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
            path[strcspn(path, " ")] = 0;
            printf("Found Didj!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            snprintf(cmd, sizeof(cmd), "sg_raw.exe %s C6 00 00 00 00 00 00 00 00 00 > nul 2>&1", path);
            system(cmd);
            printf("Ejected!\n");
            removeMntFile();
            exit(0);
        }
        case 2: { // Leapster2
            doMntChk(2);
            printf("Scanning for device...\n");
            FILE *fp = popen("sg_scan.exe | findstr 2-SD", "r");
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
            path[strcspn(path, " ")] = 0;
            printf("Found Leapster2!\n");
            // send CDB to device
            char cmd[PATH_LENGTH + 64];
            snprintf(cmd, sizeof(cmd), "sg_raw.exe %s C6 00 00 00 00 00 00 00 00 00 > nul 2>&1", path);
            system(cmd);
            printf("Ejected!\n");
            removeMntFile();
            exit(0);

        }
        default:
            printf("Unknown device type!\n");
            exit(1);
    }
}

void doMntChk(int typeChk)
{
    switch(typeChk) {
        case 1: { // mount
            char *home = getenv("USERPROFILE");
            if (home == NULL) {
                printf(HOMEERR "\n");
                abort();
            }
            char path[PATH_LENGTH];
            snprintf(path, sizeof(path), "%s\\lftools\\mount", home);
            if (access(path, F_OK) != 0) {
                return; // okay, proceed with mounting
            }
            printf(ALMNT "\n");
            exit(1);
        }
        case 2: { // eject
            char *home = getenv("USERPROFILE");
            if (home == NULL) {
                printf(HOMEERR "\n");
                abort();
            }
            char path[PATH_LENGTH];
            snprintf(path, sizeof(path), "%s\\lftools\\mount", home);
            if (access(path, F_OK) == 0) {
                return; // okay, proceed with ejecting
            }
            printf(EJERR "\n");
            exit(1);
        }
        default:
            printf("Missing type\n");
            exit(1);
    }
}

void placeMntFile()
{
    char *home = getenv("USERPROFILE");
    if (home == NULL) {
        printf(HOMEERR "\n");
        abort();
    }
    char path[PATH_LENGTH];
    snprintf(path, sizeof(path), "%s\\lftools\\mount", home);
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        printf(FILERR "\n");
        exit(1);
    }
    fclose(fp);
}

void removeMntFile()
{
    char *home = getenv("USERPROFILE");
    if (home == NULL) {
        printf(HOMEERR "\n");
        abort();
    }
    char path[PATH_LENGTH];
    snprintf(path, sizeof(path), "%s\\lftools\\mount", home);
    if (access(path, F_OK) != 0) {
        return; // file doesn't exist, nothing to do
    }
    if (remove(path) != 0) {
        printf(FILERR "\n");
        exit(1);
    }
}
// crammer support maybe in the future? it'd only be for music management though
