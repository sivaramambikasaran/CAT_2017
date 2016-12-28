#include<iostream>
#include<fstream>
#include"CPLOT/cplot.hpp"
#include"CHEBYSHEV/Chebyshev.hpp"
#include<vector>

double PI	=	3.14159265358979323846;

void plot_To_File(std::vector<double> nodes) {
	int nNodes	=	nodes.size();
	std::vector<double> theta;
	double dtheta	=	180/nNodes;
	theta.push_back(0.5*dtheta);
	for (int j=1; j<nNodes;++j) {
		theta.push_back(theta[j-1]+dtheta);
	}
	std::ofstream myfile("Cheb_Nodes.tex",std::ios::out);
	myfile << "\\documentclass{standalone}\n";
	myfile << "\\usepackage{tikz}\n";
	myfile << "\\begin{document}\n";
	myfile << "\\begin{tikzpicture}\n";
	myfile << "\\draw (-1,0) -- (1,0);\n";
	myfile << "\\draw [smooth,domain=0:180] plot({cos(\\x)}, {sin(\\x)});\n";
	myfile << "\\foreach \\i in {0,...," << nNodes-1 << "} {\n";
	myfile << "\t \\draw [draw=red,fill=red] ({cos(0.5* " << dtheta << "+ \\i*" << dtheta << ")},{sin(0.5*" << dtheta << "+ \\i*" << dtheta << ")}) circle (0.01);\n";
	myfile << "\t \\draw [dashed, ultra thin] ({cos(0.5* " << dtheta << "+ \\i*" << dtheta << ")},{sin(0.5*" << dtheta << "+ \\i*" << dtheta << ")}) -- ({cos(0.5* " << dtheta << "+ \\i*" << dtheta << ")},0);\n";
	myfile << "\t \\draw [draw=blue,fill=blue] ({cos(0.5* " << dtheta << "+ \\i*" << dtheta << ")},0) circle (0.01);\n";
	myfile << "\t };\n";
	myfile << "\\end{tikzpicture}\n";
	myfile << "\\end{document}"	;
}

int main(int argc, char* argv[]) {
	Chebyshev A(atoi(argv[1]));
	plot_To_File(A.xNodes);
}
