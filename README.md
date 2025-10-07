# Game Controller Server

A real-time 3D game controller system that combines a C++ game engine with a web-based touch interface. Control 3D objects in real-time using dual virtual joysticks from any mobile device.
Features

- 🎮: Dual Joystick Control: Touch-based movement and rotation controls
- 🌐: Web Interface: Responsive HTML5 controller accessible from any device
- ⚡: Real-time Communication: WebSocket-based bidirectional communication
- 🎯: 3D Graphics: Raylib-powered 3D rendering with texture support
- 📱: Mobile Optimized: Touch-optimized interface with smooth controls

## Architecture
```bash
┌─────────────────┐    WebSocket    ┌──────────────────┐
│   Web Client    │ ◄─────────────► │   C++ Server     │
│  (HTML/JS)      │    JSON Msgs    │ (NodePP + Raylib)│
│   *Dual Joystick│                 │    *Game Engine  │
│   *Touch Input  │                 │    *3D Rendering │
└─────────────────┘                 └──────────────────┘
```

## Prerequisites
- C++11 compatible compiler
- NodePP framework
- Raylib graphics library
- Web browser with touch support (mobile recommended)

## Install Process
```bash
# clone the project
git clone repo ; cd repo

#LINUX
g++ main.cpp -o ./build/main -L./lib -I./include -lz -lssl -lcrypto -lraylib; ./build/main

#WINDOWS
#g++ main.cpp -o ./build/main.exe -L./lib -I./include -lz -lssl -lcrypto -lraylib -lws2_32 -lwinmm -lgdi32 ; ./build/main.exe
```


## Contribution
[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/edbc_repo)