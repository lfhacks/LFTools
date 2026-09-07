//////////////////////////////////////
//
// LFTools Main Program
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"

int doMachineCheck()
{
    // bomb out if running on macOS, as various required functions are not available there
    #if (defined(__APPLE__))
        printf(MACERR "\n");
        exit(1);
    #endif
    // same with Linux, as this is Windows-specific
    #if (defined(__linux__))
        printf(LINERR "\n");
        exit(1);
    #endif
    return 0;
}

int doDepsChk()
{
    // simply check for both sg_scan.exe and sg_raw.exe in the cwd
    if (access("sg_raw.exe", F_OK) != 0) {
        printf(RAWERR "\n");
        exit(1);
    }
    if (access("sg_scan.exe", F_OK) != 0) {
        printf(SCNERR "\n");
        exit(1);
    }
    if (access("libsgutils2-2.dll", F_OK) != 0) {
        printf(SGDLLERR "\n");
        exit(1);
    }
    if (access("libwinpthread-1.dll", F_OK) != 0) {
        printf(WINPTHREADERR "\n");
        exit(1);
    }
    if (access("libgcc_s_dw2-1.dll", F_OK) != 0) {
        printf(GCCDLLERR "\n");
        exit(1);
    }
    return 0;
}

int doDirChk()
{
    // get user directory
    char *home = getenv("USERPROFILE");
    if (home == NULL) {
        printf(HOMEERR "\n");
        abort();
    }
    char path[PATH_LENGTH];
    snprintf(path, sizeof(path), "%s\\lftools", home);
    if (access(path, F_OK) != 0) {
        printf(FIRSTRUN "\n");
        if (mkdir(path) != 0) {
            printf(DIRERR "\n");
            abort();
        }
        printf("Done! Run [lftools.exe -h] to view usage information.\n");
        exit(0);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    doMachineCheck();
    doDepsChk();
    doDirChk();
    char didjopt[100]; // buffer for user input
    printf("LFTools v%s\n", VERSION);
    printf("--------------------------\n");
    doDirChk();

    // parse command line arguments
    if (argc < 2) {
        printf("Usage: \"lftools.exe <switch>\"\n");
        printf("Run [lftools.exe -h] for more information.\n");
        exit(1);
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("Usage: \"lftools.exe <switch>\"\n");
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
        printf("  list             List available packages\n");
        printf("To download a package, replace <name> with its Reference ID.\n");
        printf("For example, to mount a Leapster2:\n");
        printf("  lftools.exe -m 2\n");
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
        if (strcmp(argv[2], "download") == 0) {
            if (argc < 4) {
                printf(MISSPKG "\n");
                exit(1);
            }
            dlPkg(argv[3]);
        }
        if (strcmp(argv[2], "list") == 0) {
            lsPkg();
        }
    }
    if (strcmp(argv[1], "--update-didj") == 0) {
        printf("WARNING: You are intentionally doing something potentially harmful to your Didj.\n");
        printf("Please plug your Didj into the wall (or load it with fresh batteries) to ensure the update is not interrupted.\n");
        printf("Would you like to proceed? (y/N): ");
        waitForUserInput(didjopt);
        if (strcmp(didjopt, "y") == 0 || strcmp(didjopt, "Y") == 0) {
            printf("Proceeding with update...\n");
        } else {
            printf("Update cancelled.\n");
            exit(1);
        }
    }
    return 0;
}
// ironically, the Windows version was developed on a Mac mini
