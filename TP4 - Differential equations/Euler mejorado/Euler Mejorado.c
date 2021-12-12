/*METODO DE EULER MEJORADO*/
#include <stdio.h>
#include <stdlib.h>
double f(double xo,double yo){return 2*xo+yo;}
int main()
{
  double xo,xf,h,yo,ys;
  printf("\nIngrese valor de x inicial: ");scanf("%lf",&xo);
  printf("\nIngrese valor de y inicial: ");scanf("%lf",&yo);
  printf("\nIngrese valor de x final: ");scanf("%lf",&xf);
  printf("\nIngrese paso: ");scanf("%lf",&h);
  printf("\nTabla de valores: \n\tX\t\tY");
while(xo<=xf)
{
             ys=yo+h*f(xo,yo);
             yo=yo+h/2*(f(xo,yo)+f(xo+h,ys));
             xo=xo+h;
             printf("\n %lf , \t %lf",xo,yo);

}
 printf("\n");
  system("PAUSE");	
  return 0;
}
