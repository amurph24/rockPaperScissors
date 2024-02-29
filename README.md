# Rock, Paper, Scissors
---
## About
rps is a terminal game of Rock, Paper, Scissors you will play against the computer, your score will be recorded between play sessions.

## Dependencies
rps was tested on Linux system (x86-64 intel), the following packages will be required to install it from source on your machine:
```
git
make
gcc
```
For Debian/Ubuntu you can install these packages using apt:
```
sudo apt install git make gcc
```

## Installation
This package includes a `Makefile` so installation is fairly simple:
```
// clone the rps repository
git clone https://github.com/amurph24/rps.git

// navigate to the local repository
cd rps

// install the package using make
sudo make install

// remove compilation files
make clean
```

## Usage
execute the command:
```
rps
```
in the terminal to start the game!

## License
Licensed under the GPL-3.0 license, go nuts!
