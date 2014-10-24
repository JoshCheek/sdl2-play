# Couldn't figure out how to get the makefile to set these
# ...it set them (verified with a make task that runs env)
# but still can't find the binary for some reason.
# so fuck it, just source this file

set -x PATH /Users/josh/code/emsdk_portable \
            /Users/josh/code/emsdk_portable/clang/e1.25.0_64bit \
            /Users/josh/code/emsdk_portable/node/0.10.18_64bit/bin \
            /Users/josh/code/emsdk_portable/emscripten/1.25.0 \
            $PATH
