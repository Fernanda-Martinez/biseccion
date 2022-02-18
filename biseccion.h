#ifndef BISECCION_H
#define BISECCION_H
#include<cmath>
#include <functional>

using std::cout;
using std::endl;
using std::function;

namespace raices{//namespace son paquetes 

	struct raiz{
		bool existe;
		double valor;
		int iteraciones; 
		double error; 
	};


	class biseccion{
		/*
		*
		*/
	public:
		biseccion(
				  function<double(double)> p_f
				  ): f(p_f){
			
		}
		raiz calcular( double a, double b,double tol, int maxIter){
			raiz r; 
			r.existe = false; 
			//paso 1
			r.iteraciones  = 1; 
			//paso 2
			double xant = (a+b)/2;
			
			if(f(a)*f(xant) > 0.0f){
				//no hay cambio de singno entre a y xant
				a = xant; 
			}else{
				//hay cambio de signo entre a y xant
				b = xant;
			}
			
			//paso 3
			while(r.iteraciones<= maxIter){
				double xnueva = (a+b)/2;
				//calculo de error
				r.error  = fabs((xnueva - xant)/xnueva);
				
				//paso 5
				if(r.error < tol || fabs(f(xnueva)) < tol){
					r.existe = true;
					r.valor = xnueva;
					return r;
				}
				
				//paso 6;
				r.iteraciones ++;
				
				//paso 7
				if(f(a)* f(xnueva)> 0.0f){
					a = xnueva;
				}else{
					b = xnueva; 
				}
				xant = xnueva;
			}
			
			return r; 
		}
	private:
		function <double(double)> f;
	};

};

#endif
