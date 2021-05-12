HEADER_FILES = $(wildcard src/*.h)
SOURCE_FILES = $(wildcard src/*.c)

tb: $(SOURCE_FILES) $(HEADER_FILES)
	gcc $(SOURCE_FILES) -o tb
clean:
	-rm -f tb

