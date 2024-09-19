CC 				:= g++
CFLAGS 	 		:= -std=c++20 -Wall -Wextra -Wshadow -Wno-unused -Wno-uninitialized
CPPFLAGS 		:= -MMD -MP
LDLIBS 	 		:=
LDFLAGS 		:= 
INCLUDES 		:= -Isrc

REL_CFLAGS  	:= -O2
REL_CPPFLAGS 	:= -DNDEBUG
REL_LDLIBS 		:=
REL_LDFLAGS 	:=
REL_INCLUDES 	:=

DBG_CFLAGS 		:= -O0 -g -Werror -fsanitize=undefined,address -fno-omit-frame-pointer
DBG_CPPFLAGS 	:= -DDEBUG
DBG_LDLIBS 		:= 
DBG_LDFLAGS 	:= -fsanitize=undefined,address -fno-omit-frame-pointer
DBG_INCLUDES 	:=

GDB_CFLAGS 		:= -O0 -g -Werror -fno-omit-frame-pointer
GDB_LDFLAGS 	:= -fno-omit-frame-pointer

BIN 			:= game

SRC_DIR 		:= src
BIN_DIR 		:= bin

DBG_BIN_DIR 	:= $(BIN_DIR)/debug
DBG_OBJ_DIR 	:= $(DBG_BIN_DIR)/obj
DBG_BIN  		:= $(DBG_BIN_DIR)/${BIN}

GDB_BIN_DIR 	:= $(BIN_DIR)/debug-gdb
GDB_OBJ_DIR 	:= $(GDB_BIN_DIR)/obj
GDB_BIN  		:= $(GDB_BIN_DIR)/${BIN}

REL_BIN_DIR 	:= $(BIN_DIR)/release
REL_OBJ_DIR 	:= $(REL_BIN_DIR)/obj
REL_BIN 		:= $(REL_BIN_DIR)/${BIN}

SRC 			:= $(shell find src -name '*.cpp')

DBG_OBJ 		:= $(patsubst src/%.cpp, $(DBG_OBJ_DIR)/%.o, $(SRC))
DBG_DEPS 		:= $(DBG_OBJ:.o=.d)

GDB_OBJ 		:= $(patsubst src/%.cpp, $(GDB_OBJ_DIR)/%.o, $(SRC))
GDB_DEPS 		:= $(GDB_OBJ:.o=.d)

REL_OBJ 		:= $(patsubst src/%.cpp, $(REL_OBJ_DIR)/%.o, $(SRC))
REL_DEPS 		:= $(REL_OBJ:.o=.d)

default: debug

all: debug release

run: debug-run

--make-dirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DBG_BIN_DIR)
	@mkdir -p $(REL_BIN_DIR)
	@mkdir -p $(DBG_OBJ_DIR)
	@mkdir -p $(REL_OBJ_DIR)
	@mkdir -p $(GDB_BIN_DIR)
	@mkdir -p $(GDB_OBJ_DIR)

release: --make-dirs $(REL_BIN)

$(REL_BIN): $(REL_OBJ)
	@echo Linking RELEASE - $(REL_BIN)
	@$(CC) $(REL_OBJ) $(LDLIBS) $(REL_LDLIBS) $(LDFLAGS) $(REL_LDFLAGS) -o $@

$(REL_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@echo Compiling RELEASE - $<
	@$(CC) $(CPPFLAGS) $(REL_CPPFLAGS) $(CFLAGS) $(REL_CFLAGS) $(INCLUDES) $(REL_INCLUDES) -c $< -o $@

debug: --make-dirs $(DBG_BIN)

$(DBG_BIN): $(DBG_OBJ)
	@echo Linking DEBUG - $(DBG_BIN)
	@$(CC) $(DBG_OBJ) $(LDLIBS) $(DBG_LDLIBS) $(LDFLAGS) $(DBG_LDFLAGS) -o $@

$(DBG_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@echo Compiling DEBUG - $<
	@$(CC) $(CPPFLAGS) $(DBG_CPPFLAGS) $(CFLAGS) $(DBG_CFLAGS) $(INCLUDES) $(DBG_INCLUDES) -c $< -o $@

debug-gdb: --make-dirs $(GDB_BIN)

$(GDB_BIN): $(GDB_OBJ)
	@echo Linking DEBUG for GDB - $(GDB_BIN)
	@$(CC) $(GDB_OBJ) $(LDLIBS) $(DBG_LDLIBS) $(LDFLAGS) $(GDB_LDFLAGS) -o $@

$(GDB_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@echo Compiling DEBUG for GDB - $<
	@$(CC) $(CPPFLAGS) $(DBG_CPPFLAGS) $(CFLAGS) $(GDB_CFLAGS) $(INCLUDES) $(DBG_INCLUDES) -c $< -o $@


release-run: release
	@echo Running RELEASE
	@./$(REL_BIN)

debug-run: debug
	@echo Running DEBUG
	@./$(DBG_BIN)

clean:
	@echo Cleaning directories
	@rm -rf $(BIN_DIR)

.PHONY: release debug release-run debug-run all clean

-include $(DBG_DEPS)
-include $(REL_DEPS)
-include $(GDB_DEPS)
