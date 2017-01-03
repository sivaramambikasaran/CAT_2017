#!/bin/bash

rm *.tex >output.txt

rm *.pdf >output.txt

# echo Enter number of interpolation nodes:

# read nodes

echo Obtaining the different interpolants

g++ -Ofast function_interp.cpp -o function_interp

./function_interp

echo Plotting the interpolants using tikz

pdflatex Actual_Function.tex >output.txt

pdflatex Cheb_interpolant_5.tex >output.txt

pdflatex Cheb_interpolant_10.tex >output.txt

pdflatex Cheb_interpolant_20.tex >output.txt

pdflatex Cheb_interpolant_40.tex >output.txt

pdflatex Cheb_interpolant_80.tex >output.txt

pdflatex Cheb_interpolant_160.tex >output.txt

pdflatex Cheb_interpolant_320.tex >output.txt

pdflatex Cheb_interpolant_640.tex >output.txt

pdflatex Uniform_interpolant_5.tex >output.txt

pdflatex Uniform_interpolant_10.tex >output.txt

pdflatex Uniform_interpolant_20.tex >output.txt

pdflatex Uniform_interpolant_40.tex >output.txt

pdflatex Uniform_interpolant_80.tex >output.txt

pdflatex Uniform_interpolant_160.tex >output.txt

pdflatex Uniform_interpolant_320.tex >output.txt

pdflatex Uniform_interpolant_640.tex >output.txt

rm *.log >output.txt

rm *.aux >output.txt

rm .*.lb >output.txt

rm function_interp >output.txt

rm output.txt

rm .DS_Store