modelsrc = $(wildcard Model/*.cpp)
modelobjs = $(modelsrc:.cpp=.o)
viewsrc = $(wildcard View/*.cpp)
viewobjs = $(viewsrc:.cpp=.o)
CC = g++
LDFLAGS = -lGL -lglut


Tests: $(modelobjs) tests.cpp
	$(CC) -o test $(modelobjs) tests.cpp  $(LDFLAGS)

Model: $(modelobjs)

View: $(modelobjs) $(viewobjs)

%.o: %.cpp
	$(CC) -o $@ -c $<

.PHONY: clean

clean:
	rm -f Model/*.o
	rm -f View/*.o
	rm -f test
	rm -f main
