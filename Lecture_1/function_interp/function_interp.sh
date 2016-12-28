#!/bin/bash

rm *.tex >output.txt

rm *.pdf >output.txt

echo Enter number of interpolation nodes:

read nodes

echo Obtaining the different interpolants

g++ -Ofast function_interp.cpp -o function_interp

./function_interp $nodes

echo Plotting the interpolants using tikz

pdflatex Actual_Function.tex >output.txt

pdflatex Cheb_interpolant.tex >output.txt

pdflatex Uniform_interpolant.tex >output.txt

open Actual_Function.pdf

open Cheb_interpolant.pdf

open Uniform_interpolant.pdf

rm *.log >output.txt

rm *.aux >output.txt

rm .*.lb >output.txt

rm function_interp >output.txt

rm output.txt