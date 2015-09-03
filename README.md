# CSnake
This is a snake game implemented using C programming language

## Build
### Linux/Unix/MacOS
On these systems, GUI created using libcurses, which should be installed before building.

To install libcurses, on Debian/Ubuntu system, run,
```
$ sudo apt-get update
$ sudo apt-get install libcurses5-dev
```

1. Create a new folder named 'build'
```
$ mkdir build
```
2. Run `$ make`

### Windows

### Other platforms


## Develop
### HOWTO
The game is designed to be easily ported on other system/platforms: Just implement the APIs in src/port/port.c defined in src/port/port.h. Other parts of the game are all platform/system independent. You can port it onto another operating system or using another GUI APIs.

### TODO List
1. Port on Arduino, using Nokia 5110 LCD hardware
2. Using Qt as GUI

