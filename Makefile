CC = gcc
CFLAGS= -Wall -Werror -Wextra

CPP = cppcheck --enable=all --suppress=missingIncludeSystem
CHECK_LIBS = -lcheck -pthread -lsubunit

CFILES =  main.c s21_string_lib/s21_memchr.c s21_string_lib/s21_memcmp.c s21_string_lib/s21_memcpy.c s21_string_lib/s21_memset.c s21_string_lib/s21_strncat.c tests/suite_memchr.c

OBJS = $(CFILES:.c=.o)

all: s21_string

s21_string:
	$(CC) $(CFLAGS) $(CFILES) -o s21_string $(CHECK_LIBS)

cppcheck:
	$(CPP) $(CFILES)

clang_check:
	find -name "*.c" -o -name "*.h" | xargs clang-format -n

clean:
	rm -f s21_string $(OBJS)

rebuild: clean s21_string