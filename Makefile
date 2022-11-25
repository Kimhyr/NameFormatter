SRCD=./Source
OUTD=./Output
OBJD=$(OUTD)/Objects

DIRS=.
SRCS=$(foreach D,$(DIRS),$(wildcard $(SRCD)/$(D)/*.cpp))
OBJS=$(patsubst $(SRCD)/%.cpp,$(OBJD)/%.obj,$(SRCS))
BIN=$(OUTD)/VM.exe

CFLGS=-std=c++20 -O3
WFLGS=-Wall -Wextra -Werror
IFLGs=$(foreach D,$(DIRS),-I$(SRCD)/$(D))
FLGS=$(CFLGS) $(WFLGS) $(IFLGS)
CC=clang++

all:$(BIN)

run:$(BIN)
	$(BIN)

$(BIN):$(OBJS)
	$(CC) $^ -o $@

$(OBJD)/%.obj:$(SRCD)/%.cpp
	$(CC) -c $^ -o $@ $(FLGS) 

clean:$(OUTD)
	rm -rf $(OUTD)/*
	mkdir $(OBJD)
	mkdir $(foreach D,$(DIRS),$(OBJD)/$(D))

.PHONY:all run clean
