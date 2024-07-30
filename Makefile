.SILENT:
ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
else
    DETECTED_OS := $(shell uname -s)
endif

ifeq ($(DETECTED_OS),Windows)
    CC := gcc
    CFLAGS := -Wall -Wextra -Werror
    EXECUTABLE := base_converter.exe
else ifeq ($(DETECTED_OS),Linux)
    CC := gcc
    CFLAGS := -Wall -Wextra -Werror
    EXECUTABLE := base_converter
else ifeq ($(DETECTED_OS),Darwin)
    CC := clang
    CFLAGS := -Wall -Wextra -Werror
    EXECUTABLE := base_converter
else
    $(error Unsupported operating system: $(DETECTED_OS))
endif

SOURCES := main.c ft_convert_base.c ft_convert_base2.c

OBJECTS := $(SOURCES:.c=.o)

HEADERS := ft_convert_base.h ft_convert_base2.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	$(MAKE) clean

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
