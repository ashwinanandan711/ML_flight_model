SRC = $(shell find -iname "*.c")
SRC2 = $(wildcard *.c src/msg/*.c)
OBJ_FILES = $(SRC:%.c=%.o)
INCLUDES = $(shell find -iname "*.h" -exec dirname {} \; | sed 's/^./-I./g' | xargs)
CFLAGS = -Wall -Wextra -MD -MP
DEPS = $(OBJ_FILES:%.o=%.d)

$(info $(SRC) $(SRC2))
-include $(DEPS)

all: main
        @

run:
        @./main

main: $(OBJ_FILES)
        gcc $^ -o $@

%.o:%.c
        gcc -c $< -o $@


clean:
        @rm main $(OBJ_FILES) $(DEPS)

.PHONY: clean all run