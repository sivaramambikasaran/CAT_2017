#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "CHEBYSHEV/Chebyshev.hpp"
#include "CPLOT/cplot.hpp"

int main(int argc, char* argv[]) {
	int N		=	atoi(argv[1]);	//	Number of nodes for plotting
	int nPoly	=	atoi(argv[2]);	//	Number of Chebyshev polynomials
	std::vector<double> x;
	for (int j=0; j<N; ++j) {
		x.push_back(-1.0+(2.0*j+1.0)/N);
	}
	std::vector<std::vector<double> > T	= get_Chebyshev_Polynomials(x, nPoly);

	std::string color[] = {"red","blue","black","magenta","violet","yellow","orange","green"};

	cplot A("Chebyshev_Polynomials.tex");
	A.xlabel("x");
	A.ylabel("Chebyshev Polynomials");
	A.title("Different Chebyshev Polynomials");
	A.axes(-1.0,1.0,-1.25,1.25);

	std::ostringstream legend;

	for (int j=0; j<=nPoly; ++j) {
		plot myplot;
		myplot.xdata(x);
		myplot.ydata(T[j]);
		myplot.curve("thick",color[j%8],"",true);
		myplot.marks("no marks","");
		legend << "$T_" << j <<"$,";
		A.plots.push_back(myplot);
	}

	A.legend(legend.str(),1,0,"south west");
	A.makeplot();
}
