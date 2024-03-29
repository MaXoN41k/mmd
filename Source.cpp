#include <iostream>
#include <vector>
#include <Math.h>

double Trapecion(std::vector<double> Napruga1, double h)
{
  int n = Napruga1.size();
  double step = (h / (n-1));
  double res = (step / 2) * (Napruga1[0] + Napruga1[n - 1]);
  for (int count = 1; count < n-1; ++count)
  {
    res += step * Napruga1[count];
  }
  return res;
}

double Simpson(std::vector<double> Napruga1, double h)
{
  int n = Napruga1.size();
  double step = (h / (n - 1));
  double res =(Napruga1[0] + Napruga1[n - 1]);
  for (int count = 1; count < n - 1; ++count)
  {
    if (count % 2 == 1)
    {
      res += 4 * Napruga1[count];
    }
    else if (count % 2 == 0)
    {
      res += 2 * Napruga1[count];
    }
  }
  return res*step/3;
}

double Gauss3(std::vector<double> Napruga1, double h)
{
  int n = Napruga1.size();
  std::vector<double> korny(3);
  std::vector<double> koefs(3);
  korny[0] = (-1) * sqrt(3.0 / 5.0); korny[1] = 0.0; korny[2] = sqrt(3.0 / 5.0);
  double xk;
  double res = 0.0;
  for (int count = 0; count < 3; ++count)
  {
    xk = (korny[count]);
    koefs[count] = ((2.0 * (1.0 - (xk * xk))) / (9.0 * ((1.0 / 2.0) * ((3.0 * xk * xk) - 1.0)) * ((1.0 / 2.0) * ((3.0 * xk * xk) - 1.0))));
  }

  for (int count = 0; count < 3; ++count)
  {
    res += Napruga1[count] * koefs[count];
  }
  res = res * (h / 2.0);
  return res;
}

double Gauss5(std::vector<double> Napruga1, double h)
{
  int n = Napruga1.size();
  std::vector<double> korny(5);
  std::vector<double> koefs(5);
  korny[0] = (-1.0) * sqrt(((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0))) + (5.0 / 9.0)); korny[1] = (-1.0) * sqrt((5.0 / 9.0) - ((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0)))); korny[2] = 0.0; korny[3] = sqrt((5.0 / 9.0) - ((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0)))); korny[4] = sqrt(((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0))) + (5.0 / 9.0));
  double xk;
  double res = 0.0;
  for (int count = 0; count < 5; ++count)
  {
    xk = (korny[count]);
    koefs[count] = ((2.0 * (1.0 - (xk * xk))) / (25.0 * ((1.0 / 8.0) * ((35.0 * xk * xk * xk * xk) - (30.0 * xk * xk) + 3.0)) * ((1.0 / 8.0) * ((35.0 * xk * xk * xk * xk) - (30.0 * xk * xk) + 3.0))));
  }

  for (int count = 0; count < 5; ++count)
  {
    res += Napruga1[count] * koefs[count];
  }
  res = res * (h / 2.0);
  return res;
}

std::vector<double> NaprugaGauss3(double h, int k)
{
  std::vector<double> mas(3);
  std::vector<double> korny(3);;
  korny[0] = (-1) * sqrt(3.0 / 5.0); korny[1] = 0.0; korny[2] = sqrt(3.0 / 5.0);
  double xk;
  for (int count = 0; count < 3; ++count)
  {
    xk = (h / 2.0) * (korny[count]);
    mas[count] = pow(xk,k);
    std::cout << "«начение в узле " << count << ":" << mas[count] << std::endl;
  }
  return mas;
}

std::vector<double> NaprugaGauss5(double h, int k)
{
  std::vector<double> mas(5);
  std::vector<double> korny(5);
  korny[0] = (-1.0) * sqrt(((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0))) + (5.0 / 9.0)); korny[1] = (-1.0) * sqrt((5.0 / 9.0) - ((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0)))); korny[2] = 0.0; korny[3] = sqrt((5.0 / 9.0) - ((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0)))); korny[4] = sqrt(((2.0 * sqrt(10.0)) / (9.0 * sqrt(7.0))) + (5.0 / 9.0));
  double xk;
  for (int count = 0; count < 5; ++count)
  {
    xk = (h / 2.0) * (korny[count]);
    mas[count] = pow(xk, k);
    std::cout << "«начение в узле " << count << ":" << mas[count] << std::endl;
  }
  return mas;
}

//lin
std::vector<double> NaprugaLin(double height, int n)
{
  std::vector<double> mas(n);
  for (int count = 0; count < n; ++count)
  {
    mas[count] = -(height/2) + count*(height/(n-1));
    std::cout << "«начение в узле " << count << ":" << mas[count] << std::endl;
  }
  return mas;
}

//cube
std::vector<double> NaprugaCube(double height, int n)
{
  std::vector<double> mas(n);
  for (int count = 0; count < n; ++count)
  {
    mas[count] = (-(height / 2) + count * ((height / (n - 1)))) * (-(height / 2) + count * ((height / (n - 1)))) * (-(height / 2) + count * ((height / (n - 1))));
    std::cout << "«начение в узле " << count << ":" << mas[count] << std::endl;
  }
  return mas;
}

//const
std::vector<double> NaprugaConst(double height, int n)
{
  std::vector<double> mas(n);
  for (int count = 0; count < n; ++count)
  {
    mas[count] = 5;
    std::cout << "«начение в узле " << count << ": " << mas[count] << std::endl;
  }
  return mas;
}

//prarab
std::vector<double> NaprugaParab(double height, int n)
{
  std::vector<double> mas(n);
  for (int count = 0; count < n; ++count)
  {
    mas[count] = (-(height / 2) + count * ((height / (n - 1))))*(-(height / 2) + count * ((height / (n - 1))));
    std::cout << "«начение в узле " << count <<":"<< mas[count] << std::endl;
  }
  return mas;
}

//kvadro
std::vector<double> NaprugaQadr(double height, int n)
{
  std::vector<double> mas(n);
  for (int count = 0; count < n; ++count)
  {
    mas[count] = (-(height / 2) + count * ((height / (n - 1)))) * (-(height / 2) + count * ((height / (n - 1)))) * (-(height / 2) + count * ((height / (n - 1)))) * (-(height / 2) + count * ((height / (n - 1))));
    std::cout << "«начение в узле " << count << ":" << mas[count] << std::endl;
  }
  return mas;
}

int main()
{
  setlocale(LC_ALL,"rus");
  int yzel=0;
  int h;

  //while (yzel % 2 != 1)
  //{
  //  std::cout << "¬ведите количество узлов (нечЄтное)" << std::endl;
  //  std::cin >> yzel;
  //  std::cout << std::endl;
  //}

  std::cout << "¬ведите высоту" << std::endl;
  std::cin >> h;
  std::cout << std::endl;

  //std::vector<double> nap = NaprugaQadr(h, yzel + 2);
  std::vector<double> nap = NaprugaGauss5(h, 6);

  //double res = Trapecion(nap, h);
  //double res = Simpson(nap, h);

  double res = Gauss5(nap, h);
  std::cout << res;
  return 0;
}