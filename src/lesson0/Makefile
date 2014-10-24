CXX = clang++
SDL = -framework SDL2
CXXFLAGS = -Wall -c -std=c++11 -I ../../include
LDFLAGS = $(SDL)
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
