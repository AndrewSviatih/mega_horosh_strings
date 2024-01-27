CC = gcc
CFLAGS = -Wall -Werror -Wextra
C11 = -std=c11

CPP = cppcheck --enable=all --suppress=missingIncludeSystem

MAIN = main.c

CFILES_STR_LIB = $(wildcard s21_string_lib/*.c)
OBJS_STR_LIB = $(CFILES_STR_LIB:.c=.o)

CFILES_TESTS = $(wildcard tests/*.c)
OBJS_TESTS = $(CFILES_TESTS:.c=.o)

CHECK_LIBS = -lcheck -lsubunit -lm
MY_LIB = s21_string.a

#################################################################################
all: s21_string

s21_string: $(MY_LIB) tests final

$(MY_LIB): $(OBJS_STR_LIB)
	ar rcs $(MY_LIB) $(OBJS_STR_LIB)

tests: $(OBJS_TESTS)
	$(CC) -c $(MAIN) -o main.o

final:
	$(CC) $(CFLAGS) $(C11) main.o $(OBJS_TESTS) -o s21_string -L. $(MY_LIB) $(CHECK_LIBS)
################################################################################

cppcheck:
	$(CPP) $(CFILES_STR_LIB) $(CFILES_TESTS) $(MAIN)

clang_check:
	find -name "*.c" -o -name "*.h" | xargs clang-format -n

clean_o:
	rm -f $(OBJS_STR_LIB) $(OBJS_TESTS) main.o 

clean: clean_o
	rm -f s21_string main.o $(MY_LIB)

rebuild: clean s21_string

$(OBJS_STR_LIB): %.o: %.c $(wildcard s21_string_lib/*.h)
	$(CC) $(CFLAGS) $(C11) -c $< -o $@

$(OBJS_TESTS): %.o: %.c $(wildcard tests/*.h)
	$(CC) $(CFLAGS) $(C11) -c $< -o $@