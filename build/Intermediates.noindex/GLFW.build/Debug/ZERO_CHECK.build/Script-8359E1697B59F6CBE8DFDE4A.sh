#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build
  make -f /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build
  make -f /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build
  make -f /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build
  make -f /Users/game/Desktop/Raed_Abuzaid_Fall_24/glfw_build/CMakeScripts/ReRunCMake.make
fi

