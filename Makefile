HEADER_FILES := $(wildcard src/*.h)
SOURCE_FILES := $(wildcard src/*.c)
TEST_SOURCE_FILES := tests.c $(filter-out src/main.c, $(SOURCE_FILES))

tb: $(SOURCE_FILES) $(HEADER_FILES)
	gcc $(SOURCE_FILES) -o tb

tests: $(TEST_SOURCE_FILES) $(HEADER_FILES)
	gcc $(TEST_SOURCE_FILES) -o tests

clean:
	-rm -f tb

