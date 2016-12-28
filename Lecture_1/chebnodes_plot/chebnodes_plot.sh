#!/bin/bash

echo Enter number of Chebyshev nodes:

read nodes

echo Obtaining the Chebyshev nodes

./chebnodes_plot $nodes

echo Plotting them using tikz

pdflatex Cheb_Nodes.tex >output.txt

echo Opening the figure

open Cheb_Nodes.pdf

rm Cheb_Nodes.tex

rm Cheb_Nodes.aux

rm Cheb_Nodes.log

rm .Cheb_Nodes.lb

rm output.txt