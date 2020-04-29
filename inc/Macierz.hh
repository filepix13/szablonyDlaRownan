#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.hh"
#include <iostream>
#include <algorithm> 

/*
  Klasa Macierz modeluje pojęcie macierzy kwadratowej o ROZMIAR kolumnach i ROZMIAR wierszach
 */
template <class TYP, int ROZMIAR>
class Macierz 
{
  Wektor<TYP,ROZMIAR> tab[ROZMIAR];
  
  public:
  //Deklaracja konstruktora
  Macierz();

  //Deklaracja przeciążenia operatora indeksującego(const)
  const Wektor<TYP,ROZMIAR> & operator[] (int indeks) const;

  //Deklaracja przeciążenia operatora indeksującego
  Wektor<TYP,ROZMIAR> & operator[] (int indeks);

  //Deklaracja przeciążnie operatora funkcyjnego(const)
  const TYP & operator() (int ind1, int ind2) const;

  //Deklaracja przeciążnie operatora funkcyjnego
  TYP & operator() (int ind1, int ind2);

  //Deklaracja funkcji transponującej macierz(const)
  Macierz transpozycja2() const;

  //Deklaracja funkcji obliczającej wyznacznik macierzy(const)
  TYP Wyznacznik() const;

  //Deklaracja funkcji obliczającej macierz odwrotną(const)
  Macierz odwrotnosc() const;

  //Deklaracja funkcji dodającej dwie macierze(const)
  Macierz operator + (const Macierz & M) const;

  //Deklaracja funkcji odejmującej dwie macierze(const) 
  Macierz operator - (const Macierz& M) const;

  //Deklaracja funkcji mnożącej dwie macierze 
  Macierz operator * (const Macierz & M) const;

  //void swap (Wektor<TYP,ROZMIAR>& a, Wektor<TYP,ROZMIAR>& b);

  //Deklaracja funkcji mnożącej macierz i wektor
  Wektor<TYP,ROZMIAR> operator * (const Wektor<TYP,ROZMIAR> & W) const;  
};


/* 
  Funkcja wczytująca macierz ze strumienia wejściowego
*/
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac);

/*
  Funkcja wyświetlająca macierz na strumień wejściowy
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac);


#endif
