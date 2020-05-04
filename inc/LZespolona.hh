#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cstdlib>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  public:

  //Deklaracja funkcji przypisującej wartość części rzeczywistej liczy zespolonej
  LZespolona operator = (double a);

  //Deklaracja funkcji sumującej liczby zepolone
  LZespolona operator += (LZespolona Z);

  //Deklaracja funkcji mnożącej liczbę zespoloną z liczbą rzeczywistą
  LZespolona operator * (double d) const;

  //Deklaracja funkcji mnożącej liczby zepolone
  LZespolona operator *= (LZespolona Z);

  //Deklaracja funkcji porównującej dwie liczby zespolone(const)
  bool operator == (double d) const;

  //Deklaracja funkcji porównującej dwie liczby zespolone
  bool operator == (double d);

};

//Deklaracja funkcji obliczającej sprzeżenie liczby zespolonej
LZespolona Sprzezenie(LZespolona);

//Deklaracja funkcji obliczającej moduł z liczby zespolonej
double Modul2(LZespolona);

//Prównuje dwie liczby zespolone
bool Porownaj(LZespolona a, LZespolona b);

//Tworzy liczbę zepoloną
LZespolona Utworz(double re, double im);

//Wyświetla liczbę zespoloną
std::ostream &operator <<(std::ostream& StrmWy, const LZespolona &Lz);

//Wczytuje liczbę zespoloną
std::istream &operator >>(std::istream& StrmWe,LZespolona &Lz);

//Deklaracja funckji dodającej dwie liczby zespolonej
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funckji odejmującej dwie liczby zespolonej
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funckji mnożącej dwie liczby zespolonej
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funckji dzielącej dwie liczby zespolonej
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

//Deklaracja funkcji dzielącej liczbę zespoloną przez liczbę rzeczywistą
LZespolona  operator / (LZespolona &Skl1, double b);

//Porównuje dwie liczba zespolone
bool operator == (LZespolona Skl1, LZespolona Skl2);

#endif
