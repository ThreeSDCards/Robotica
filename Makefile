modelsrc = $(wildcard Model/*.cpp)
modelobjs = $(modelsrc:.cpp=.o)
CC = g++
LDFLAGS = -lGl -lGlut


Tests: Model tests.cpp
	$(CC) -o test tests.cpp $(modelobjs) $(LDFLAGS)

Model: $(modelobjs)

%.o: %.cpp
	$(CC) -o $@ -c $<

.PHONY: clean

clean:
	rm -f Model/*.o
	rm -f View/*.o