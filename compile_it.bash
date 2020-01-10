#!/bin/bash

bison -d parser.ypp
echo "starting flex"
flex scanner.lex
echo "starting g++"
g++ -std=c++11 *.c *.cpp -o hw5.exe