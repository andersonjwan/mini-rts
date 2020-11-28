OBJECTS = main.cpp MyGame.cpp

# Compiler
CC = g++

# Compiler Flag(s)
COMPILER_FLAGS = -w

# Linker Flag(s)
LINKER_FLAGS = -lSDL2

# Executable Name
EXEC_NAME = MyGame.out

all :
	$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)
