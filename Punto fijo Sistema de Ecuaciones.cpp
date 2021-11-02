#include <bits/stdc++.h>
using namespace std;
double x1, x2, x3;
double f1(){
    //Write your function here
    return (-2*x1+4*x2)/(3*x2*x2);
    //sqrt(-1*x2+x1+0.75);
    //(x2*x2-9)/(x2*x2);
}
double f2(){
    //Write your function here
    return sqrt((5.0-x1*x1+x1*x2)/3.0);
    //(-1*x2+x1*x1)/(5*x1);
}

void puntoFijo(int cifras){
    int iteracion = 0;
    double errorPrevio, errorRelativo1, errorRelativo2;
    double  x1Aux=0, x2Aux=0, x3Aux=0;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo1 = errorPrevio + 1;
    errorRelativo2 = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;

    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "x1", "x2", "%Eax1", "%Eax2");

    while((abs(errorRelativo1) > errorPrevio || abs(errorRelativo2) > errorPrevio ) && iteracion<INT_MAX){
        if(iteracion==0){
           printf("|%10s\t|%10.10f\t|%10.10f\t|%10s\t|%10s\t|\n", "", x1, x2,"","");
        }else {
            errorRelativo1 = ((x1-x1Aux)/x1)*100.0;
            errorRelativo2 = ((x2-x2Aux)/x2)*100.0;
            printf("|%10d\t|%10.10f\t|%10.10f\t|%10.8f\t|%10.10f\t|\n", iteracion, x1, x2, errorRelativo1, errorRelativo2);
        }
        x1Aux=x1;
        x2Aux=x2;
        x1 =f1();
        x2 =f2();
        iteracion++;
    }
    printf("\n\nValores aproximados ");
    cout<<"x1="<<x1Aux<< " x2=" <<x2Aux<<endl;
}


int main(){
    int cifras;
    cout<< "Ingresa cantidad de cifras significativas: ";
    cin>>cifras;
    cout<< "Ingresa valor inicial de X: ";
    cin>>x1;
    cout<< "Ingresa valor inicial de Y: ";
    cin>>x2;
    cout<< "PUNTO FIJO" << endl;
    puntoFijo(cifras);
    return 0;
}
