#include<iostream>
#include<vector>
#include<cmath>
#include<sstream>
#include<cstdlib>
#include"CHEBYSHEV/Chebyshev.hpp"
#include"LAGRANGE/Lagrange.hpp"
#include"CPLOT/cplot.hpp"

int main(int argc, char* argv[]) {
	std::vector<int> Nall;
	Nall.push_back(5);
	for (int j=0; j<7; ++j) {
		Nall.push_back(2*Nall[j]);
	}
	srand(time(NULL));
	double RMAX	=	RAND_MAX;
	for (int j=0; j<Nall.size(); ++j) {
		int N	=	Nall[j];
		std::vector<double> fNodes;
		std::vector<double> xNodes	=	get_Standard_Chebyshev_Nodes(N);
		for (int k=0; k<N; ++k) {
			fNodes.push_back(rand()/RMAX);
		}
		Lagrange L(xNodes, fNodes);
		std::ostringstream fileName;
		fileName << "Interp_" << N << ".tex";
		L.drawplot(-1,1,fileName.str());
	}
}