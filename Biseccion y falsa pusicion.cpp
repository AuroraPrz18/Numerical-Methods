#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return (3.0*x*x-3.5)/(double)sqrt(x);
    //6.0*x*x-8.0*x-4.375;
    //2*x*x*x-11.7*x*x+17.7*x-5;
    //6.0*x*x-8.0*x-4.375;
    //2*x*x*x-11.7*x*x+17.7*x-5;
    //2*pow(sin(x), 0.5) - x;
    //pow(x, 10)-1;
    //(3.0*x)-4.0;
    //sin(10*x)+cos(3*x);
}

void biseccion(int cifras, double l1, double l2){
    int iteracion = 1;
    double errorPrevio, errorRelativo, pivIzq=l1, pivDer=l2, aproxRaiz, previaAproxRaiz;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "xi", "xu", "xr",  "f(xi)", "f(xu)", "f(xr)", "%Ea");

    while(abs(errorRelativo) > errorPrevio && iteracion<INT_MAX){
        aproxRaiz = (pivIzq + pivDer)/ 2.0;
        errorRelativo = ((aproxRaiz-previaAproxRaiz)/aproxRaiz)*100.0;
        previaAproxRaiz = aproxRaiz;
        if(iteracion==1){
           printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10s\t|\n", iteracion, pivIzq, pivDer, aproxRaiz, f(pivIzq), f(pivDer), f(aproxRaiz), "  ");

        }else printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|\n", iteracion, pivIzq, pivDer, aproxRaiz, f(pivIzq), f(pivDer), f(aproxRaiz), errorRelativo);
        iteracion++;
        if(f(pivIzq)*f(aproxRaiz) < 0){
            pivDer = aproxRaiz;
        }else if(f(pivIzq)*f(aproxRaiz) > 0){
            pivIzq = aproxRaiz;
        }else{
            break;
        }

    }
    printf("\n\nRaiz es aproximadamente ");
    cout << setprecision(cifras);
    cout<<previaAproxRaiz<<endl;
}

double formulaFalsaPosicion(double x1, double x2){
    double f1 = f(x1);
    double f2 = f(x2);
    double dif = f2-f1;
    double xr = ((x1 * f2)-(x2 * f1))/dif;
    return xr;
}

void falsaPosicion(int cifras, double l1, double l2){
    int iteracion = 1;
    double errorPrevio, errorRelativo, pivIzq=l1, pivDer=l2, aproxRaiz, previaAproxRaiz;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;

    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "xi", "xu", "xr",  "f(xi)", "f(xu)", "f(xr)", "%Ea");

    while(abs(errorRelativo) > errorPrevio && iteracion<INT_MAX){
        aproxRaiz = formulaFalsaPosicion(pivIzq, pivDer);
        errorRelativo = ((aproxRaiz-previaAproxRaiz)/aproxRaiz)*100.0;
        previaAproxRaiz = aproxRaiz;
        if(iteracion==1){
           printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10s\t|\n", iteracion, pivIzq, pivDer, aproxRaiz, f(pivIzq), f(pivDer), f(aproxRaiz), "  ");

        }else printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|\n", iteracion, pivIzq, pivDer, aproxRaiz, f(pivIzq), f(pivDer), f(aproxRaiz), errorRelativo);

        iteracion++;
        if(f(pivIzq)*f(aproxRaiz) < 0){
            pivDer = aproxRaiz;
        }else if(f(pivIzq)*f(aproxRaiz) > 0){
            pivIzq = aproxRaiz;
        }else{
            break;
        }
    }
    printf("\n\nRaiz es aproximadamente ");
    cout << setprecision(cifras);
    cout<<previaAproxRaiz<<endl;
}
int main(){
    int cifras; double l1, l2;
    cout<< "Ingresa cantidad de cifras significativas: ";
    cin>>cifras;
    cout<< "Ingresa limite inferior: ";
    cin>>l1;
    cout<< "Ingresa limite superior: ";
    cin>>l2;
    if(f(l1)*f(l2)>=0){
        cout<< "\nAqui no fue imposible encontrar una raiz, intente con otro rango\n";
        return 0;
    }
    cout<< "METODO DE BISECCION" << endl;
    biseccion(cifras, l1, l2);
    cout<<endl<<endl<< "METODO DE FALSA POSICION" << endl;
    falsaPosicion(cifras, l1, l2);
    return 0;
}
