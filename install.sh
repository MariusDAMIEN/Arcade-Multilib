#!/bin/bash

echo -e "\e[32m*****************\e[0m"
echo -e "\e[32m*installing sfml*\e[0m"
echo -e "\e[32m*****************\e[0m"
sudo apt-get install libsfml-dev

echo -e "\e[32m**********************\e[0m"
echo -e "\e[32m*setting path library*\e[0m"
echo -e "\e[32m**********************\e[0m"
export LD_LIBRARY_PATH=./lib:./:./games

echo -e "\e[32m********************\e[0m"
echo -e "\e[32m*installing allegro*\e[0m"
echo -e "\e[32m********************\e[0m"
sudo add-apt-repository ppa:allegro/5.2
sudo apt-get update
sudo apt-get install liballegro5-dev
