 CC = g++

 ifeq ($(DEBUG), 1)
	D_FLAG = -DDEBUG
 else
	D_FLAG = -DNDEBUG
 endif

 CFLAGS = -w -c -g -std=c++0x $(D_FLAG) 

 IDIR=-I -I/Fiends 

 _DEPS = $(wildcard *.h)

 DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

 SOURCES = $(wildcard *.cpp)

 COMPILE = $(CC) $(CFLAGS)

 OBJFILES = $(SOURCES:.cpp=.o)    

 EXECUTABLE = AdventureWorld

 all: $(SOURCES) $(EXECUTABLE)

 $(EXECUTABLE): $(OBJFILES)
	 $(CC) $(LDFLAGS) $(OBJFILES) -o $(EXECUTABLE)

 .cpp.o: $(DEPS)
	 $(CC) $(CFLAGS) $< -o $@

 clean:
	 rm -rf *o AdventureWorld