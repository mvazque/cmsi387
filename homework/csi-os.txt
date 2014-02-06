Csi-os
All of the images related to this part of this assignment
are located in the folder title csi-os_images.
The images are all titled similarly
"os" - mac,windows,linux
"os"_first_process.png
"os"_kernel.png
"os"_network.png
"os"_preOS.jpg (note the linux version is in .png format)
"os"_startUp_scripts.png

Linux files
first_process.png -- ps -p 1 shows the processes and -p option allows a specific process to be shown, in this case 1 representing the first process

kernel.png -- For this part three different commands were found that provided similar information. uname prints system information with -r representing the kernel and -a all.

network.png -- There is a button at the top right of the screen on the wired version it is the two arrows pointing in opposite directions which is where the mouse pointer is located in the screenshot.

preOS.png -- There is a directory title boot that contains files that start when the system is booted up. By using ls to see the files while inside the directory they were found.

startUp_scripts.png -- The directory /etc is said to contain the configure files which are connected to start up. The directory was changed to the directory and grep was used to find only the files containing .conf for configure.

Mac files

first_process.png -- ps -p 1 This command represents showing the processes by their process id and only the first is called for.

kernel.png -- the kernel file was found within directory / and is the file titled mach_kernel.

network -- For the network settings the wifi signal can be clicked on and then by selecting the network settings option.

preOS.jpg -- While the computer is starting up if command + v is selected the Verbose boot information will be displayed

startUp_scritps.png -- These files are located within the preferences directory and can be viewed by usage of ls.

Windows files

first_process.png -- By going to the \ directory and using the tasklist command will print tasks but fi will find and display the task dictated by the string.

kernel.png -- The directory System32 contains the kernel file. dir will print the contents of the directory and findstr will narrow it to print only contents that contain the string that is specified.

network.png -- Going through control panel and then selecting Network and Internet will show the network settings

preOS.jpg -- Pressing F2 while it boots up will allow access to what is shown in the image.

startUp_scripts.png -- There is a startup directory that contains the files used when starting up the computer. They were directed by using the dir command.
