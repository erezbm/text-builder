# text-builder
A utility program to apply transformations on text.  

## Build
Clone the project and run `make` to get `./tb`.

## Usage
Run `./tb -h` to see usage and options.
Possibly outdated usage and options:
```
Usage: ./tb [-ulrR] [-a postfix] [-p prefix] [-m count]
Options:
  -u uppercase the input
  -l lowercase the input
  -r reverse the input
  -R randomcase the input
  -a append <postfix> at the end of the input
  -p prepend <prefix> at the start of the input
  -m repeat the input <count> times (negative <count> means 0)
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

