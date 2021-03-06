CC			=	g++-6
CFLAGS		=	-c -Wall -Ofast -I ./ -I ./../../cplot/
LDFLAGS		=	
SOURCES		=	./examples/example1.cpp
OBJECTS		=	$(SOURCES:.cpp=.o)
EXECUTABLE	=	./exec/example1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.out ./examples/*.o ./CPLOT/*.o ./exec/*

tar:
	tar -zcvf cplot.tar.gz ./makefile.mk ./exec ./CHEBYSHEV ./examples ./README.md ./LICENSE.md
