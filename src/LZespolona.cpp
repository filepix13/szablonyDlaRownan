#include "LZespolona.hh"
#include <cmath>


LZespolona LZespolona::operator = (double a)
{
  re = a;
  im = a;
  return *this;
}

LZespolona LZespolona::operator += (LZespolona Z)
{
  re = re + Z.re;
  im = im + Z.im;

  return *this;
}

LZespolona LZespolona::operator * (double d)
{
  re = re * d;
  im = im * d;
  return *this;
}

LZespolona LZespolona::operator *= (LZespolona Z)
{
  re = re * Z.re;
  im = im * Z.im;

  return *this;
}

bool LZespolona::operator == (double d)
{
  if(re == d && im == d)
    return true;
  else
    return false;
}


LZespolona operator / (double d, LZespolona Z)
{
  Z.re = d/Z.re;
  Z.im = d/Z.im;
  return Z;
}

/*!
 * Realizuje sprzężenie liczby zespolonej.
 * Argumenty:
 *    l - liczba zespolona której sprzężenie wykonujemy,
 * Zwraca:
 *    Sprzężoną liczbę zespoloną
 */
LZespolona Sprzezenie(LZespolona l)
{
  LZespolona liczba;

  liczba.re = l.re;
  liczba.im = -l.im;
  
  return liczba;
}


/*!
 * Realizuje obliczenie modułu liczby zespolonej.
 * Argumenty:
 *    l - liczba zespolona, której moduł obliczamy.
 * Zwraca:
 *    Moduł liczby zespolonej.
 */
double Modul2(LZespolona l)
{
  double modul = sqrt(pow(l.re, 2) + pow(l.im, 2));
  return modul;
}


/*
    Funkcja ta tworzy liczbę zespoloną z dwóch liczb typu double.
    Argumenty:
        re - część rzeczywista liczby zespolonej,
        im - część urojona liczby zespolonej,
    Zwraca:
        Funkcja zwraca liczbę zespoloną.
 */
LZespolona Utworz(double re, double im)
{
    LZespolona l;

    l.re = re;
    l.im = im;

    return l;
}


/*
    Funkcja ta wyświetla liczbę zespoloną na strumień wyjściowy.
    Argumenty:
        StrWy - Strumień wyjściowy,
        Lz - liczba zespolona.
    Zwraca:
        Funkcja zwraca strumień wyjściowy.
 */
std::ostream &operator <<(std::ostream& StrmWy, const LZespolona &Lz)
{
    return StrmWy << '(' <<Lz.re << std::showpos << Lz.im << std::noshowpos << "i)";
}


/*
    Funkcja ta wczytuje liczbę zespoloną ze strumienia wejściowego.
    Argumenty:
        StrWe - Strumień wejściowy,
        Lz - liczba zespolona.
    Zwraca:
        Funkcja zwraca strumień wejściowy.
 */
std::istream &operator >>(std::istream& StrmWe,LZespolona& Lz)
{
    char znak;

    StrmWe >> znak;
    if(znak!='(')
        StrmWe.setstate(std::ios::failbit);

    StrmWe >> Lz.re;
    StrmWe >> Lz.im;
    
    StrmWe >> znak;
    if(znak!='i')
        StrmWe.setstate(std::ios::failbit);
    StrmWe >> znak;
    if(znak!=')')
        StrmWe.setstate(std::ios::failbit);

    return StrmWe;
} 


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje odejmnowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnożenia,
 *    Skl2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re; 
  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  a,Wynik;
  double b;

  a = Sprzezenie(Skl2);
  b = Modul2(Skl2);

  Wynik.re = (Skl1.re*a.re);
  Wynik.im = (Skl1.im*a.im);

  Wynik = Wynik/b;

  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą
 * Argumenty:
 *    Skl1 - liczba zespolona
 *    b - liczba rzeczywista
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona &Skl1, double b)
{
  LZespolona l;

  if(b == 0)
  {
    std::cerr << "Próba dzielenia przez zero. Zamykanie programu...";
    std::exit(1);
  }

  l.re = Skl1.re/b;
  l.im = Skl1.im/b;

  return l;
}


/*
    Funkcja ta porównuje dwie liczby zespolone.
    Argumenty:
        Skl1 - pierwsza liczba zespolona, którą będziemy porównywać,
        Skl2 - druga liczba zespolona, którą będziemy porównywać.
    Zwraca:
        Zwraca prawdę lub fałsz.
*/
bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    {
        return true;
    }
    else
    {
        return false;
    }
}
