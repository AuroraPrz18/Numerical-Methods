#include <bits/stdc++.h>
using namespace std;

double f(double x){
    //Write your function here
    return (3.0*x*x-3.5)/(double)sqrt(x);
    //6.0*x*x-8.0*x-4.375;
    //x*x - (pow((x*x*x-4.0)/(1.0-x), 1.0/2.0));
    //exp(-1*x);
}

void newtonRap(int cifras, double xi, double h){
    int iteracion = 1;
    double errorPrevio, errorRelativo, aproxRaiz, previaAproxRaiz;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "Xi", "f(Xi)", "Xi+1", "%Ea");
    previaAproxRaiz =xi;
    aproxRaiz = xi;
    while(abs(errorRelativo) > errorPrevio && iteracion<INT_MAX ){
        aproxRaiz = aproxRaiz-((f(aproxRaiz)*h)/(f(aproxRaiz+h)-f(aproxRaiz)));
        errorRelativo = ((aproxRaiz-previaAproxRaiz)/aproxRaiz)*100.0;
        printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|\n", iteracion, previaAproxRaiz, f(previaAproxRaiz), aproxRaiz, errorRelativo);
        iteracion++;
        previaAproxRaiz = aproxRaiz;


    }
    printf("\n\nRaiz es aproximadamente ");
    cout << setprecision(cifras);
    cout<<previaAproxRaiz<<endl;
}


int main(){
    int cifras; double l1, h;
    cout<< "Ingresa cantidad de cifras significativas: ";
    cin>>cifras;
    cout<< "Ingresa xi: ";
    cin>>l1;
    cout<< "Ingresa h: ";
    cin>>h;
    cout<< "MÉTODO DE NEWTON-RAPHSON" << endl;
    newtonRap(cifras, l1, h);
    return 0;
}

