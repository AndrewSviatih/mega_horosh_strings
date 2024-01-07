CC = gcc
CFLAGS = -Wall -Werror -Wextra
C11 = -std=c11

CPP = cppcheck --enable=all --suppress=missingIncludeSystem

MAIN = main.c

BUILD_STR = build
CFILES_STR_LIB = $(wildcard s21_string_lib/*.c)
OBJS_STR_LIB = $(CFILES_STR_LIB:.c=.o)
OBJS_STR_LIB_DONE = $(addprefix $(BUILD_STR)/,$(CFILES_STR_LIB:.c=.o))

CFILES_TESTS = $(wildcard tests/*.c)
OBJS_TESTS = $(CFILES_TESTS:.c=.o)
OBJS_TESTS_DONE = $(addprefix $(BUILD_STR)/,$(CFILES_TESTS:.c=.o))

CHECK_LIBS = -lcheck -lsubunit -lm
MY_LIB = build/s21_string.a

all: s21_string

s21_string: lib tests main final

lib: $(OBJS_STR_LIB)
	ar rcs $(MY_LIB) $(OBJS_STR_LIB_DONE)

tests: $(OBJS_TESTS)

main:
	$(CC) -c $(MAIN) -o build/main.o

final:
	$(CC) $(CFLAGS) $(C11) build/main.o $(OBJS_TESTS_DONE) -o s21_string -L. $(MY_LIB) $(CHECK_LIBS)

cppcheck:
	$(CPP) $(CFILES)

clang_check:
	find -name "*.c" -o -name "*.h" | xargs clang-format -n

clean:
	rm -f s21_string $(OBJS_STR_LIB_DONE) $(OBJS_TESTS_DONE) build/main.o $(MY_LIB)

rebuild: clean s21_string

$(OBJS_STR_LIB): %.o: %.c
	$(CC) $(CFLAGS) $(C11) -c $< -o build/$@

$(OBJS_TESTS): %.o: %.c
	$(CC) $(CFLAGS) $(C11) -c $< -o build/$@