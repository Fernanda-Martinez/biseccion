#include<iostream>
#include<iomanip>
#include "biseccion.h"
//using namespace std;
using std::cout;
using std::endl;
using namespace raices; 

int main (int argc, char *argv[]) {
	
	biseccion bis{[](double x) -> double{
		return exp(-x) - log(x); //log ->logaritmo natural ojo!!
	}
	};
	
double a = 1.0f;
double b = 1.5f;
double tolerancia = 0.00001f;
int maxIter = 100;

	raiz r = bis.calcular(a,b,tolerancia,maxIter);
	
	if(r.existe){
		cout<< 
			"la raiz entre: "<<a << " y "<<b<< " es "
			<<std::setprecision(7) <<r.valor<<" iteraciones"<<r.iteraciones
			<<endl;
	}else{
		cout <<"No se puedo encontar la raiz entre "<<
			a <<" y "<<b<<"luego de "<<r.iteraciones <<"iteraciones"<<endl;
	}
	return 0;
}

