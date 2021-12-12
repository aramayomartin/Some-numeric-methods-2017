/*METODO DE RUNGE KUTTA*/
#include <stdio.h>
#include <stdlib.h>
double f(double xo,double yo){return 2*xo+yo;}
int main()
{
  double xo,xf,h,yo,k1,k2,k3,k4;
  printf("\nIngrese valor de x inicial: ");scanf("%lf",&xo);
  printf("\nIngrese valor de y inicial: ");scanf("%lf",&yo);
  printf("\nIngrese valor de x final: ");scanf("%lf",&xf);

  printf("\nIngrese paso: ");scanf("%lf",&h);
  printf("\nTabla de valores: \n\tX\t\tY");
while(xo<=xf)
{
             k1=f(xo,yo);
             k2=f(xo+h/2,yo+h/2*k1);
             k3=f(xo+h/2,yo+h/2*k2);
             k4=f(xo+h/2,yo+h/2*k3);
             yo=yo+h/6*(k1+2*k2+2*k3+k4);
             xo=xo+h;
             printf("\n %lf , \t %lf",xo,yo);


}
 printf("\n");
  system("PAUSE");	
  return 0;
}
