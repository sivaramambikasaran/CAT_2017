#include<iostream>
#include"CHEBYSHEV/Chebyshev.hpp"
#include"CPLOT/cplot.hpp"

int main(int argc, char* argv[]) {
	cplot A("Cheb_GM.tex");
	cplot B("Unif_GM.tex");
	int L	=	14;
	for (int l=L; l<L+1; ++l) {
		int N	=	pow(2.0,l)-1;
		std::vector<double> xNodes	=	get_Standard_Chebyshev_Nodes(N);
		std::vector<double> xUniform;
		for (int j=0; j<N; ++j) {
			xUniform.push_back(-1.0+(1.0+2.0*j)/N);
		}
		std::vector<double> logGeometricMean, geometricMean;
		std::vector<double> logUniformMean, uniformMean;
		for (int j=0;j<N; ++j) {
			logGeometricMean.push_back(0.0);
			logUniformMean.push_back(0.0);
			for (int k=0; k<j; ++k) {
				logGeometricMean[j]+=log(fabs(xNodes[k]-xNodes[j]));
				logUniformMean[j]+=log(fabs(xUniform[k]-xUniform[j]));
			}
			for (int k=j+1; k<N; ++k) {
				logGeometricMean[j]+=log(fabs(xNodes[k]-xNodes[j]));
				logUniformMean[j]+=log(fabs(xUniform[k]-xUniform[j]));
			}
			logGeometricMean[j]	=	logGeometricMean[j]/N;
			logUniformMean[j]	=	logUniformMean[j]/N;
			geometricMean.push_back(exp(logGeometricMean[j]));
			uniformMean.push_back(exp(logUniformMean[j]));
		}
		A.xlabel("Nodes");
		A.ylabel("Geometric mean distance");
		A.title("GM of Chebyshev nodes versus nodes");
		A.axes(-1,1,0.4,1.2);
		plot myplot;
		myplot.xdata(xNodes);
		myplot.ydata(geometricMean);
		myplot.marks("no marks","red");
		myplot.curve("thick", "blue", "" , false);
		A.plots.push_back(myplot);

		B.xlabel("Nodes");
		B.ylabel("Geometric mean distance");
		B.title("GM of Uniform nodes versus nodes");
		B.axes(-1,1,0.3,1);
		myplot.xdata(xUniform);
		myplot.ydata(uniformMean);
		myplot.marks("no marks","red");
		myplot.curve("thick", "blue", "" , false);
		B.plots.push_back(myplot);
	}
	A.makeplot();
	B.makeplot();
}