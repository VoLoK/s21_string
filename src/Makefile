CC=gcc

TARGET?=s21_string.a
TEST_TARGET?=test_s21_string.a
TEST_EXE?=test_s21_string

SRC_DIR?=./String
INC_DIR?=./String/includes
OBJ_DIR?=./String/obj

TEST_SRC_DIR?=./StringUnittest
TEST_INC_DIR?=./StringUnittest/includes
TEST_OBJ_DIR?=./StringUnittest/obj

INC:=$(shell find $(INC_DIR) -name "*.h")
SRC:=$(shell find $(SRC_DIR) -name "*.c")
OBJ:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

TEST_INC:=$(shell find $(TEST_INC_DIR) -name "*.h")
TEST_SRC:=$(shell find $(TEST_SRC_DIR) -name "*.c")
TEST_OBJ:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

AR:= ar rc
RAN:= ranlib
MK:= mkdir -p
RM:= rm -f

CFLAGS= -Wall -Wextra -Werror -std=c11
TEST_CFLAGS= -g $(CFLAGS) $(shell pkg-config --cflags --libs check) -lm -fsanitize=address
GCOV_FLAGS?= -fprofile-arcs -ftest-coverage

all: s21_string.a

$(TARGET): $(OBJ)
	@$(AR) $(TARGET) $(OBJ)
	@$(RAN) $(TARGET)
	@echo "\033[22;90m$(TARGET) has been changed and recompiled.\033[0m"

$(TEST_TARGET): $(TEST_OBJ)
	@$(AR) $(TEST_TARGET) $(TEST_OBJ)
	@$(RAN) $(TEST_TARGET)
	@echo "\033[22;90m$(TEST_TARGET) has been changed and recompiled.\033[0m"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@$(MK) $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(TEST_OBJ): $(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c $(TEST_INC)
	@$(MK) $(TEST_OBJ_DIR)
	@$(CC) -c $(CFLAGS) -o $@ -c $< -I $(TEST_INC_DIR) -I $(INC_DIR)

test: $(TARGET) $(TEST_TARGET)
	@$(CC) $(TEST_OBJ) $(TEST_TARGET) -o $(TEST_EXE) $(TEST_CFLAGS) -L. $(TARGET)
	@./$(TEST_EXE)

clang:
	@clang-format -n --style=file $(SRC) $(INC) $(TEST_SRC) $(TEST_INC)

clang-fix:
	@clang-format -i --style=file $(SRC) $(INC) $(TEST_SRC) $(TEST_INC)

clean:
	@$(RM) $(OBJ)
	@$(RM) -d $(OBJ_DIR)
	@$(RM) $(TEST_OBJ)
	@$(RM) -d $(TEST_OBJ_DIR)
	@$(RM) $(TARGET)
	@$(RM) $(TEST_TARGET)
	@$(RM) $(TEST_EXE)
	@echo "\033[1;31mAll objects have been removed.\033[0m"

re: clean all
