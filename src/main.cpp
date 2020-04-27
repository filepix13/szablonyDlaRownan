#include <iostream>
#include "LZespolona.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"


int main()
{
  Macierz<LZespolona, 5> W;
  Macierz<LZespolona, 5> Z;

  std::cin >> W;
  Z = W.odwrotnosc();

  std::cout << Z;


  
}
