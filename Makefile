CC = g++
OPT = -O0
INCDIRS = -I.
CFLAGS = -g -Wall -Wextra $(OPT) $(INCDIRS)

SRC = supervised
#SRC += unsupervised
OBJ = obj

SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BIN = main

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o:  $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS) $(BIN)