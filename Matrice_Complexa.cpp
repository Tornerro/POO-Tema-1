#include "Matrice_Complexa.h"
#include<math.h>


Matrice_Complexa::Matrice_Complexa()
{
    this->lin=0;
    this->col=0;
}

Matrice_Complexa::Matrice_Complexa(nr_complex val, int lin, int col)
{
    this->lin=lin;
    this->col=col;
    for(int i=1; i<=lin; ++i)
    {
        for(int j=1; j<=col; ++j)a[i][j]=val;
    }
}

Matrice_Complexa::Matrice_Complexa(const Matrice_Complexa& M)
{
    this->lin=M.lin;
    this->col=M.col;
    for(int i=1; i<=lin; ++i)
    {
        for(int j=1; j<=col; ++j)this->a[i][j]=M.a[i][j];
    }
}

Matrice_Complexa::~Matrice_Complexa()
{
    this->lin=0;
    this->col=0;
}

std::istream& operator>>(std::istream& f, Matrice_Complexa& M)
{
    int lin, col;
    nr_complex val;
    f>>val>>lin>>col;
    M=Matrice_Complexa(val,lin,col);
    return f;
}

std::ostream& operator<<(std::ostream& g, Matrice_Complexa &M)
{
    for(int i=1; i<=M.lin; ++i)
    {
        for(int j=1; j<=M.col; ++j)g<<M.a[i][j]<<' ';
        g<<'\n';
    }
    g<<'\n';
    return g;
}

Matrice_Complexa& Matrice_Complexa::operator+(Matrice_Complexa &M)
{
    if( this->lin != M.lin || this->col != M.col)
    {
        std::cout<<"Eroare! Matricile nu au aceleasi dimenisuni. Matricea nu se va modifica.\n";
        return *this;
    }
    Matrice_Complexa *S = new Matrice_Complexa;
    nr_complex z(0,0);
    *S= Matrice_Complexa(z, this->lin, this->col);
    for(int i=1; i<=this->lin; ++i)
    {
        for(int j=1; j<=this->col; ++j)(*S).a[i][j]=this->a[i][j]+M.a[i][j];
    }
    return *S;
}

Matrice_Complexa& Matrice_Complexa::operator*(Matrice_Complexa& M)
{
    if(this->col != M.lin)
    {
        std::cout<<"Eroare! Matricile nu au dimenisuni corespunzatoare. Matricea nu se va modifica.\n";
        return *this;
    }
    Matrice_Complexa *Prod = new Matrice_Complexa;
    nr_complex z(0,0);
    *Prod = Matrice_Complexa(z,this->lin,M.col);
    for(int i=1; i <= (*Prod).lin; ++i)
    {
        for(int j=1; j <= (*Prod).col; ++j)
        {
            for(int k=1; k <= this->col; ++k)(*Prod).a[i][j]=(*Prod).a[i][j]+this->a[i][k]*M.a[k][j];
        }
    }
    return *Prod;
}





std::ostream& operator<<(std::ostream& g, const nr_complex& c)
{
    if(c.re!=0)g<<c.re;
    if(c.img!=0)
    {
        if(c.img<0)g<<c.img;
        else
        {
            if(c.re!=0)g<<'+';
            g<<c.img;
        }
        g<<'i';
    }
    return g;
}

std::istream& operator>>(std::istream& f, nr_complex& c)
{
    f>>c.re>>c.img;
    return f;
}

nr_complex::nr_complex(){
    this->re=0;
    this->img=0;
}

nr_complex::nr_complex(double x, double y){
    this->re=x;
    this->img=y;
}

nr_complex::~nr_complex(){
    re=0;
    img=0;
    //std::cout<<"distruge numarul\n";
}

nr_complex::nr_complex(const nr_complex &other){
    this->re=other.re;
    this->img=other.img;
}

nr_complex& nr_complex::operator+(const nr_complex &A){
    nr_complex *C = new nr_complex ;
    (*C).re=this->re+A.re;
    (*C).img=this->img+A.img;
    return *C;
}

nr_complex& nr_complex::operator*(const nr_complex &A){
    nr_complex *C = new nr_complex ;
    (*C).re=(this->re)*A.re-(this->img)*A.img;
    (*C).img=(this->re)*A.img+(this->img)*A.re;
    return *C;
}

