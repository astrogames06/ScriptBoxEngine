em++ -o build/index.html src/main.cpp src/Entity/Entity.cpp src/Game/Game.cpp -std=c++17 -Os -Wall ./llib/libraylib.a -I. -I include/ -L. -L llib/ -I"include/sol" -llua54 -s USE_GLFW=3 --shell-file build/shell.html -DPLATFORM_WEB