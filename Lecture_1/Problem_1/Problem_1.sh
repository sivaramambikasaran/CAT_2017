#!/bin/bash

rm *.aux
rm *.log
rm *.gz
rm .*.lb
rm .DS_Store
rm a.out
rm Problem_1.o

g++ -Ofast Problem_1.cpp -o Problem_1.o

./Problem_1.o

pdflatex Interp_5.tex
pdflatex Interp_10.tex
pdflatex Interp_20.tex
pdflatex Interp_40.tex
pdflatex Interp_80.tex
pdflatex Interp_160.tex
pdflatex Interp_320.tex
pdflatex Interp_640.tex

rm *.aux
rm *.log
rm *.gz
rm .*.lb
rm .DS_Store
rm a.out
rm Problem_1.o