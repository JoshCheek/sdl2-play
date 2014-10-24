Going through tutorials at http://www.willusher.io/pages/sdl2/

Depends on sdl. There's a homebrew thing for it, but I couldn't get that to work.
Insted, I downloaded the DMG from http://libsdl.org/download-2.0.php and copied
it into /Library/Frameworks

...I'm not sure that emcc works with libsdl2 or just libsdl,
it seemed like the one that it loaded
https://github.com/kripken/emscripten/blob/c40c7c218c3cfac5d832607733cf1cbc6ba47dab/tests/hello_world_sdl.cpp#L2
is sdl1 (at least I assume, since the includes are different).
