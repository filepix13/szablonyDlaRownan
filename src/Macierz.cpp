#include "Macierz.hh"
#include "LZespolona.hh"
#include <math.h>
#include <algorithm>


/* 
    Konstuktor zmiennej Macierz, zeruje tabelę tab
    Argumenty:
        this
    Zwraca:
        this
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR>::Macierz()
{
    for(int i = 0; i < ROZMIAR; i++)
    {
        for(int j = 0; j < ROZMIAR; j++)
        {
            tab[i][j] = 0;
        }
    }
}


/* 
    Konstuktor parametryczny zmiennej Wektor
    Argumenty:
        this
        Wek1, Wek2, Wek3 - wektory wstawiane do tabeli tab
    Zwraca:
        this
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR>::Macierz(Wektor<TYP,ROZMIAR> Wek1, Wektor<TYP,ROZMIAR> Wek2, Wektor<TYP,ROZMIAR> Wek3)
{
    tab[0] = Wek1;
    tab[1] = Wek2;
    tab[2] = Wek3;
}


/* 
    Konstuktor parametryczny zmiennej Wektor
    Argumenty:
        this
        a, b, c, d, e, f, g, h, i - liczby rzeczywiste podstawiane do tabeli tab
    Zwraca:
        this
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR>::Macierz(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
    tab[0][0] = a;
    tab[0][1] = b;
    tab[0][2] = c;
    tab[1][0] = d;
    tab[1][1] = e;
    tab[1][2] = f;
    tab[2][0] = g;
    tab[2][1] = h;
    tab[2][2] = i;
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        tab[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
template<class TYP, int ROZMIAR>
const Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[indeks];
}


/* 
    Funkcja ta przeciąża operator indeksujący
    Argumenty:
        this
        int indeks - indeks zmniennej którą chcemy uzyskać
    Zwraca:
        tab[indeks] - zwraca tą zmienną klasy, której indeks podaliśmy
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> & Macierz<TYP,ROZMIAR>::operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[indeks];
}


/* 
    Funkcja ta przeciąża operator funkcjonalny
    Argumenty:
        this
        int ind1 - pierwszy indeks(wiersze)
        int ind2 - drugi indeks(kolumny)
    Zwraca:
        tab[ind1][ind2] - zwraca tą zmienną klasy, której indeksy podaliśmy
*/
template<class TYP, int ROZMIAR>
const TYP & Macierz<TYP,ROZMIAR>::operator() (int ind1, int ind2) const
{
    if (ind1 < 0 || ind1 >= ROZMIAR || ind2 < 0 || ind2 >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[ind1][ind2];
}


/* 
    Funkcja ta przeciąża operator funkcjonalny
    Argumenty:
        this
        int ind1 - pierwszy indeks(wiersze)
        int ind2 - drugi indeks(kolumny)
    Zwraca:
        tab[ind1][ind2] - zwraca tą zmienną klasy, której indeksy podaliśmy
*/
template<class TYP, int ROZMIAR>
TYP & Macierz<TYP,ROZMIAR>::operator() (int ind1, int ind2)
{
    if (ind1 < 0 || ind1 >= ROZMIAR || ind2 < 0 || ind2 >= ROZMIAR) {
      std::cerr << "blad: zly indeks macierzy";
      exit(1);
    }
    return this->tab[ind1][ind2];
}


/* 
    Funkcja ta transponuje macierz
    Argumenty:
        this
    Zwraca:
        Mac - transponowana macierz
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::transpozycja2() const
{
    Macierz Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Mac.tab[i][j] = this->tab[j][i];
        }
    }

    return Mac;
}


/* 
    Funkcja ta transponuje macierz
    Argumenty:
        this
    Zwraca:
        this
*/
template<class TYP, int ROZMIAR>
void Macierz<TYP,ROZMIAR>::transpozycja()
{
    std::swap(this->tab[0][1], this->tab[1][0]);
    std::swap(this->tab[0][2], this->tab[2][0]);
    std::swap(this->tab[2][1], this->tab[1][2]);
}



/* 
    Funkcja ta oblicza wyznacznik macierzy metodą Laplaca
    Argumenty:
        this
    Zwraca:
        d - wynacznik macierzy
*/
template<class TYP, int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::Wyznacznik() const
{
    TYP d;
    Macierz<TYP,ROZMIAR> M;

    d = 1;
    M = *this;

    for(int i=0, x=ROZMIAR-1; i<ROZMIAR; i++, x--)
    {   
        for(int j=0; j<x; j++)
        {
            //if(M[i][i])
                //swap(M[ROZMIAR-(j+1)], M[i]);
            M[ROZMIAR-(j+1)] = M[ROZMIAR-(j+1)] - M[i] * (M[ROZMIAR-(j+1)][i]/M[i][i]);
        }
    }

    for(int i=0; i<ROZMIAR; i++)
    {
        d *= M[i][i];
    }

    return d;
}


/* 
    Funkcja ta tworzy macierz odwrotną
    Argumenty:
        this
    Zwraca:
        Mac - macierz odwócona
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::odwrotnosc() const
{
    Macierz<TYP,ROZMIAR> M;
    Macierz<TYP,ROZMIAR> Jed;
    TYP p;

    if(this->Wyznacznik() == 0)
    {
        std::cerr << "Wyznacznik równy zero, brak możliwości obliczenia odwrotności" << std::endl << "Zamykanie programu...";
        exit(1);
    }

    for(int i=0; i<ROZMIAR; i++)
    {
        Jed[i][i] = 1;
    }

    M = *this;

    for(int i=0, x=ROZMIAR-1; i<ROZMIAR; i++, x--)
    {
        for(int j=0; j<x; j++)
        {   
            p = M[ROZMIAR-(j+1)][i]/M[i][i];
            M[ROZMIAR-(j+1)] = M[ROZMIAR-(j+1)] - M[i] * p;
            Jed[ROZMIAR-(j+1)] = Jed[ROZMIAR-(j+1)] - Jed[i] * p;
        }
    }

    for(int i=0; i<ROZMIAR; i++)
    {
        p = 1/M[i][i];
        M[i] = M[i] * p;
        Jed[i] = Jed[i] * p;
    }

    for(int i=0, x=ROZMIAR-1; i<ROZMIAR; i++, x--)
    {
        for(int j=0; j<x; j++)
        {   
            p = M[j][ROZMIAR-(i+1)]/M[ROZMIAR-(i+1)][ROZMIAR-(i+1)];
            M[j] = M[j] - M[ROZMIAR-(i+1)] * p;
            Jed[j] = Jed[j] - Jed[ROZMIAR-(i+1)] * p;
        }
    }

    return Jed;
}


/* 
    Funkcja ta dodaje dwie macierze
    Argumenty:
        this
        M - druga macierz
    Zwraca:
        Mac - suma dwóch macierzy wejściowych
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator + (const Macierz & M) const
{
    Macierz<TYP,ROZMIAR> Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Mac.tab[i][j] = this->tab[i][j] + M.tab[i][j];
        }
    }

    return Mac;
}


/* 
    Funkcja ta odejmnuje dwie macierze
    Argumenty:
        this
        M - druga macierz
    Zwraca:
        Mac - różnica dwóch macierzy wejściowych
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator - (const Macierz & M) const
{
    Macierz<TYP,ROZMIAR> Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Mac.tab[i][j] = this->tab[i][j] - M.tab[i][j];
        }
    }

    return Mac;
}


/* 
    Funkcja ta mnoży dwie macierze
    Argumenty:
        this
        M - druga macierz
    Zwraca:
        Mac - iloraz dwóch macierzy wejściowych
*/
template<class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator * (const Macierz & M) const
{
   Macierz<TYP,ROZMIAR> Mac;

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            for(int k=0; k<ROZMIAR; k++)
            {
                Mac.tab[i][j] += this->tab[i][k] * M.tab[k][j];
            }
        }
    }

    return Mac;
}


/* 
    Funkcja ta mnoży macierz z wektorem
    Argumenty:
        this
        W - wektor
    Zwraca:
        Wek - Iloraz macierzy i wektora wejściowego
*/
template<class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator * (const Wektor<TYP,ROZMIAR> & W) const
{
    Wektor<TYP,ROZMIAR> Wek;

    for(int i=0; i<ROZMIAR; i++)
    {   
        for(int j=0; j<ROZMIAR; j++)
        {   
            Wek[i] += this->tab[i][j] * W[j];
        }
    }

    return Wek;
}

/*template<class TYP, int ROZMIAR>
void Macierz<TYP,ROZMIAR>::swap(Wektor<TYP,ROZMIAR> &a, Wektor<TYP,ROZMIAR> &b)
{
    Wektor<TYP,ROZMIAR> temp;
    temp = a;
    a = b;
    b = temp;
}*/


/* 
    Funkcja ta wczytuje macierz z strumienia wejściowego
    Argumenty:
        Strm - strumień wejściowy
        Wek - macierz do której wczytujemy dane
    Zwraca:
        Strumień wejściowy
*/
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }

    Mac = Mac.transpozycja2();
    return Strm;
}


/* 
    Funkcja ta wyświetla macierz na strumień wejściowy
    Argumenty:
        Strm - strumień wyjściowy
        Wek - macierz którą wyświetlamy
    Zwraca:
        Strumień wyjściowy
*/
template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac)
{   
    Macierz<TYP,ROZMIAR> M;
    M = Mac.transpozycja2();

    for(int i=0; i<ROZMIAR; i++)
    {
        Strm << M[i] << std::endl;
    }
    
    return Strm; 
}

template class Macierz<double,5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,5>  &Mac);
template class Macierz<double,3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,3>  &Mac);
template class Macierz<double,4>;
template std::istream& operator >> (std::istream &Strm, Macierz<double,4> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double,4>  &Mac);
template class Macierz<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona,5>  &Mac);