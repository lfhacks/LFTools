//////////////////////////////////////
//
// LFTools Main Program
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"
// istg if i have to touch objective-c i will lose it

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
        printf("  -p               Package manager (only downloading)\n");
        printf("  --update-didj    Update Didj (unimplemented)\n");
        printf("Device Types:\n");
        printf("  1                Didj\n");
        printf("  2                Leapster2\n");
        printf("Package Manager Options:\n");
        printf("  download <name>  Download package by name\n");
        printf("For example, to mount a Leapster2:\n");
        printf("  ./lftools -m 2\n");
        printf("For more information, read the README.md file.\n");
        // man page never
        return 0;
    }
    if (strcmp(argv[1], "-m") == 0) {
        if (argc < 3) {
            printf(MISSDEV "\n");
            exit(1);
        }
        while (1) {
            mountDevice(atoi(argv[2]));
        }
    }
    if (strcmp(argv[1], "-x") == 0) {
        if (argc < 3) {
            printf(MISSDEV "\n");
            exit(1);
        }
        while (1) {
            ejectDevice(atoi(argv[2]));
        }
    }
    if (strcmp(argv[1], "-p") == 0) {
        if (argc < 3) {
            printf(MISSPARG "\n");
            exit(1);
        }
        if (argc < 4) {
            printf(MISSPKG "\n");
            exit(1);
        }
        if (strcmp(argv[2], "download") == 0) {
            dlPkg(argv[3]);
        }
    }
    if (strcmp(argv[1], "--update-didj") == 0) {
        printf("WARNING: You are intentionally doing something potentially harmful to your Didj.\n");
        printf("Please plug your Didj into the wall (or load it with fresh batteries) to ensure the update is not interrupted.\n");
        printf("Would you like to proceed? (y/N): ");
        
    }
    return 0;
}