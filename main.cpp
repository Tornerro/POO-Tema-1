#include <iostream>
#include "Matrice_Complexa.h"

int main()
{
    Matrice_Complexa M;
    nr_complex a,b,c;
    std::cin>>a>>b>>c;
    M=Matrice_Complexa(a,3,2);
    Matrice_Complexa N = Matrice_Complexa(b,2,3);
    Matrice_Complexa Q = Matrice_Complexa(c,3,2);
    std::cout<<M;
    std::cout<<M+Q;
    std::cout<<M*N;
    return 0;
}
