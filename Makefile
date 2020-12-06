BIN = dillikwaji

BIN_DIR = bin
SRC_DIR = src
OBJ_DIR = obj

CC = g++

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -pedantic

LDLIBS = 
LDFLAGS = 

.PHONY: all clean files release

BIN := $(BIN_DIR)/$(BIN)

all: $(BIN)

release: FLAGS = -O2
release: LDFLAGS += -static -static-libstdc++ -static-libgcc
release: clean
release: all	

$(BIN): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)/*

files:
	@echo "bin: $(BIN)"
	@echo "src: $(SRC)"
	@echo "obj: $(OBJ)"
