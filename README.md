# text-builder
A utility program to apply transformations on text.  

## Build
Clone the project and run `make` to get `./tb`.

## Usage
```bash
$ echo hello | tb -u
HELLO
$ echo hello | tb -u -r
OLLEH
$ echo hello | tb -u -r -a ' world'
OLLEH world
```
#### Note
I made this program for me to get familiar with Vim (and get back into C).

