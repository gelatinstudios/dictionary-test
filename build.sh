#!/bin/bash
g++ main.cpp -o mike -DMIKE -lSDL2 -fno-exceptions -fno-rtti -O2 -g
g++ main.cpp -o dict -lSDL2 -fno-exceptions -fno-rtti -O2 -g
g++ average.cpp -o average -fno-exceptions -fno-rtti -O2 
