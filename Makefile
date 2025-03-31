# set the compiler to g++
CXX = g++                          # compiler to use
# set the compiler flags to use C++11 standard and enable all warnings
CXXFLAGS = -std=c++11 -Wall        # compiler flags
# define the name of the final executable
TARGET = lab8                      # target executable name
# list the object files that will be built
OBJS = main.o matrix.o             # object files

# default target: build the executable
all: $(TARGET)                     # default target depends on the executable

# rule to link the object files and create the executable
$(TARGET): $(OBJS)                 # target depends on the object files
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)  # link object files to produce the executable

# rule to compile main.cpp into main.o
main.o: main.cpp matrix.hpp        # main.o depends on main.cpp and matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp   # compile main.cpp into main.o

# rule to compile matrix.cpp into matrix.o
matrix.o: matrix.cpp matrix.hpp      # matrix.o depends on matrix.cpp and matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp  # compile matrix.cpp into matrix.o

# rule to clean up generated files
clean:                             # clean target to remove built files
	rm -f $(TARGET) $(OBJS)         # remove the executable and object files
