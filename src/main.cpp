#include <iostream>
#include "LZespolona.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"


int main()
{
  char c;
  UkladRownanLiniowych <double, 5> D;
  UkladRownanLiniowych <LZespolona, 5> Z;

  std::cin >> c;

  if(c == 'r')
  {
    std::cout << "Układ równań liniowych o współczynnikach rzeczywistych" << std::endl << std::endl;
    std::cout << "Macierz A^T oraz wektor wyrazów wolnych b:" << std::endl;
    std::cin >> D;
    
    std::cout << std::endl <<"Rozwiazanie x = (x1, x2, x3, x4, x5):" << std::endl;

    std::cout << D.Oblicz() << std::endl;

    std::cout << "Wektor błędu: Ax-B = " << D.Blad();
  }
  else if(c == 'u')
  {
    std::cout << "Układ równań liniowych o współczynnikach urojonych" << std::endl << std::endl;
    std::cout << "Macierz A^T oraz wektor wyrazów wolnych b:" << std::endl;
    std::cin >> Z;
    
    std::cout << std::endl <<"Rozwiazanie x = (x1, x2, x3, x4, x5):" << std::endl;

    std::cout << Z.Oblicz() << std::endl;

    std::cout << "Wektor błędu: Ax-B = " << Z.Blad();
  }
    
  else
  {
    std::cout << "Błędny format liczby. Możliwe formaty r (rzeczywiste) lub u (urojone)." << std::endl;
    exit(1);
  }
}
