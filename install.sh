#!/bin/bash

echo -e "\e[32m*****************\e[0m"
echo -e "\e[32m*installing sfml*\e[0m"
echo -e "\e[32m*****************\e[0m"
sudo apt-get install libsfml-dev

echo -e "\e[32m**********************\e[0m"
echo -e "\e[32m*setting path library*\e[0m"
echo -e "\e[32m**********************\e[0m"
export LD_LIBRARY_PATH=./lib:./:./games

echo -e "\e[32m**********************\e[0m"
echo -e "\e[32m*installing OpenGL*\e[0m"
echo -e "\e[32m**********************\e[0m"
sudo apt-get install freeglut3 freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev mesa-common-dev
sudo apt-get install xorg-dev libgl1-mesa-dev
sudo apt-get install libglfw3-dev freeglut3 freeglut3-dev libglfw3 libglfw3-dev
sudo apt-get install libsoil-dev libglm-dev libassimp-dev libglew-dev libglfw3-dev libxinerama-dev libxcursor-dev libxi-dev

echo -e "\e[32m**************\e[0m"
echo -e "\e[32m*install sdl2*\e[0m"
echo -e "\e[32m**************\e[0m"
sudo apt-get install libsdl2-dev 
git clone https://github.com/dhewg/libsdl.git
cd libsdl
chmod +x configure
sudo ./configure
make
sudo make install
sudo ln -s /usr/local/bin/sdl2-config /usr/bin/sdl2-config
cd ..
rm -rf libsdl
