#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*ARAMAYO MARCA, Raúl Martín*/
int main()
{
/*ZONA DE DECLARACION DE VARIABLES*/
	int n, //Grado del polinomio
		imax, //maximo de iteraciones
		ki, //contador de iteraciones
		i,//indice de control
		k;//indice de control
	double xo, //punto inicial
			x, //variable 
			e, //presicion
			f, //funcion
			fp, //derivada de la funcion
			a[20], //vector de coeficientes
			b[20]; //vector de coeficientes para hacer ruffini
/*ZONA DE INGRESO DE DATOS*/
printf("\nIngrese el grado del polinomio: ");scanf("%d",&n);
printf("\nIngrese punto inicial: ");scanf("%lf",&xo);
printf("\nIngrese presicion: ");scanf("%lf",&e);
printf("\nCantidad maxima de iteraciones: ");scanf("%d",&imax);
printf("\nPolinomios de la forma: A(n+1)X^n+A(n)X^n-1.....A(1)\n");
for(i=n+1;i>=1;i--)
{
	printf("Ingrese el coeficiente A[%d]=",i);scanf("%lf",&a[i]);
}
printf("\nSoluciones: \n");
/*ZONA DE OPERACIONES*/
while (n>2)
{
	//Esta parte se hace para poder entrar al algoritmo de NEWTON RAPHSON
	f=0;
	for(i=1;i<=n+1;i++)	{f=f+a[i]*pow(xo,i-1);}//Arma el polinomio
	fp=0;
	for(i=2;i<=n+1;i++){fp=fp+(i-1)*a[i]*pow(xo,i-2);} //Arma la derivada
/*ENTRAMOS A NEWTON RAPHSON*/
ki=0; //inicializamos el contador de iteraciones en cero
x=xo-(f/fp);
while(fabs(x-xo)>e&&ki<=imax)
{
	xo=x;
	f=0;
	for(i=1;i<=n+1;i++)	{f=f+a[i]*pow(xo,i-1);}//Arma el polinomio
	fp=0;
	for(i=2;i<=n+1;i++){fp=fp+(i-1)*a[i]*pow(xo,i-2);} //Arma la derivada
	ki++; //contador de iteracoines incrementando
	x=xo-(f/fp);	
}
if(fabs(x-xo)<e)
{
	printf("\nX=%lf",x);
}//finaliza el if

	//METODO DE RUFFINI
	b[n+1]=0;
	for(k=0;k<=n-1;k++)
	{
		b[n-k]=x*b[n-k+1]+a[n-k+1];
	}
	n=n-1;
	for(i=1;i<=n+1;i++){a[i]=b[i];}
	xo=x;
}//finaliza el while
if(ki>=imax){printf("\nNumero maximo de iteraciones alcanzado.");}
if(n==2)
{
//Calcularemos las ultimas 2 raices
if((a[2]*a[2]-4*a[3]*a[1])>=0)
{
printf("\nX=%lf",(-a[2]+sqrt(a[2]*a[2]-4*a[3]*a[1]))/(2*a[3]));
printf("\nX=%lf\n",(-a[2]-sqrt(a[2]*a[2]-4*a[3]*a[1]))/(2*a[3]));
}
	else 
	{
	printf("\nX=%lf +  %lfi\n",(-a[2]/(2*a[3])),(sqrt(-1*(a[2]*a[2]-4*a[3]*a[1]))/(2*a[3]))) ;	
	printf("\nX=%lf %lfi\n",(-a[2]/(2*a[3])),(-sqrt(-1*(a[2]*a[2]-4*a[3]*a[1]))/(2*a[3]))) ;	
	}
/*TERMINA TODO EL ALGORITMO*/	
system ("PAUSE");
return 0;
}
}
