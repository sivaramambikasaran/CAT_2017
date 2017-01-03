#!/bin/bash

rm *.tex >output.txt

rm *.pdf >output.txt

g++ -Ofast Chebyshev_Polynomials.cpp -o Chebyshev_Polynomials

./Chebyshev_Polynomials 100 7

pdflatex Chebyshev_Polynomials.tex >output.txt

rm *.log >output.txt

rm *.aux >output.txt

rm .*.lb >output.txt

rm function_interp >output.txt

rm output.txt

rm .DS_Store

rm Chebyshev_Polynomials

open Chebyshev_Polynomials.pdf