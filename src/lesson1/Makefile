CXX = clang++
SDL = -framework SDL2
CXXFLAGS = -Wall -c -std=c++11 -I ../../include
LDFLAGS = $(SDL)
EXE = SDL_Lesson1

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
