//METODO DE NEWTON RAPHSON
/*ARAMAYO MARCA, Raul Martin*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
  int iter,imax;
  double XO,X,e,f,d; //valor propuesto, valor de iteracion,presicion,funcion,derivada
printf("\nIngrese cantidad maxima de iteraciones: ");scanf("%d",&imax);
printf("\nIngrese precision: ");scanf("%lf",&e);
printf("\nIngrese solucion propuesta: ");scanf("%lf",&XO);
f=XO-1+exp(-2*XO);
d=1-2*exp(-2*XO);
X=XO-f/d;
iter=0;
while(fabs(X-XO)>e&&iter<imax)
{
       XO=X;
      f=XO-1+exp(-2*XO);
	  d=1-2*exp(-2*XO);	  
  X=XO-f/d;
  printf("\nIteracion N°: %d X=%lf",iter,X);
  iter++;                    
}
if(fabs(X-XO)<e){printf("\nSolucion hallada en la iteracion %d: X=%lf\n",iter,X);}
if(iter>=imax){printf("\nNumero de iteraciones maximo alcanzada.\n");}

  system("PAUSE");	
  return 0;
};
