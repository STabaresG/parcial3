//Main

#include "hiperbolica.h"


//Funciones de condiciones iniciales
double funcion1(double);
double funcion2(double);


int main()
{
  //Parametros del problema
  double l1 = 2;
  double T1 = 10;
  double alpha1 = 1/(4*M_PI);
  int m1 = 100;
  int N1 = 100;

  //Objeto de la clase Hiperbolica
  Hiperbolica onda(l1, T1, alpha1, m1, N1, &funcion1, &funcion2);
  onda.Solucion();

  string nombre_archivo = "analitico.txt";
  fstream archivo_salida(nombre_archivo.c_str(), ios::out);

  //Solucion analitica del problema
  for (int i=0; i<=m1; i++)
    {
      for (int j=0; j<=N1; j++){
	archivo_salida << fixed << setw(8) << setprecision(3) << sin(j*T1/N1)*sin(4*M_PI*i*l1/m1) << " ";
      }
      archivo_salida << "\n";
    }
  
  
  return 0;
}


double funcion2(double x)
{
  return sin(4*M_PI*x);
}

double funcion1(double x)
{
  return 0.0;
}
