#!/bin/bash

echo -e "\e[32m*****************\e[0m"
echo -e "\e[32m*installing sfml*\e[0m"
echo -e "\e[32m*****************\e[0m"
sudo apt-get install libsfml-dev

echo -e "\e[32m**********************\e[0m"
echo -e "\e[32m*setting path library*\e[0m"
echo -e "\e[32m**********************\e[0m"
export LD_LIBRARY_PATH=./lib:./:./games