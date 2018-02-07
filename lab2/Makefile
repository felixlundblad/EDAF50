# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
#Gammal -> PROGS =  ltest test_coding print_argv HelloWorld encode decode
PROGS = spell

all: $(PROGS)

#Gammal -> test: test_coding
#Gammal -> 	./test_coding

# Targets rely on implicit rules for compiling and linking
#Gammal -> ltest: ltest.o list.o
#Gammal -> test_coding: test_coding.o coding.o #"Receptet för målet "coding" misslyckades" om jag kör coding.o själv?
#Gammal -> print_argv: print_argv.o
#Gammal -> HelloWorld: HelloWorld.cc
#Gammal -> encode: encode.cc
#Gammal -> decode: decode.cc
spell: spell.o word.o dictionary.o 

# Phony targets
.PHONY: all #Gammal -> test clean distclean link

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
