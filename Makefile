modelsrc = $(wildcard Model/*.cpp)
modelobjs = $(modelsrc:.cpp=.o)
CC = g++
LDFLAGS = -lGL -lglut


Tests: $(modelobjs) tests.cpp
	$(CC) -o test $(modelobjs) tests.cpp  $(LDFLAGS)

Model: $(modelobjs)

%.o: %.cpp
	$(CC) -o $@ -c $<

.PHONY: clean

clean:
	rm -f Model/*.o
	rm -f View/*.o
	rm -f test
	rm -f main