#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "CPLOT/cplot.hpp"
#include "CHEBYSHEV/Chebyshev.hpp"
#include "LAGRANGE/Lagrange.hpp"

int main() {
	int Nall[]	=	{5,10,20,50,100,200};
	double RMAX	=	RAND_MAX;
	for (int k=0; k<6; ++k) {
		int N	=	Nall[k];
		std::vector<double> xChebNodes	=	get_Standard_Chebyshev_Nodes(N);
		std::vector<double> xUniNodes;
		std::vector<double> fNodes;
		for (int j=0; j<N; ++j) {
			xUniNodes.push_back(-1.0+(2.0*j+1.0)/N);
			fNodes.push_back(rand()/RMAX);
		}
		Lagrange Chebinterp(xChebNodes, fNodes);
		std::ostringstream sCheb;
		sCheb << "Chebyshev_" << N << ".tex";
		Chebinterp.drawplot(-1,1,sCheb.str());
		Lagrange Uniforminterp(xUniNodes, fNodes);
		std::ostringstream sUni;
		sUni << "Uniform_" << N << ".tex";
		Uniforminterp.drawplot(-1,1,sUni.str());
	}
}