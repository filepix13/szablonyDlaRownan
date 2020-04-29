#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.hh"
#include "LZespolona.hh"
#include <iostream>


/*
  Klasa wektor modeluje pojęcie macierzy o 1 kolumnie i ROZMIAR wierszach
 */
template <class TYP, int ROZMIAR>
class Wektor 
{
  
  TYP dane[ROZMIAR];

  public:

  //Deklaracja konstruktora
  Wektor();

  //Deklaracja funkcji dodającej dwa wektory
  Wektor operator + (const Wektor & W2) const;

  //Deklaracja funkcji odejmującej dwa wektory
  Wektor operator - (const Wektor & W2) const;

  //Deklaracja funckji obliczającej iloczyn skalarny dwóch wektorów
  TYP operator * (const Wektor & W2) const;

  //Deklaracja funkcji mnożącej poszczególne elementy wektora przez liczbę
  Wektor operator * (TYP t) const;

  //Deklaracja przeciążenia funkcji indeksującej
  const TYP & operator [] (int indeks) const;

  //Deklaracja przeciążenia funkcji indeksującej
  TYP & operator[] (int indeks);  

};

/* 
  Funkcja wczytująca wektor ze strumienia wejściowego
*/
template <class TYP, int ROZMIAR>
std::istream & operator>> (std::istream & Strm, Wektor<TYP,ROZMIAR> & Wek);

/*
  Funkcja wyświetlająca wektor na strumień wejściowy
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> & Wek);


#endif
