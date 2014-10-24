#!/usr/bin/env ruby

# this file has never been run,
# just sort of documenting what all I tried
# This is all largely based on http://gsathya.in/blog/mozilla/sdl2-emscripten.html

Dir.chdir __dir__

def self.sh(command)
  $stderr.puts command
  system command
end

# build sdl2 for emscripten
puts "\e[33mSdl2 for emscripten\e[39m"
sh 'git submodule init'
Dir.chdir 'SDL-emscripten' do
  puts 'cd SDL-emscripten'
  sh 'emconfigure '\
        './configure '\
        '--host=asmjs-unknown-emscripten '\
        '--disable-assembly '\
        '--disable-threads '\
        '--enable-cpuinfo=false '\
        'CFLAGS="-O2"'
  sh 'emmake make'
  puts 'cd ..'
end

# set env vars
def self.set_env(var, value)
  $stderr.puts "Setting env var #{var.inspect} to #{value.inspect}"
  ENV[var] = value
end
set_env 'CPLUS_INCLUDE_PATH', File.expand_path('SDL-emscripten/include', __dir__)
set_env 'LIBS' ['-L/usr/local/lib',
                '-L'+File.expand_path('SDL-emscripten/build/.libs', __dir__),
                '-lSDL2',
               ].join(':')

# build sdl2_gfx for emscripten
puts "\e[33mSdl2 for emscripten\e[39m"
sh 'curl http://www.ferzkopp.net/Software/SDL2_gfx/SDL2_gfx-1.0.1.tar.gz > SDL2_gfx-1.0.1.tar.gz'
sh 'gunzip SDL2_gfx-1.0.1.tar.gz'
sh 'tar -xf SDL2_gfx-1.0.1.tar'
sh 'rm SDL2_gfx-1.0.1.tar'
Dir.chdir 'SDL2_gfx-1.0.1/' do
  puts 'cd SDL2_gfx-1.0.1/'
  sh './configure'
  sh 'make'
  puts 'cd ..'
end

# this got it to compile and load in the browser,
# but it died shortly after because it was missing "SDL_CreateWindow"
# so I must not have linked them all up correctly
# also tried configuring SDL2_gfx with this command:
#
# sh 'env EMCONFIGURE_JS=1 emconfigure ../SDL-emscripten/configure --disable-mmx'
