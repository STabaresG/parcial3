#include "hiperbolica.h"

//Implementacion

//Constructor
Hiperbolica::Hiperbolica(double x_max, double t_max, double alpha, int m1, int N1, double (*f) (double x1), double (*g) (double x2))
{
  l = x_max;  //Longitud intervalo
  T = t_max;  //Tiempo intervalo
  m = m1;     //Cantidad divisiones intervalo l
  N = N1;     //Cantidad divisiones intervalo T
  h = l/m;    //Paso espacial
  k = T/N;    //Paso temporal
  lambda = alpha*k/h;  

  //Guardar valores f y g en t0
  for (int i=0; i<=m; i++)
    {
      f_t0.push_back(f(i*h));
      g_t0.push_back(g(i*h));
    }  
}

//Crea archivo con los valores de x y t
void Hiperbolica::Solucion()
{
  double soluciones[m+1][N+1];  //Matriz para guardar los datos
  string nombre_archivo = "solucionNumerica.txt";
  fstream archivo_sol(nombre_archivo.c_str(), ios::out);

  for (int i=1; i<=m; i++)
    {
      if (i == 0 or i == m)
	{
	  //Condiciones iniciales en los extremos
	  soluciones[i][0] = 0.0;
	  soluciones[i][1] = 0.0;
	}

      else
	{
	  soluciones[i][0] = f_t0[i];  //Condiciones iniciaes en todos los puntos
	  soluciones[i][1] = (1 - lambda*lambda)*f_t0[i] + lambda*lambda*f_t0[i+1]/2 + lambda*lambda*f_t0[i-1]/2 + k*g_t0[i];  //Solucion en t_1
	}
    }

  //Solucion en todo el espacio en cada tiempo
  for (int j=1; j<N; j++)  //Para el tiempo
    {
      for (int i=0; i<=m; i++)  //Para el espacio
	{
	  if (i == 0 or i == m)
	    {
	      soluciones[i][j+1] = 0.0;  //Condiciones en los extremos
	    }
	  
	  else
	    {
	      soluciones[i][j+1] = 2*(1 - lambda*lambda)*soluciones[i][j] + lambda*lambda*(soluciones[i+1][j] + soluciones[i-1][j]) - soluciones[i][j-1];  //Solucion del siguiente tiempo
	    }
	}
    }

  //Guardar soluciones en el archivo
  for (int i=0; i<=m; i++)
    {
      archivo_sol << fixed;
      
      for (int j=0; j<=N; j++)
	{
	  archivo_sol << setw(8) << setprecision(3) << soluciones[i][j] << " ";
	}
      archivo_sol << "\n";
    }
}

