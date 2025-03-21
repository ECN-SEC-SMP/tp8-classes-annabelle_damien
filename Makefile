OUT_DIR = out
OBJ_DIR = $(OUT_DIR)/obj
SRC_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

$(OBJ_DIR)/%.o: src/%.cpp
	mkdir -p $(OBJ_DIR)
	g++ -g -Iinclude -c $< -o $@  # Added -g flag for debugging

$(OUT_DIR)/main.exe : $(OBJ_FILES)
	g++ -g -o $(OUT_DIR)/main.exe $(OBJ_FILES)  # Added -g flag for debugging

clean:
	rm -rf $(OUT_DIR)

build:
	make clean && make -j

run:
	$(OUT_DIR)/main.exe

buildrun:
	make build && make run

debug:
	gdb $(OUT_DIR)/main.exe