CC 	   = g++
CFLAGS = -c -g -Wall -Werror -Wno-unused-variable

# names
OBJ    = ../obj
SRC    = ../src
INC    = ../inc
BIN    = ../bin
MAKE   = ../make

MAIN   = main
QUE    = Queue
UTIL   = utility

# -I tells compiler to look on $(INC) dir
INCDIR = -I $(INC)

# link all
all: $(OBJ)/$(MAIN).o $(OBJ)/$(UTIL).o $(OBJ)/$(QUE).o
	$(CC) $(OBJ)/$(MAIN).o $(OBJ)/$(UTIL).o $(OBJ)/$(QUE).o -o $(BIN)/$(MAIN)

# create main.o
$(OBJ)/$(MAIN).o: $(INC)/$(UTIL).h $(SRC)/$(MAIN).cpp
	$(CC) $(CFLAGS) $(SRC)/$(MAIN).cpp $(INCDIR) -o $(OBJ)/$(MAIN).o

# create utility.o
$(OBJ)/$(UTIL).o: $(INC)/$(UTIL).h $(SRC)/$(UTIL).cpp
	$(CC) $(CFLAGS) $(SRC)/$(UTIL).cpp $(INCDIR) -o $(OBJ)/$(UTIL).o 

# create Queue.o
$(OBJ)/$(QUE).o: $(INC)/$(QUE).h $(SRC)/$(QUE).cpp
	$(CC) $(CFLAGS) $(SRC)/$(QUE).cpp $(INCDIR) -o $(OBJ)/$(QUE).o 

# utility
run: $(BIN)/$(MAIN)
	$(BIN)/$(MAIN)

clean:
	rm -f $(OBJ)/*
	rm -f $(BIN)/*