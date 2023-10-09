LIBRARY_NAME = ngulibc

CC = clang
CFLAGS = -Wall -Werror -I$(SRC_DIR) -pthread -fPIC
LDFLAGS = -pthread -shared

SRC_DIR = src
OBJ_DIR = binary
LIB_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

LIB_SHARED = $(LIB_DIR)/lib$(LIBRARY_NAME).so
LIB_STATIC = $(LIB_DIR)/lib$(LIBRARY_NAME).a

all: $(LIB_SHARED) $(LIB_STATIC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIB_SHARED): $(OBJ_FILES) | $(LIB_DIR)
		$(CC) $(LDFLAGS) $(OBJ_FILES) -o $(LIB_SHARED)

$(LIB_STATIC): $(OBJ_FILES) | $(LIB_DIR)
		ar rcs $(LIB_STATIC) $(OBJ_FILES)

clean:
		rm -rf $(OBJ_FILES) $(LIB_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(LIB_DIR):
		mkdir -p $(LIB_DIR)

.PHONY: all clean

