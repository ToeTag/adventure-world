 CC = g++

 CFLAGS = -w -c -g -std=c++0x

#LDFLAGS= -lSDL

 SOURCES = $(wildcard *.cpp)

 COMPILE = $(CC) $(CFLAGS)

 OBJFILES = $(SOURCES:.cpp=.o)    

 EXECUTABLE = AdventureWorld


 all: $(SOURCES) $(EXECUTABLE)

 $(EXECUTABLE): $(OBJFILES)
	 $(CC) $(LDFLAGS) $(OBJFILES) -o $(EXECUTABLE)

 .cpp.o:
	 $(CC) $(CFLAGS) $< -o $@

 clean:
	 rm -rf *o AdventureWorld