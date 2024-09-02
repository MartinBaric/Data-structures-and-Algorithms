# the compiler to use
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -fopenmp turn on multiprocessing using threads
CFLAGS   = -fopenmp 
CFLAGS  += -g
#CFLAGS	+=  -Wall
OPTS 	= -c -Wall  
#files to link:
LFLAGS  = -Trees/BinaryTree.o

BUILD_DEBUG=yes

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

$(info Current systemparameters set for compilation:  )
$(info Compiler: $(CC))
$(info Source Folders paths: $(SRC))
$(info Object Folders paths: $(OBJ))
$(info Input executable file: $(INPUT))
$(info Output executable file: $(OUTPUT))
$(info Compiled source files: $(SRCS))
$(info Generated object files: $(OBJS))


# all: $(OBJS)-before compiling the main file create the object files first  
all: $(OBJS)
	$(CC) $(INPUT).cpp $(CFLAGS) -o $(OUTPUT) $(OBJS)
#	$(CC) -c $(SRCS_Main) $(SRCS) -fopenmp 
# %.o serves a template which replace % with all contents +++% bofere %   
#%.o: $(SRCS)/%.cpp
#	$(CC) -c $< -o $@
#$(INPUT):
clean: 
	rm -f *.o
	rm -f Test
	rm -f Trees/*.o

# Usefull commands : 
# ifndef 
# if variable not set do
# endif
# $(shell ...) allows to use linux shell
