//METODO ITERATIVO DE PUNTO FIJO
/*ARAMAYO MARCA,Raul Martin*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
  int iter,imax,i;
  double XO,X,e;
printf("\nIngrese numero maximo de iteraciones: ");scanf("%d",&imax);
printf("\nIngrese presicion: "); scanf("%lf",&e); 
printf("\nIngrese solucion propuesta: ");scanf("%lf",&XO);
iter=0;
X=2*XO-1+exp(-2*XO);
while(fabs(X-XO)>e&&iter<imax)
{
     XO=X;
     X=2*XO-1+exp(-2*XO);
     iter=iter+1;
    printf("\nIteracion numero %d : %lf",iter,X);
}
if(fabs(X-XO)<e){printf("\nSolucion X=%lf\n",X);}
if(iter>=imax){printf("\nSe alcanzo el maximo de iteraciones.\n");}
  system("PAUSE");	
  return 0;
}
