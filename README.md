# LFTools
Utilities to easily mount/eject Didj and Leapster2 devices, while also being able to manage the filesystem.

# How to Install
You will need to pick the correct version for your system, which can be found in the releases tab. LFTools is available for Linux and Windows.

A hard prerequisite for all versions is that you must have `sg3-utils` installed.

It can be installed by:
## Debian/Ubuntu based distributions:
```
sudo apt install sg3-utils
```
## RedHat/Fedora:
```
sudo dnf install sg3_utils
```
## Arch Linux:
```
sudo pacman -S sg3_utils
```

# Compiling from Source
There are prerequisites for compiling LFTools from source:
## Linux
### Debian/Ubuntu based distributions:
```
sudo apt install build-essential git sg3-utils
```
### RedHat/Fedora:
```
sudo dnf groupinstall "Development Tools"
sudo dnf install git sg3_utils
```
### Arch Linux:
```
sudo pacman -S base-devel git sg3_utils
```
### Compiling
```
git clone https://github.com/lfhacks/LFTools.git
cd LFTools/Linux
make
```
## Windows
To compile on Windows, you may either use [MSYS2](https://msys2.org) or [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/).
### MSYS2
```
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-git
git clone https://github.com/lfhacks/LFTools.git
cd LFTools/Win
make
```
### Dev-C++
Load the .dev project in Dev-C++ and go to Execute -> Rebuild All. If the build fails, you may need to remove "collect2.exe" from Dev-C++'s files. It's usually located under "C:\Dev-Cpp\libexec\gcc\mingw32\3.4.2\collect2.exe".

# wen eta macOS?
macOS support is very limited, and because the default LeapFrog Connect kernel extension is Intel-only, it causes a massive compatibility shift with most recent Macs.

If you have a Mac and want to use LFTools, you can use a virtual machine software like VMware Fusion paired with an ARM-based Linux distribution. Or if you prefer some other OS over macOS, you can try out Asahi Linux.

Intel Macs may gain support in the future, but it's not a priority right now.

TL;DR: No, but Intel Maybe.

# Commands:
## Mounting/Ejecting
-m: mount device (requires device type)
-x: eject device (requires device type)

## Package Management
-p: package management

## Miscellaneous:
--update-didj: ...

-h: help

# Features Completed
[X]Basic Mounting/Ejecting

[X]Package Downloader

[-]Package Utilities

[-]Resetting Didj

[-]Other mumbo jumbo I can't come up with right now

# License
This project is licensed under [GPL v3.0](https://github.com/lfhacks/LFTools?tab=GPL-3.0-1-ov-file).
