//////////////////////////////////////
//
// LFPkg (macOS) Main Program
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"

int main(int argc, char *argv[])
{
    printf("LFPkg v%s\n", VERSION);
    printf("--------------------------\n");

    // parse command line arguments
    if (argc < 2) {
        printf("Usage: \"./lfpkg <switch>\"\n");
        printf("Run \"./lfpkg -h\" for help.\n");
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("Usage: \"./lfpkg <switch>\"\n");
        printf("Commands:\n");
        printf("  -h               Show this help message\n");
        printf("  -d               Download a package\n");
        printf("  -l               List all packages\n");
        printf("Examples:\n");
        printf("  ./lfpkg -d <name>  Download package by name\n");
        printf("        To download a package, use its Reference\n");
        printf("        ID. The Reference ID for Dragon Kingdom\n");
        printf("        is \"dragon\". Use -l to get a list of\n");
        printf("        packages and their Reference IDs.\n");
        printf("For more information, read the README.md file.\n");
        // man page never
        return 0;
    }
    if (strcmp(argv[1], "-d") == 0) {
        if (argc < 3) {
            printf(MISSPKG "\n");
            exit(1);
        }
        dlPkg(argv[2]);
    }
    if (strcmp(argv[1], "-l") == 0) {
        lsPkg();
    }
    return 0;
}