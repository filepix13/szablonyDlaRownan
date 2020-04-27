#include "Wektor.hh"
#include "LZespolona.hh"
#include <math.h>  
#include <iostream>


/* 
    Konstuktor zmiennej Wektor, zeruje tabelę dane
    Argumenty:
        this
    Zwraca:
        this
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor()
{
    for(int i=0; i<ROZMIAR; i++)
    {
        dane[i]=0;
    }
}


/* 
    Konstuktor parametryczny zmiennej Wektor
    Argumenty:
        this
        x, y, z - wartości podstawiane pod odpowiednie miejsca tabeli dane
    Zwraca:
        this
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(TYP Ntab[]) 
{
    for (int i=0;i<ROZMIAR;i++) 
    {
      dane[i] = Ntab[i];
    }
}


/* 
    Funkcja ta oblicza długość wektora
    Argumenty:
        this
    Zwraca:
        dlugosc - długość wektora
*/
/*template<class TYP, int ROZMIAR>
double Wektor<TYP,ROZMIAR>::dlugosc() const
{
    return sqrt(*this * *this);
}*/


/* 
    Funkcja ta dodaje dwa wektory
    Argumenty:
        this
        W2 - drugi wektor
    Zwraca:
        W - suma dwóch wektorów
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator + (const Wektor & W2) const
{
    Wektor W;

    for(int i=0; i<ROZMIAR; i++)
    {
        W.dane[i] = this->dane[i] + W2.dane[i];
    }

    return W;
}


/* 
    Funkcja ta odejmnuje dwa wektory
    Argumenty:
        this
        W2 - drugi wektor
    Zwraca:
        W - różnica dwóch wektorów
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator - (const Wektor & W2) const
{
    Wektor W;

    for(int i=0; i<ROZMIAR; i++)
    {
        W.dane[i] = this->dane[i] - W2.dane[i];
    }

    return W;
}


/* 
    Funkcja ta oblicza iloczyn sklarny dwóch wektorów
    Argumenty:
        this
        W2 - drugi wektor
    Zwraca:
        Iloczyn skalarny(double)
*/
template<class TYP, int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>::operator * (const Wektor & W2) const
{
    TYP d;

    for(int i=0; i<ROZMIAR; i++)
    {
        d += dane[i] * W2.dane[i];
    }

    return d;
}

template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>::operator * (double d) const
{
    Wektor W;

    for(int i=0; i<ROZMIAR; i++)
    {
        W[i] = dane[i] * d;
    }

    return W;
}

template<>
Wektor<LZespolona,5> Wektor<LZespolona,5>::operator * (LZespolona Z) const
{
    Wektor<LZespolona, 5> W;

    for(int i=0; i<5; i++)
    {
        W[i] = dane[i] * Z;
    }

    return W;
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        dane[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
template<class TYP, int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad:  zly indeks wektora";
      exit(1);
    }
    return this->dane[indeks];
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        dane[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
template<class TYP, int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks wektora";
      exit(1);
    }
    return this->dane[indeks];
}


/* 
    Funkcja ta wczytuje wektor z strumienia wejściowego
    Argumenty:
        Strm - strumień wejściowy
        Wek - wektor do którego wczytujemy dane
    Zwraca:
        Strumień wejściowy
*/
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }

    if(std::cin.fail())
    {
        std::cerr << "Wpisany znak nie jest liczbą rzeczywistą" << std::endl << "Zamykanie programu...";
        exit(1);
    }

    return Strm;
}


/* 
    Funkcja ta wyświetla wektor na strumień wejściowy
    Argumenty:
        Strm - strumień wyjściowy
        Wek - wektor który wyświetlamy
    Zwraca:
        Strumień wyjściowy
*/
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Wektor<TYP,ROZMIAR> & Wek)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm << Wek[i] << "  ";
    }

    Strm << std::endl;

    return Strm;
}

template class Wektor<double,5>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,5> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,5> & Wek);
template class Wektor<double,3>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,3> & Wek);
template class Wektor<double,4>;
template std::istream& operator >> (std::istream &Strm, Wektor<double,4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double,4> & Wek);
/*template class Wektor<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona,5> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona,5> & Wek);*/