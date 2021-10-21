#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return 1.08012;
    //(3.0*x*x-3.5)/(double)sqrt(x) + x;
    //(2.0*x*x*x-11.7*x*x-5.0)/-17.7;
    //(6.0*x*x-4.375)/8.0;
    //pow((x*x*x-4.0)/(1.0-x), 1.0/4.0);
    //(2*x*x*x-11.7*x*x-5)/-17.7;
    //exp(-1*x);
}

void puntoFijo(int cifras, double xi){
    int iteracion = 1;
    double errorPrevio, errorRelativo, aproxRaiz, previaAproxRaiz;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "xi", "x2", "%Ea");
    previaAproxRaiz =xi;
    aproxRaiz = xi;
    while(abs(errorRelativo) > errorPrevio && iteracion<INT_MAX ){
        aproxRaiz = f(aproxRaiz);
        //if(aproxRaiz!=0)
            errorRelativo = ((aproxRaiz-previaAproxRaiz)/aproxRaiz)*100.0; // ERROR APROXIMADO para resultados del profe
        //if(iteracion==1)
        //    printf("|%10d\t|%10.10f\t|%10.10f\t|%10s\t|\n", iteracion, previaAproxRaiz, aproxRaiz, "  ");
        //else
        printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|\n", iteracion, previaAproxRaiz, aproxRaiz, errorRelativo);
        iteracion++;
        previaAproxRaiz = aproxRaiz;


    }
    printf("\n\nRaiz es aproximadamente ");
    cout << setprecision(cifras);
    cout<<previaAproxRaiz<<endl;
}


int main(){
    int cifras; double l1;
    cout<< "Ingresa cantidad de cifras significativas: ";
    cin>>cifras;
    cout<< "Ingresa xi: ";
    cin>>l1;
    cout<< "METODO DE ITERACIÓN SIMPLE DE PUNTO FIJO" << endl;
    puntoFijo(cifras, l1);
    return 0;
}
