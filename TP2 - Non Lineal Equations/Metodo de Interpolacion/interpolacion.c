//METODO DE INTERPOLACION
/*ARAMAYO MARCA, Raul Martin*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//Funciones
double f(double xm){ return (xm*xm)/4-sin(xm);}
int main()
{
int ef;
double xi,xd,xm,e;
printf("\nIngrese extremo izquierdo del intervalo: "); scanf("%lf",&xi);  
printf("\nIngrese extremo derecho del intervalo: "); scanf("%lf",&xd);
printf("\nIngrese presicion: "); scanf("%lf",&e);
ef=0;
xm=(xd*f(xi)-xi*f(xd))/(f(xi)-f(xd));
while(fabs(xd-xi)>e)
{
	if(f(xi)*f(xd)<0){xm=(xd*f(xi)-xi*f(xd))/(f(xi)-f(xd));}
	if(f(xm)*f(xi)>=0){xi=xm;/*achico por izquierda*/}
	if(f(xm)*f(xd)>=0){xd=xm;/*achico por derecha*/}
	ef++;
}
if(fabs(xi-xd)<e)
{
  printf("\nSolucion encontrada: X=%lf\n",xm);
  printf("Funcion evaluada en la solucion: f(x)=%lf\n ",f(xm));
  printf("\nLa funcion fue evaluada %d veces.\n",ef);
}
  system("PAUSE");	
  return 0;
}
