CXX := clang++
CXX_FLAGS := -Wall -g -std=c++20 -ggdb

SRC_ROOT := ../$(shell basename $(realpath ../))

BIN := bin
SRC := $(shell find $(SRC_ROOT)/src -name "*.cc")
INCLUDE := $(shell find $(SRC_ROOT)/include -name "*.hh")
LIBLITE := $(SRC_ROOT)/lib

LIBRARIES :=

# name of executable
EXECUTABLE := main

.PHONY: build run clean

build: clean $(BIN)/$(EXECUTABLE)
	@echo "MAKE:: BUILDING"

run: build
	@echo "MAKE:: RUNNING"
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(LIBLITE) $^ -o $@ $(LIBRARIES)

clean:
	@echo "MAKE:: CLEANING"
	-rm $(BIN)/*