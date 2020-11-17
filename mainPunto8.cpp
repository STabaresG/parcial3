//Main

#include "hiperbolica.h"

//Funciones de condiciones iniciales
double I(double);
double dI(double);

int main()
{
  //Parametros del problema
  double l1 = 200;
  double C = 0.1;
  double L = 0.3;
  
  double T1 = 30;
  double alpha1 = 1/sqrt(L*C);
  int m1 = 10;
  int N1 = 10;

  //Objeto de la clase Hiperbolica
  Hiperbolica corriente(l1, T1, alpha1, m1, N1, &I, &dI);
  corriente.Solucion();

  string nombre_archivo = "analitico.txt";
  fstream archivo_salida(nombre_archivo.c_str(), ios::out);

  //Solucion analitica del problema
  for (int i=0; i<=m1; i++)
    {
      for (int j=0; j<=N1; j++){
	archivo_salida << fixed << setw(8) << setprecision(3) << 5.5*cos(alpha1*M_PI*j*T1/(200*N1))*sin(M_PI*i*l1/(200*m1)) << " ";
      }
      archivo_salida << "\n";
    }
  
  return 0;
}


double I(double x)
{
  return 5.5*sin(M_PI*x/200);
}

double dI(double x)
{
  return 0.0;
}
