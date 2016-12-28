#include<iostream>
#include<cmath>
#include<vector>
#include"LAGRANGE/Lagrange.hpp"
#include"CPLOT/cplot.hpp"

double pi	=	3.141592653589793238;

void display_vector(std::vector<double> f) {
	int N	=	f.size();
	for (int j=0; j<N; ++j) {
		std::cout << f[j] << "\t";
	}
	std::cout << "\n";
}

// void find_max_min(std::vector<double> f, double& fmax, double& fmin){
// 	int N	=	f.size();
// 	fmin	=	f[0];
// 	fmax	=	f[0];
// 	for (int j=1; j<N; ++j) {
// 		if (fmin > f[j]) {
// 			fmin	=	f[j];
// 		}
// 		if (fmax < f[j]) {
// 			fmax	=	f[j];
// 		}
// 	}
// }

//	Returns the Chebyshev nodes
std::vector<double> cheb_Nodes(int nNodes) {
	std::vector<double> x;
	for (int j=-nNodes+1; j<nNodes; j+=2) {
		x.push_back(sin(0.5*pi/nNodes*j));
	}
	return x;
}

//	Returns the Chebyshev nodes
std::vector<double> cheb_Nodes(int nNodes, double center, double radius) {
	std::vector<double> x	=	cheb_Nodes(nNodes);
	for (int j=0; j<nNodes; ++j) {
		x[j]	=	center+radius*x[j];
	}
	return x;
}

//	The function we want to interpolate at a point 'x'
double myfunction(double x) {
	// return 1.0/(1.0+4*x*x);
	// return exp(-x*x);
	// return sin(10.0*x);
	return sin(5.0*x) + sin(25.0*x*x);
	// return exp(-fabs(x));
}

//	The function we want to interpolate at a set of nodes 'xNodes'
std::vector<double> myfunction(std::vector<double> xNodes) {
	int N	=	xNodes.size();
	std::vector<double> fNodes;
	for (int j=0; j<N; ++j) {
		fNodes.push_back(myfunction(xNodes[j]));
	}
	return fNodes;
}

int main(int argc, char* argv[]) {
	int N	=	atoi(argv[1]);
	int M	=	1000;

	/****************************************************/
	//	Actual function
	/****************************************************/
	
	//	The values at which we want to plot the function
	std::vector<double> x;
	for (int j=0; j<M; ++j) {
		x.push_back(-1.0+(2.0*j+1.0)/M);
	}

	//	Exact value of the function at the specified set of point where we want to plot
	std::vector<double> fexact		=	myfunction(x);
	//	Plot the actual function

	double fmax, fmin;
	find_max_min(fexact, fmax, fmin);

	cplot A("Actual_Function.tex");
	A.xlabel("x");
	A.ylabel("y");
	A.title("Actual Function");
	A.axes(-1,1,(1-0.1*fmin/fabs(fmin))*fmin,(1+0.1*fmax/fabs(fmax))*fmax);

	plot myplot;
	myplot.xdata(x);
	myplot.ydata(fexact);
	myplot.curve("","black","thick",true);
	myplot.marks("no marks", "");
	A.plots.push_back(myplot);
	A.makeplot();

	/****************************************************/
	//	Function interpolated using Chebyshev nodes
	/****************************************************/

	//	Obtain the Chebyshev nodes
	std::vector<double> xChebNodes	=	cheb_Nodes(N);

	//	Exact value of the function at the Chebyshev nodes
	std::vector<double> fChebNodes	=	myfunction(xChebNodes);

	//	Function interpolated using Chebyshev nodes
	Lagrange C(xChebNodes, fChebNodes);
	C.drawplot(-1,1,"Cheb_interpolant.tex");

	/****************************************************/
	//	Function interpolated using Uniform nodes
	/****************************************************/

	//	Uniform spaced nodes
	std::vector<double> xUniform;
	for (int j=0; j<N; ++j) {
		xUniform.push_back(-1.0+(2.0*j+1.0)/N);
	}

	//	Exact value of the function at Uniform nodes
	std::vector<double> fUniform	=	myfunction(xUniform);

	//	Function interpolated using Uniform nodes
	Lagrange U(xUniform, fUniform);
	U.drawplot(-1,1,"Uniform_interpolant.tex");
}