//////////////////////////////////////
//
// LFTools Console
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"

int console()
{
    #ifdef CONSOLE
    // check for first run
    char *home = getenv("HOME");
    char path[PATH_LENGTH];
    FILE *fp;
    snprintf(path, sizeof(path), "%s/.lftools/confirstrun", home);
    if (access(path, F_OK) != 0) {
        if ((fp = fopen(path, "w")) == NULL) {
            printf(DIRERR "\n");
            abort();
        }
        fclose(fp);
        printf("ALERT: You have started LFTools without any arguments.\n");
        printf("Running LFTools without arguments will, by default, start the console interface.\n");
        printf("If this is by mistake, you can carry on with your day.\n");
        printf("Otherwise, run [./lftools] again to enter the console.\n");
        exit(0);
    }
    char cmd[1024];
    printf("You are now in the LFTools console. Type 'help' for a list of commands.\n");
    while (1) {
        printf("> ");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0; // get rid of the dumbass newline
        if (strcmp(cmd, "quit") == 0) {
            exit(0);
        }
        if (strcmp(cmd, "help") == 0) {
            printf("Available commands:\n");
            printf("  quit             Exit the console\n");
            printf("  help             Show this help message\n");
            printf("  mount            Mount a device\n");
            printf("  eject            Eject a device\n");
            printf("  send             Send a custom CDB\n");
            printf("For console-specific commands, type 'console.help'.\n");
        }
        if (strcmp(cmd, "console.help") == 0) {
            printf("Console-specific commands:\n");
            printf("  console.help     Show this help message\n");
            printf("  console.clear    Clear the console\n");
        }
        if (strcmp(cmd, "console.clear") == 0) {
            printf("\033[2J\033[1;1H");
        }
        if (strcmp(cmd, "mount") == 0) {
            printf("From the list below, select a device to mount.\n");
            snprintf(cmd, sizeof(cmd), "sg_scan -i");
            system(cmd);
            printf("mount> ");
            fgets(cmd, sizeof(cmd), stdin);
            cmd[strcspn(cmd, "\n")] = 0; // get rid of the dumbass newline
            if (strcmp(cmd, "back") == 0) {
                continue;
            }
        }
    }
    #else
    printf("The console is not enabled.\n");
    exit(0);
    #endif
}