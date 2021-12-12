//METODO DE APROXIMACION DE PARAMETROS - REGRESION LINEAL
/*ARAMAYO MARCA RAUL MARTIN*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
  //Declaracion de variables
  int n, //Cantidad de datos experimentales
      p,  //cantidad de parametros
      i,j,k; //indices de control
  double x[30],
         y[30],
         e[30], //Vector solucion
         q, //Para Gauss
         s, //Sumatoria para Gauss
         a[30][30], //Matriz F
         b[30],     // Terminos independientes
         ap[30];    // Vector de parametros
  //CARGA DE DATOs
  printf("\nIngrese cantidad de datos: ");scanf("%d",&n);
  printf("\nIngrese cantidad de parametros: ");scanf("%d",&p);
  for(i=1;i<=p;i++)
  {
   printf("\nIngrese e[%d]=",i);scanf("%lf",&e[i]);
  }
 for(i=1;i<=n;i++)
  {
   printf("\nIngrese x[%d]=",i);scanf("%lf",&x[i]);
   printf("\nIngrese y[%d]=",i);scanf("%lf",&y[i]);
  }
 /*ALGORITMO*/ 
 for(i=1;i<=p;i++)
 {
                  for(j=1;j<=p;j++)
                  {
                                   a[i][j]=0;
                                   for(k=1;k<=n;k++)
                                   {
                                                    a[i][j]=a[i][j]+pow(x[k],e[i])*pow(x[k],e[j]);
                                   }
                  }
 }

 for(i=1;i<=n;i++)
 {
   printf("\n");
   printf("\tX[%d]=%lf",i,x[i]);
   printf("\tY[%d]=%lf",i,y[i]);                
 }
   printf("\nMatriz F:\n");
 for(i=1;i<=p;i++)
 {
                  for(j=1;j<=p;j++)
                  {
                                   printf("\t%lf",a[i][j]);
                  }
   printf("\n");
 }
 for(i=1;i<=p;i++)
 {
                  b[i]=0;
                  for(k=1;k<=n;k++)
                  {
                                   b[i]=b[i]+y[k]*pow(x[k],e[i]);
                  }
 }
 printf("\nVector de coeficientes independientes: \n"); 
 for(i=1;i<=p;i++){printf("\t%lf",b[i]);};  printf("\n");
 printf("Aplicaremos el algoritmo de Gauss:");
 //ESCALONAMIENTO
 for(k=1;k<=p-1;k++)
 {
 	for(i=k+1;i<=p;i++)
 	{
 	   q=a[i][k]/a[k][k];
 	   a[i][k]=0;
 	   b[i]=b[i]-q*b[k];
 	   for(j=k+1;j<=p;j++)
 	   {
 	   	a[i][j]=a[i][j]-q*a[k][j];
 	   }//FIN j
 	}//FIN i
 }//FIN k
 //SUSTITUCION INVERSA
 e[p]=b[p]/a[p][p];
 for(i=p-1;i>=1;i--)
 {
 	s=0;
 	for(j=i+1;j<=n;j++)
 	{
 		s=s+a[i][j]*e[j];
 	}//FIN j
 	e[i]=(b[i]-s)/a[i][i];
 }//FIN i
 //MOSTRANDO RESULTADOS
 printf("\nMatriz Resultante escalonada: \n");
 for(i=1;i<=p;i++)
 {
                  for(j=1;j<=p;j++)
                  {
                                   printf("\t%lf",a[i][j]);
                  }
   printf("\n");
 }
 printf("Soluciones halladas: \n");
 for(i=1;i<=p;i++){printf("\t%lf",e[i]);};  printf("\n"); 
  system("PAUSE");	
  return 0;
}
