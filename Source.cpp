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

std::vector<double> Napruga(double height, int n)
{
  std::vector<double> mas(n);
  for (int count = 0; count < n; ++count)
  {
    mas[count] = -(height/2) + count*(height/(n-1));
  }
  return mas;
}

int main()
{
  int yzel=1;
  int h;

  std::cout << "¬ведите количество узлов" << std::endl;
  std::cin >> yzel;
  std::cout << std::endl;

  std::cout << "¬ведите высоту" << std::endl;
  std::cin >> h;
  std::cout << std::endl;

  std::vector<double> nap = Napruga(h, yzel + 2);

  double res = Trapecion(nap,h);
  std::cout << res;
  return 0;
}