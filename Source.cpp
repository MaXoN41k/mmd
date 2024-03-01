#include <iostream>
#include <vector>

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

  while (yzel % 2 != 1)
  {
    std::cout << "¬ведите количество узлов (нечЄтное)" << std::endl;
    std::cin >> yzel;
    std::cout << std::endl;
  }

  std::cout << "¬ведите высоту" << std::endl;
  std::cin >> h;
  std::cout << std::endl;

  std::vector<double> nap = NaprugaCube(h, yzel + 2);

  //double res = Trapecion(nap, h);
  double res = Simpson(nap, h);
  std::cout << res;
  return 0;
}