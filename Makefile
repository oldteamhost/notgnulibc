LIBRARY_NAME = ngulibc

CC = clang
CFLAGS = -Wall -Werror -I$(SRC_DIR) -fPIC

SRC_DIR = src
OBJ_DIR = binary
LIB_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

LIB_FILE = $(LIB_DIR)/lib$(LIBRARY_NAME).so
LDFLAGS = -shared

all: $(LIB_FILE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIB_FILE): $(OBJ_FILES) | $(LIB_DIR)
		$(CC) $(LDFLAGS) $(OBJ_FILES) -o $(LIB_FILE)

clean:
		rm -rf $(OBJ_FILES) $(LIB_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(LIB_DIR):
		mkdir -p $(LIB_DIR)

.PHONY: all clean

