# bemxOS
bemxOS (pronounced "bemsh-OS" but people pronounce it wrongly as "bem-x-OS" and other people get to be pedantic and correct those people) is a little operating system created by me (bemxio!), just for learning OS development.

Based on [this](https://github.com/cfenollosa/os-tutorial) cool tutorial. If you want to make your own OS, you should follow that tutorial too!

I plan to add network support and all of the other cool stuff later on, don't expect it soon though.
For now, it will probably just have a few basic commands with a basic filesystem as well.

## Running
Before trying to run anything, make sure to obtain an image file of the system.

You can either get it from [here](https://github.com/bemxio/bemxos/releases), or you can just compile it yourself.

### VirtualBox
1. Open VirtualBox and press the `New` button with a blue icon.
2. Name the virtual machine however you want, set the type to `Other` and the version to `Other/Unknown`.
3. After pressing `Next`, choose `Do not add a virtual hard disk`. On the warning message box, press `Continue`.
4. Select the virtual machine from the list, and press `Settings`.
5. Go to the `Storage` window, select the `Controller: IDE` controller and delete it using the small buttons at the bottom of the list.
6. Add a new controller and choose `I82078 (Floppy)`.
7. Select the `Controller: Floppy` controller and press the floppy disk icon with a plus on the highlighted controller.
8. In the pop-up window, press `Leave Empty`.
9. Click on the `Empty` button on the list.
10. Click the floppy disk next to the `Floppy Drive 0` text, and from the dropdown menu, select `Choose a disk file...`.
11. Select the image file you downloaded (or compiled yourself) out from GitHub and confirm the file choice.
12. Press `OK` to save all of the settings.

After doing all of the setup, bemxOS should boot up correctly after pressing the `Start` button.

### QEMU
Just simply run the `image.img` file within the command line with the following command:
```
qemu-system-i386 -fda image.img
```

## Building
You will need some prerequisites before you start compiling the system:

- a Linux host system (if you are on Windows, WSL will do the job)
- a GCC cross-compiler (feel free to follow [this](https://github.com/cfenollosa/os-tutorial/blob/master/11-kernel-crosscompiler/README.md) tutorial for steps on how to compile one yourself)
- (optionally) QEMU, for testing the system
- (optionally) GCC, for debugging it

1. Export some global environment variables:
    - `CC_PATH`, that points to the directory path of your cross-compiler.
    - (optionally) `QEMU_PATH`, that points to the QEMU directory. (for Windows peeps, install QEMU on Windows and point to it in WSL, where `/mnt/c/` is `C:\`)
    - (optionally) `GDB_PATH`, that points to the GDB **executable**. (for Windows peeps, it's the same as with QEMU)

2. Clone the repository using `git`, and use `cd` to change the current directory.
3. Just run the `make` command, and it should work!

It should produce a `bemxOS.bin` file at the end, that you can launch with QEMU.

If you want to clean all of the mess the compilers made, you can run `make clean` to quickly get rid of all of the files.

### Debugging
If you set up the `QEMU_PATH` and `GDB_PATH` environment variables, you can use `make debug` to compile the code and run it inside of a debugging session in GDB.

You can also do `make run`, if you just want to run it, although you still need `QEMU_PATH` to be set up.

## Contributions
Feel free to point out any mistakes or issues you've found while using this little thing!

Anything from a simple question to a pull request is really appreciated!
