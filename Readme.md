Going through tutorials at http://www.willusher.io/pages/sdl2/

Plus, making up my own shit.

Warning
-------

There's SDL and SDL2, this caused me a lot of issues as I'd accidentally
wind up with the wrong version, or a lib that depended on the wrong version,
and tuts/answers are often for the wrong one.

Framework approach to installing SDL2
-------------------------------------

Initially I couldn't figure out how to get the homebrew thing to work.
So I downloaded the DMG from http://libsdl.org/download-2.0.php and copied
it into /Library/Frameworks
that worked fine, until I wanted to use `SDL_gfx`,
I couldn't figure out how to get them to work together.

Homebrew approach to installing SDL2
------------------------------------

`brew install sdl2 sdl2_gfx`

That installd fine, but you have to manually tell it where to find them when compiling.
You can find what to tell the compiler with:

```
$ sdl2-config --cflags
-I/usr/local/include/SDL2 -D_THREAD_SAFE

$ clang++ -Wall -c -std=c++11 -I ../../include -I/usr/local/include/SDL2 -D_THREAD_SAFE main.cpp -o main.o
```

And what to tell the linker with:
```
$ sdl2-config --libs
-L/usr/local/lib -lSDL2

$ clang++ -L/usr/local/lib -lSDL2 -lSDL2_gfx main.o -o SDL_vector
```

I don't know how you figure out where `SDL2_gfx` shit is, I just looked in the
same place that it told me to find the `SDL2` stuff, and then saw they were there, too,
so then made a few guesses about what the flags do, and eventually it worked.

Emcc
----

...I'm not sure that emcc works with libsdl2 or just libsdl,
it seemed like the one that it loaded
https://github.com/kripken/emscripten/blob/c40c7c218c3cfac5d832607733cf1cbc6ba47dab/tests/hello_world_sdl.cpp#L2
is sdl1 (at least I assume, since the includes are different).
