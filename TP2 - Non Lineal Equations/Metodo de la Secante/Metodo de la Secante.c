#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double funcion(double xo){return xo-1+exp(-2*xo);}
int main ()
{
	int iter, imax;
	double xo,x,e,c;
	printf("\nIngrese solucion propuesta: ");scanf("%lf",&xo);
	printf("\nPrecision: ");scanf("%lf",&e);
	printf("\nIngrese C: ");scanf("%lf",&c);
	printf("\nIngrese cantidad maxima de iteraciones: ");scanf("%d",&imax);
	iter=0;
	x=xo-funcion(xo)/((funcion(c)-funcion(xo))/(c-xo));
	while (fabs(x-xo)>e&&iter<imax)
	{
		xo=x;
		x=xo-funcion(xo)/((funcion(c)-funcion(xo))/(c-xo));
		iter++;	
		printf("\nIteracion numero: %lf",x);
	}
if(fabs(x-xo)<e){printf("\nSolucion hallada en la %d iteracion: X=%lf\n",iter,x);}
if(iter>=imax){printf("\nNumero maximo de iteraciones alcanzada.");}
system("PAUSE");
return 0;
}
