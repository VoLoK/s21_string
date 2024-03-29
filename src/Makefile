CC=gcc

TARGET?=s21_string.a
TEST_TARGET?=test_s21_string.a
TEST_EXE?=test_s21_string

SRCS=$(wildcard s21_*.c)
OBJ=$(SRCS:.c=.o)

TEST_SRC_DIR?=./StringUnittest
TEST_INC_DIR?=./
TEST_OBJ_DIR?=./StringUnittest/obj

TEST_INC:=$(shell find $(TEST_INC_DIR) -name "s21_*.h")
TEST_SRC:=$(shell find $(TEST_SRC_DIR) -name "s21_*.c")
TEST_OBJ:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

AR:= ar rc
RAN:= ranlib
MK:= mkdir -p
RM:= rm -f

CFLAGS= -Wall -Wextra -Werror -std=c11
TEST_CFLAGS= -g $(CFLAGS) $(shell pkg-config --cflags --libs check) -lm

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(AR) $(TARGET) $(OBJ)
	@$(RAN) $(TARGET)
	@echo "\033[22;90m$(TARGET) has been changed and recompiled.\033[0m"

$(TEST_TARGET): $(TEST_OBJ)
	@$(AR) $(TEST_TARGET) $(TEST_OBJ)
	@$(RAN) $(TEST_TARGET)
	@echo "\033[22;90m$(TEST_TARGET) has been changed and recompiled.\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJ): $(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c $(TEST_INC)
	@$(MK) $(TEST_OBJ_DIR)
	@$(CC) -c $(CFLAGS) -o $@ -c $< -I $(TEST_INC_DIR)

test: $(TARGET) $(TEST_TARGET)
	@$(CC) $(TEST_OBJ) $(TEST_TARGET) -o $(TEST_EXE) $(TEST_CFLAGS) -L. $(TARGET)
	@./$(TEST_EXE)
	
add-coverage:
	$(eval CFLAGS += --coverage)

gcov_report: clean add-coverage test
	@gcovr -o gcov_report.html --html --html-self-contained

clang:
	@cp ../materials/linters/.clang-format ./.clang-format
	@clang-format -n --style=file *.c *.h StringUnittest/*.c
	@$(RM) .clang-format

clang-fix:
	@cp ../materials/linters/.clang-format ./.clang-format
	@clang-format -i --style=file *.c *.h StringUnittest/*.c
	@$(RM) .clang-format

clean:
	@$(RM) $(OBJ)
	@$(RM) -rd $(TEST_OBJ_DIR)
	@$(RM) $(TARGET)
	@$(RM) $(TEST_TARGET)
	@$(RM) $(TEST_EXE)
	@$(RM) gcov*
	@$(RM) *.gcda tests/*.gcda
	@$(RM) *.gcno tests/*.gcno

	@echo "\033[1;31mAll objects have been removed.\033[0m"

re: clean all