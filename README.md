# text-builder
A utility program to apply transformations on text.  

## How to Build the C Version
Clone the project and run `cd c/ && make` to get the `tb` binary.

## Usage
To run the C version you can use the [built](#how-to-build-the-c-version) binary.  
To run the Haskell version you can use `stack Main.hs`.  
Use the `-h` flag to see the usage and options.  
Example output (possibly outdated):
```
Usage: ./tb [-u | -l | -r | -R | -a POSTFIX | -p PREFIX | -m COUNT]...
Available options:
  -u Uppercase the input
  -l Lowercase the input
  -r Reverse the input
  -R Randomcase the input
  -a Append POSTFIX at the end of the input
  -p Prepend PREFIX at the start of the input
  -m Repeat the input COUNT times (negative COUNT means 0)
  -h Show this help text
```

## Usage Examples
```bash
$ echo hello | ./tb -u
HELLO
$ echo hello | ./tb -u -r
OLLEH
$ echo hello | ./tb -u -r -a ' world'
OLLEH world
```
#### Note
I made this program for me to get familiar with Vim (and get back into C).

