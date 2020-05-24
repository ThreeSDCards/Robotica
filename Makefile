modelsrc = $(wildcard Model/*.cpp)
modelobjs = $(modelsrc:.cpp=.o)
viewsrc = $(wildcard View/*.cpp)
viewobjs = $(viewsrc:.cpp=.o)
CC = g++
LDFLAGS = -lGL -lglut

main: $(modelobjs) $(viewobjs)
	$(CC) -o main main.cpp $(modelobjs) $(viewobjs) $(LDFLAGS)

Tests: $(modelobjs) tests.cpp
	$(CC) -o test $(modelobjs) tests.cpp  $(LDFLAGS)

Model: $(modelobjs)

View: $(viewobjs)


%.o: %.cpp
	$(CC) -o $@ -c $< $(LDFLAGS)

.PHONY: clean

clean:
	rm -f Model/*.o
	rm -f View/*.o
	rm -f test
	rm -f main
