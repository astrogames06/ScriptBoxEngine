#!/bin/bash

# Compiler options
CC=g++
CFLAGS="-O1 -Wall -std=c++17 -Wno-missing-braces"

# Paths
INCLUDE_DIR="include/"
LIB_DIR="mlib/"
LUA_INCLUDE=$(pkg-config --cflags lua)
LUA_LIBS=$(pkg-config --libs lua)

# Build command
$CC src/main.cpp src/utils.cpp src/Entity/Entity.cpp src/Game/Game.cpp src/Engine/Console/Console.cpp src/Engine/Collisions/Collisions.cpp src/Engine/Transformation.cpp -o build/app $CFLAGS -I $INCLUDE_DIR -L $LIB_DIR -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -I"include/sol" $LUA_INCLUDE $LUA_LIBS

# Run the app
./build/app