/*METODO DE LA BISECCION*/
/*ARAMAYO MARCA, Raul Martin*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//Zona de funciones
double f(double xm){return (xm*xm)/4-sin(xm);}
int main() 
{
	//Declaracion de variables
	int ef; //Contador 
	double xi,xd,xm,e; //limite izquierdo y derecho, punto medio y presicion
	printf("\nIngrese extremo inferior del intervalo: ");scanf("%lf",&xi);
	printf("\nIngrese extremo superior del intervalo: ");scanf("%lf",&xd);
	printf("\nIngrese presicion: ");scanf("%lf",&e);
ef=0;//iniciando contador
xm=(xi+xd)/2;
while(fabs(xd-xi)>e)
{
	if(f(xi)*f(xd)<0){xm=(xi+xd)/2;}
	if(f(xm)*f(xi)>=0){xi=xm;/*achico por izquierda*/}
	if(f(xm)*f(xd)>=0){xd=xm;/*achico por derecha*/}
	ef++;
	printf("Biseccion numero %d xm=%lf\n",ef,xm);
}
if(fabs(xd-xi)<e){printf("\nSolucion encontrada en %d bisecciones X= %lf \n",ef,xm);}
	system("PAUSE");
	return 0;
}
