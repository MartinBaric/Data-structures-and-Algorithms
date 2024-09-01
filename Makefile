# the compiler to use
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -fopenmp turn on multiprocessing using threads
CFLAGS = -fopenmp -g
OPTS = -c -Wall  
#files to link:
LFLAGS = -Trees/BinaryTree.o

# -I Add paths to the compiler containing directories with header files other than default header files within usr/include directory 

# Define all c-or-cpp files to be compilated 

SRC = Trees
OBJ = Trees

# Tell the compiler to replace during the compilation process to replace all .c path and names with .o patterns using $(SRC:.c = .o) command

# Set name of file to be compilated 
INPUT = Main
# Set name for executable file as compilation output 
OUTPUT = Test

# Files and folders
SRCS_Main = $(INPUT).cpp
SRCS = $(shell find $(SRC) -name '*.cpp')
SRCDIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)/./g' )
OBJS    = $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCS))

all: $(INPUT)
$(INPUT) : buildrepo $(OBJS)
	$(CC) -c $(SRCS_Main) $(SRCS) -fopenmp 
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $< -o $@
$(INPUT):
	$(CC) $(INPUT).cpp $(CFLAGS) -o $(OUTPUT) $(OBJS)
clean: 
	rm -f *.o
	rm -f Test
	rm -f Trees/*.o

buildrepo:
	@$(call make-repo)

define make-repo
	mkdir -p $(OBJ)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJ)/$$dir; \
	done
endef
