//////////////////////////////////////
//
// LFTools Main Program
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"

int doDepsChk()
{
    // check if "sginfo" is present in the system, which should confirm sg3_utils is installed
    FILE *fp = popen("which sginfo 2>/dev/null", "r");
    if (fp == NULL) {
        printf(DEPSERR2 "\n");
        abort();
    }

    char path[PATH_LENGTH];
    if (fgets(path, sizeof(path), fp) == NULL) {
        printf(DEPSERR "\n");
        return 1;
    }
    pclose(fp);
    return 0;
}

int doDirChk()
{
    // check if "~/.lftools" folder exists, if not, create it
    char *home = getenv("HOME");
    if (home == NULL) {
        printf(HOMEERR "\n");
        abort();
    }
    char path[PATH_LENGTH];
    snprintf(path, sizeof(path), "%s/.lftools", home);
    if (access(path, F_OK) != 0) {
        printf(FIRSTRUN "\n");
        if (mkdir(path, 0700) != 0) {
            printf(DIRERR "\n");
            abort();
        }
        printf("Done! Run [./lftools -h] to view usage information.\n");
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (doDepsChk() == 1) {
        // bruh
        exit(0);
    }
    printf("LFTools v%s\n", VERSION);
    printf("--------------------------\n");
    doDirChk();

    // parse command line arguments
    if (argc < 2) {
        printf("Usage: \"./lftools <switch>\"\n");
        printf("Run \"./lftools -h\" for help.\n");
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("Usage: \"./lftools <switch>\"\n");
        printf("Commands:\n");
        printf("  -h               Show this help message\n");
        printf("  -m               Mount device\n");
        printf("  -x               Eject device\n");
        printf("  -p               Package manager (unimplemented)\n");
        printf("  --update-didj    Update Didj (unimplemented)\n");
        printf("Device Types:\n");
        printf("  1                Didj\n");
        printf("  2                Leapster2\n");
        printf("For example, to mount a Leapster2:\n");
        printf("  ./lftools -m 2\n");
        printf("For more information, read the README.md file.\n");
        return 0;
    }
    if (strcmp(argv[1], "-m") == 0) {
        if (argc < 3) {
            printf("Missing device type!\n");
            exit(1);
        }
        while (1) {
            mountDevice(atoi(argv[2]));
        }
    }
    if (strcmp(argv[1], "-x") == 0) {
        if (argc < 3) {
            printf("Missing device type!\n");
            exit(1);
        }
        while (1) {
            ejectDevice(atoi(argv[2]));
        }
    }
    return 0;
}