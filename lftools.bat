@echo off
echo LF Tools
echo Developed by Awesome_neos145
echo Version: v1.0
echo ----------------------------
if not exist .\sg_raw.exe goto rawerror
if not exist .\sg_scan.exe goto scanerror
:main
echo What would you like to do?
echo (1) Mount Device
echo (2) Lock Device
echo (3) Eject Device
echo (4) Quit
set /p menu="Choose: "
if %menu%==1 goto mount
if %menu%==2 goto lock
if %menu%==3 goto eject
if %menu%==5 goto quit
:mount
.\sg_scan.exe
echo Find and type the ID of your Leapster2 or Didj in the terminal. If an error shows, run LF Tools as an administrator.
set /p lfid="ID: "
.\sg_raw.exe %lfid% C2 00 00 00 00 00 00 00 00 00
echo Your Didj or Leapster2 has been mounted. Make desired changes in the filesystem, then eject here.
goto main
:lock
.\sg_scan.exe
echo Find and type the ID of your Leapster2 or Didj in the terminal. If an error shows, run LF Tools as an administrator.
set /p lfid="ID: "
.\sg_raw.exe %lfid% C1 00 00 00 00 00 00 00 00 00
echo Your Didj or Leapster2 has been locked. To make more changes, re-mount the device here.
goto main
:eject
.\sg_scan.exe
echo Find and type the ID of your Leapster2 or Didj in the terminal. If an error shows, run LF Tools as an administrator.
set /p lfid="ID: "
.\sg_raw.exe %lfid% C6 00 00 00 00 00 00 00 00 00
echo Your Didj or Leapster2 has been ejected. Unplug, and then reboot your device.
goto quit
:rawerror
echo Required executable "sg_raw.exe" cannot be found! This executable is required to execute commands on your Leapster2 or Didj. Please redownload LF Tools, and try again.
goto quit
:scanerror
echo Required executable "sg_scan.exe" cannot be found! This executable is required for you to find your Leapster2 or Didj. Please redownload LF Tools, and try again.
goto quit
:quit
set menu=0
set lfid=0