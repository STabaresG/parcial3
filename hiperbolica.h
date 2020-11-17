#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

//Definicion de clase para solucionar una ED hiperbolica con condiciones de frontera especificas

class Hiperbolica
{
public:
  Hiperbolica(double, double, double, int, int, double (*) (double), double (*) (double));
  void Solucion();
 

private:
  double l, T, lambda, h, k;
  int m, N;
  vector <double> f_t0, g_t0;
};
