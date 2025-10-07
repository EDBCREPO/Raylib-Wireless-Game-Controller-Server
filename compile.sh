export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH

if [ ! -d "build" ]; then
    mkdir "build"
fi

#LINUX
g++ main.cpp -o ./build/main -L./lib -I./include -lz -lssl -lcrypto -lraylib; ./build/main

#WINDOWS
#g++ main.cpp -o ./build/main.exe -L./lib -I./include -lz -lssl -lcrypto -lraylib -lws2_32 -lwinmm -lgdi32 ; ./build/main.exe