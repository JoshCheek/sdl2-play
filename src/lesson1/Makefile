CXX = clang++
CXXFLAGS = -Wall -c -std=c++11 -I ../../include -I/usr/local/include/SDL2 -D_THREAD_SAFE
LDFLAGS = -L/usr/local/lib -lSDL2
EXE = SDL_Lesson1

all: $(EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
