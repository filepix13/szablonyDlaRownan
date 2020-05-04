#include "UkladRownanLiniowych.hh"

/* 
    Konstuktor zmiennej UkladRownanLiniowych, zeruje macierz oraz wektor
    Argumenty:
        this
    Zwraca:
        this
*/
template <class TYP, int ROZMIAR>
UkladRownanLiniowych<TYP,ROZMIAR>::UkladRownanLiniowych()
{
    Macierz<TYP,ROZMIAR> A;
    Wektor<TYP,ROZMIAR> B;
}


/* 
    Funkcja rozwiązuje układ równań metodą eliminaji Gaussa-Jordana
    Argumenty:
        this
    Zwraca:
        W - wektor wynikowy
*/
template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::Oblicz() const
{

    Macierz<TYP,ROZMIAR> M;
    Wektor<TYP,ROZMIAR> W;
    TYP p, temp;

    W = this->B;
    M = this->A;
    temp = 1;

    for(int i=0, x=ROZMIAR-1; i<ROZMIAR; i++, x--)      // Przekształcamy macierz wejściową M w macierz trójkątną górną, wykonując 
    {                                                   // te same działania na wektorze W
        for(int j=0; j<x; j++)
        {   
            if(M[i][i] == 0)                            //Chroni przed dzieleniem przez 0, zamienia wiersze w macierzy
            {                                           //oraz liczby w wektorze                                        
                M.zamiana(ROZMIAR-(j+1), i);            
                W.zamiana(ROZMIAR-(j+1), i);
            }

            p = M[ROZMIAR-(j+1)][i]/M[i][i];
            M[ROZMIAR-(j+1)] = M[ROZMIAR-(j+1)] - M[i] * p;
            W[ROZMIAR-(j+1)] = W[ROZMIAR-(j+1)] - W[i] * p;
        }
    }

    for(int i=0; i<ROZMIAR; i++)                        //W macierzy M przekształcam wartości po przekątnej dzielimy aby uzykać Wen
    {                                                   //Dla wektora W wykonujemy dokładnie te same działania co dla M
        p = temp/M[i][i];
        M[i] = M[i] * p;
        W[i] = W[i] * p;
    }


    for(int i=0, x=ROZMIAR-1; i<ROZMIAR; i++, x--)      //Przekształacmy macierz wejściową w macierz diagonalizowaną 
    {                                                   //Dla wektora W wykonujemy te same działania co dla M
        for(int j=0; j<x; j++)
        {   
            p = M[j][ROZMIAR-(i+1)]/M[ROZMIAR-(i+1)][ROZMIAR-(i+1)];
            M[j] = M[j] - M[ROZMIAR-(i+1)] * p;
            W[j] = W[j] - W[ROZMIAR-(i+1)] * p;
        }
    }

    return W;
}


/* 
    Funkcja przekazująca macierz z klasy do odczytu
    Argumenty:
        this
    Zwraca:
        A - macierz
*/
template <class TYP, int ROZMIAR>
Macierz<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::wez_macierz() const
{
    return this->A;
}


/* 
    Funkcja przekazująca macierz z klasy do zapisu
    Argumenty:
        this
    Zwraca:
        brak
*/
template <class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::zmien_macierz(Macierz<TYP,ROZMIAR> M)
{
    this->A = M;
}


/* 
    Funkcja przekazująca wektor z klasy do odczytu
    Argumenty:
        this
    Zwraca:
        B - wektor
*/
template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::wez_wektor() const
{
    return this->B;
}


/* 
    Funkcja przekazująca wektor z klasy do zapisu
    Argumenty:
        this
    Zwraca:
        brak
*/
template <class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP,ROZMIAR>::zmien_wektor(Wektor<TYP,ROZMIAR> W)
{
    this->B = W;
}


/* 
    Funkcja ta oblicza wektor błędu wynikający z obliczeń
    Argumenty:
        this
    Zwraca:
        Wektor błędu
*/
template <class TYP, int ROZMIAR>
Wektor<TYP,ROZMIAR> UkladRownanLiniowych<TYP,ROZMIAR>::Blad() const
{
    return this->A * this->Oblicz() - this->B;
}


/* 
    Funkcja ta wczytuje układ równań z strumienia wejściowego
    Argumenty:
        Strm - strumień wejściowy
        Wek - układ równań do którego wczytujemy dane
    Zwraca:
        Strumień wejściowy
*/
template <class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
    Macierz<TYP,ROZMIAR> AA;
    Wektor<TYP,ROZMIAR> BB;

    Strm >> AA >> BB;
    UklRown.zmien_macierz(AA);
    UklRown.zmien_wektor(BB);

    return Strm;
}


/* 
    Funkcja ta wyświetla układ równań na strumień wejściowy
    Argumenty:
        Strm - strumień wyjściowy
        Wek - układ równań który wyświetlamy
    Zwraca:
        Strumień wyjściowy
*/
template <class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<TYP,ROZMIAR> &UklRown)
{
    return Strm << UklRown.wez_macierz() << UklRown.wez_wektor() << std::endl;
}



template class UkladRownanLiniowych<double,5>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<double,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<double,5>  &Mac);
template class UkladRownanLiniowych<LZespolona,5>;
template std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<LZespolona,5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<LZespolona,5>  &Mac);