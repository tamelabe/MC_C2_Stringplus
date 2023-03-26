CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
SRCS = s21_insert.c s21_memchr.c s21_memcmp.c\
	   s21_memcpy.c s21_memmove.c s21_memset.c\
	   s21_strcat.c s21_strchr.c s21_strcmp.c\
	   s21_strcpy.c s21_strcspn.c s21_strerror.c\
	   s21_strlen.c s21_strncat.c s21_strncmp.c\
	   s21_strncpy.c s21_strpbrk.c s21_strrchr.c\
	   s21_strspn.c s21_strstr.c s21_strtok.c\
	   s21_to_lower.c s21_to_upper.c s21_trim.c\
	   s21_sprintf.c s21_sscanf.c

TESTS = s21_start_test.c s21_sprintf_test.c s21_string_test.c s21_sscanf_test.c
HEADERS = s21_string.h s21_sprintf.h s21_tests.h s21_sscanf.h

OBJ = $(patsubst %.c, %.o, $(SRCS))
TESTS_OBJ = $(patsubst %.c, %.o, $(TESTS))

OS = $(shell uname)

ifeq ($(OS), Linux)
	LINUX_LIBS=-lsubunit -lrt -lpthread -lm
endif

.PHONY: all clean test s21_string.a gcov_report

all: s21_string.a test gcov_report

s21_string.a: $(OBJ)
	@ar -rcs s21_string.a $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test: s21_string.a $(TESTS_OBJ) $(HEADERS)
	@$(CC) --coverage s21_string.a $(TESTS_OBJ) -lcheck $(LINUX_LIBS) -o a.out
	./a.out

gcov_report: $(SRCS) $(TESTS) $(HEADRES)
	@$(CC) $(SRCS) $(TESTS) -o s21 -lcheck  $(LINUX_LIBS) -fprofile-arcs -ftest-coverage
	@./s21
	@lcov -c -d . -o s21.info
	@genhtml s21.info -o report
	@open report/index.html

clean:
	@rm -rf *.o *.gcno *.gcda *.info *.out s21 ./report