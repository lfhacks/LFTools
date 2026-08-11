//////////////////////////////////////
//
// LFPkg (macOS) Download Manager
//
// 2026 by Ian Mathews / awes145
//
//////////////////////////////////////

#include "lf_def.h"

// list of synonyms for game names to link to package id
char *L2Pkgs[][3] = {
    {"dragon", "Dragon Kingdom", "LSTR-0x00010011-000000"}, // dragon kingdom
    {"chicken", "Chicken Coop", "LSTR-0x0013000A-000000"}, // chicken coop
    {"rabbit", "Rabbit River", "LSTR-0x0013000B-000000"}, // rabbit river
    {"shape", "Shape Shop", "LSTR-0x0013000C-000000"}, // shape shop
    {"number", "Number Raiders", "LSTR-0x00130002-000000"}, // number raiders
    {"letter", "Letterpillar", "LSTR-0x00130003-000000"}, // letterpillar
    {"b-dragon", "UK Dragon Kingdom", "LSTR-0x00130013-000000"}, // dragon kingdom
    {"b-chicken", "UK Chicken Coop", "LSTR-0x00130010-000000"}, // chicken coop
    {"b-rabbit", "UK Rabbit River", "LSTR-0x00130011-000000"}, // rabbit river
    {"b-shape", "UK Shape Shop", "LSTR-0x00130012-000000"}, // shape shop
    {"b-number", "UK Number Raiders", "LSTR-0x00130004-000000"}, // number raiders
    {"b-letter", "UK Letterpillar", "LSTR-0x00130005-000000"}, // letterpillar
    {"sdmenu-old", "SDMenu 1.0.2", "LSTR-0x00130001-000000"}, // SDMenu
    {"sdmenu", "SDMenu 1.0.0.2", "LSTR-0x00130006-000000"}, // SDMenu (new)
    {"badapple", "Bad Apple", "LSTR-0x00001337-000000"}, // bad apple
    {"dmpster-ei", ".DMPSTER (Early-LF Icon)", "LSTR-0x00FE0002-000000"}, // cart/bios dump tool
    {"dmpster-ni", ".DMPSTER (New-LF Icon)", "LSTR-0x00FE0001-000000"}, // cart/bios dump tool
    {NULL, NULL}
};

void dlPkg(char *pkg) {
char *pkgid = NULL;
char *pkgname = NULL;
    for (int i = 0; L2Pkgs[i][0] != NULL; i++) {
        if (strcmp(pkg, L2Pkgs[i][0]) == 0) {
            pkgid = L2Pkgs[i][2];
            pkgname = L2Pkgs[i][1];
            break;
        }
    }
    if (pkgid == NULL) {
        printf("Package not found: %s\n", pkgname);
        return;
    }
    char url[256];
    printf("Downloading package: %s (ID: %s)\n", pkgname, pkgid);
    snprintf(url, sizeof(url), "curl -L -O https://archive.org/download/lstr-0x-00010011-000000/%s.lfp", pkgid);
    system(url);
}