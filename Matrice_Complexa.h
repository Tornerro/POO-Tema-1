#include <iostream>

class nr_complex
{
    friend class Matrice_Complexa;
    double re, img;
public:
    nr_complex();
    nr_complex(double , double );
    ~nr_complex();
    nr_complex(const nr_complex&);
    nr_complex& operator+(const nr_complex&);
    nr_complex& operator*(const nr_complex&);
    friend std::istream& operator>>(std::istream&, nr_complex&);
    friend std::ostream& operator<<(std::ostream&, const nr_complex&);
};

class Matrice_Complexa
{
    int lin, col;
    nr_complex a[20][20];
public:
    Matrice_Complexa();
    Matrice_Complexa(nr_complex, int, int );
    Matrice_Complexa(const Matrice_Complexa&);
    ~Matrice_Complexa();
    friend std::istream& operator>>(std::istream&, Matrice_Complexa&);
    friend std::ostream& operator<<(std::ostream&,  Matrice_Complexa&);
    Matrice_Complexa& operator+(Matrice_Complexa&);
    Matrice_Complexa& operator*(Matrice_Complexa&);

};
