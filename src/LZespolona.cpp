#include "LZespolona.hh"
#include <cmath>
#define Epsilon 3.17207e-15



/*!
 * Przypisuje wartość części rzeczywistej, cześć urojona jest równa 0.
 * Argumenty:
 *    this
 * Zwraca:
 *    zmienione this
 */
LZespolona LZespolona::operator = (double a)
{
  re = a;
  im = 0;
  return *this;
}


/*!
 * Dodaje liczby zespolone 
 * Argumenty:
 *    this - liczba zespolona do której dodajemy
 *    Z - liczba zespolona którą dodajemy
 * Zwraca:
 *    this zsumowane z liczbą zespoloną
 */
LZespolona LZespolona::operator += (LZespolona Z)
{
  re = re + Z.re;
  im = im + Z.im;

  return *this;
}


/*!
 * Mnożymy liczbę zespoloną z liczbą rzeczywistą
 * Argumenty:
 *    this - liczba zespolona
 *    d - liczba rzeczywista
 * Zwraca:
 *    this pomnożone o liczbę rzeczywistą
 */
LZespolona LZespolona::operator * (double d) const
{ 
  LZespolona Z;
  Z.re = re * d;
  Z.im = im * d;
  return Z;
}


/*!
 * Mnożymy dwie liczby zespolone
 * Argumenty:
 *    this - liczba zespolona do którą mnożymy
 *    Z - liczba zespolona o którą mnożymy
 * Zwraca:
 *    this iloczyn liczb zespolonych
 */
LZespolona LZespolona::operator *= (LZespolona Z)
{
  double temp;

  temp = re;
  re = re * Z.re - im * Z.im;
  im = temp * Z.im + im * Z.re; 

  return *this;
}


/*!
 * Prównywanie liczby zespolonej z liczbą rzeczywistą z pewnym marginesem błędu (Epsilon)
 * Argumenty:
 *    this - liczba zespolona
 *    d liczba rzeczywista
 * Zwraca:
 *    true lub false
 */
bool LZespolona::operator == (double d)
{
  if(abs(re) < Epsilon && abs(im) < Epsilon)
    return true;
  else
    return false;
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

  Wynik = Skl1 * a;

  Wynik = Wynik/pow(b,2);

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
