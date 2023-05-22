CC=gcc

TARGET?=s21_string.a

SRC_DIR?=./String
INC_DIR?=./String
TEST_DIR?=./StringUnittest
OBJ_DIR?=./objs

INC:=$(shell find $(INC_DIR) -name "*.h")
SRC:=$(shell find $(SRC_DIR) -name "s21_*.c")
OBJS:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

AR:= ar rc
RAN:= ranlib
RM:= rm -rf
MK:=mkdir -p

CFLAGS=-c -Wall -Wextra -Werror -std=c11

all: s21_string.a

$(TARGET): $(OBJS)
	$(AR) $(TARGET) $(OBJS)
	$(RAN) $(TARGET)

$(OBJS): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@$(MK) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

clang:
	clang-format -n --style=file -output-replacements-xml $(SRC) $(INC)
	
clang-fix:
	clang-format -i --style=file -output-replacements-xml $(SRC) $(INC)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
