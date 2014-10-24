CXX = clang++
CXXFLAGS = -Wall -c -std=c++11 -I ../../include -I/usr/local/include/SDL2 -D_THREAD_SAFE
LDFLAGS = -L/usr/local/lib -lSDL2
EXE = SDL_Lesson0
POSTSCRIPT_EXE = SDL_Postscript

all: $(EXE) $(POSTSCRIPT_EXE)

$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@

$(POSTSCRIPT_EXE): postscript.o
	$(CXX) $(LDFLAGS) $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

postscript.o: postscript.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE) $(POSTSCRIPT_EXE)
