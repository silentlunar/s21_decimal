OS = $(shell uname)
USERNAME=$(shell whoami)
CC = gcc
STDFLAGS=-c -Wall -Wextra -Werror -std=c11
CFLAGS?= $(STDFLAGS)
TST_CFLAGS:= -g $(STDFLAGS) 
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
CLANG_FILE = -style=file:../materials/linters/.clang-format
STYLE_TARGETS = *.c *.h tests/*.c tests/*.h

ifeq ($(OS), Darwin)
	LIBS = $(shell pkg-config --libs check) -lm
	OPENF = open
else
	OPENF = xdg-open
	LIBS = -lcheck -lsubunit -lrt -lm -lpthread
endif

TEST_OBJ_DIR?=./tests/objects
TEST_SRC_DIR?=./tests
REPORT_TARGET=./report
REPORT_FILE=s21_decimal.info
MK:=mkdir -p

INC_DIR:=./
INC:=$(shell find $(INC_DIR) -name "*.h")
TEST_INC:=$(shell find $(TEST_SRC_DIR) -name "*.h")

SRC_DIR?=.
SRC:=$(shell find $(SRC_DIR) -name "s21_*.c")
TEST_SRC:=$(shell find $(TEST_SRC_DIR) -name "*.c" -type f -not -name "tests.c")

OBJ_DIR?=./objects
OBJS:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
REPORT_OBJS:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
TEST_OBJS:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

GCDA=$(shell find $(TEST_OBJ_DIR) -name "*.gcda")
GCNO=$(shell find $(TEST_OBJ_DIR) -name "*.gcno")

.PHONY: clean report rebuild test

all: test

rebuild: clean test style_set

s21_decimal.a: $(OBJS)
	ar rc s21_decimal.a $(OBJS)
	ranlib s21_decimal.a

test_s21_decimal.a: $(REPORT_OBJS) $(INC)
	ar rc test_s21_decimal.a $(REPORT_OBJS)
	ranlib test_s21_decimal.a

test: s21_decimal.a $(TEST_OBJ_DIR)/main.o $(TEST_OBJS) $(TEST_INC) 	
	$(CC) $(TEST_OBJS) $(TEST_OBJ_DIR)/main.o $(GCOV_FLAGS) -o test $(LIBS) -L. s21_decimal.a
	./test

$(TEST_OBJ_DIR)/main.o: tests/tests.c 
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -o $(TEST_OBJ_DIR)/main.o tests/tests.c 

$(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c $(TEST_INC) 
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(TST_CFLAGS) -o $@ -c $<

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) 
	@$(MK) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(REPORT_OBJS): $(TEST_OBJ_DIR)%.o: $(SRC_DIR)%.c $(TEST_INC)
	@$(MK) $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

gcov_report: $(REPORT_TARGET)

$(REPORT_TARGET): CFLAGS += $(GCOV_FLAGS)
$(REPORT_TARGET): $(REPORT_FILE)
	genhtml $(REPORT_FILE) -o $(REPORT_TARGET)
	$(OPENF) ./report/src/index.html

test_gcov: test_s21_decimal.a $(TEST_OBJ_DIR)/main.o $(TEST_OBJS) 
	$(CC) $(TEST_OBJS) $(TEST_OBJ_DIR)/main.o $(GCOV_FLAGS) -o test_gcov $(LIBS) -L. test_s21_decimal.a

$(REPORT_FILE): test_gcov
	./test_gcov
	geninfo $(TEST_OBJ_DIR) -b . -o $(REPORT_FILE)

brsw:
	eval "$(/opt/goinfre/$(USERNAME)/homebrew/bin/brew shellenv)"
	brew update --force --quiet
	chmod -R go-w "$(brew --prefix)/share/zsh"

install_brew:
	cd /opt/goinfre/$(USERNAME)
	mkdir homebrew
	git clone https://github.com/Homebrew/brew homebrew
	make brsw

style_set:
	clang-format $(CLANG_FILE) -i $(STYLE_TARGETS)

style_check:
	clang-format $(CLANG_FILE) -n $(STYLE_TARGETS) 

clean:
	rm -f test_s21_decimal.a s21_decimal.a test test_gcov *.gcno *.gcda s21_decimal.info
	rm -rf objects tests/objects report

valgrind: test
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
	rm s21_decimal.a test
	rm -rf objects/ tests/objects
	clang-format $(CLANG_FILE) -n $(STYLE_TARGETS)