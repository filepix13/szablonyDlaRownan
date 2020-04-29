#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.hh"


/*
  Klasa UkladRownanLiniowych modeluje pojęcie układu równań składającego się z macierzy i wektora
 */
template <class TYP, int ROZMIAR>
class UkladRownanLiniowych 
{
  Macierz<TYP,ROZMIAR> A;
  Wektor<TYP,ROZMIAR> B;

  public:

  //Deklaracja konstruktora
  UkladRownanLiniowych();

  //Deklaracja funkcji obliczającej równanie macierzowe(const)
  Wektor<TYP,ROZMIAR>  Oblicz() const;

  //Deklaracja funkcji przekazującej nam macierz z klasy do odczytu
  Macierz<TYP,ROZMIAR>  wez_macierz() const;

  //Deklaracja funkcji przekazującej nam macierz z klasy do zapisu
  void zmien_macierz(Macierz<TYP,ROZMIAR>  M);

  //Deklaracja funkcji przekazującej nam wektor z klasy do odczytu
  Wektor<TYP,ROZMIAR>  wez_wektor() const;

  //Deklaracja funkcji przekazującej nam wektor z klasy do zapisu
  void zmien_wektor(Wektor<TYP,ROZMIAR> W);

  //Deklaracja funkcji obliczającej wektor błędu
  Wektor<TYP,ROZMIAR>  Blad() const;

};


/* 
  Funkcja wczytująca układ równań ze strumienia wejściowego
*/
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);

/*
  Funkcja wyświetlająca układ równań na strumień wejściowy
 */
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown);

#endif
