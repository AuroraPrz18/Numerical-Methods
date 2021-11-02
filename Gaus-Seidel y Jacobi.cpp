#include <bits/stdc++.h>
using namespace std;
double x1, x2, x3;
double f1(){
    //Write your function here
    return (x2 - x3 + 4)/(-4);


    //(x2 - 2*x3 - 10)/(-4);
    //(-2.3*x2 + 0.7*x3 + 7.43)/(-4.4); TAREA 1
    //(x2-2*x3+3)/7;
}
double f2(){
    //Write your function here
    return (x1 + 2*x3 - 5)/(-5);

    //(2*x1 + x3 - 5)/5;
    //(0.8*x1 + 1.1*x3 - 12.17)/(-2.5); TAREA 1
    //(-3*x1-x3-5)/(-4);
}
double f3(){
    //Write your function here
    return (x1 - x2 - 2)/(-3);
    //(x1  - 2*x2 - 9)/(-6) ;
    //(-1.6*x1 + 0.4*x2 - 12.17)/(5.2); TAREA 1
    //(-x1-2*x2+2)/(-5);
}
void gaussseidel(int cifras){
    int iteracion = 0;
    double errorPrevio, errorRelativo1, errorRelativo2, errorRelativo3;
    double  x1Aux=0, x2Aux=0, x3Aux=0;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo1 = errorPrevio + 1;
    errorRelativo2 = errorPrevio + 1;
    errorRelativo3 = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;

    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "x1", "x2", "x3",  "%Eax1", "%Eax2", "%Eax3");

    while((abs(errorRelativo1) > errorPrevio || abs(errorRelativo2) > errorPrevio || abs(errorRelativo3) > errorPrevio) && iteracion<INT_MAX){
        if(iteracion==0){
           printf("|%10s\t|%10.10f\t|%10.10f\t|%10.10f\t|%10s\t|%10s\t|%10s\t|\n", "", x1, x2, x3, "","","");
        }else {
            errorRelativo1 = ((x1-x1Aux)/x1)*100.0;
            errorRelativo2 = ((x2-x2Aux)/x2)*100.0;
            errorRelativo3 = ((x3-x3Aux)/x3)*100.0;
            printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|\n", iteracion, x1, x2, x3, errorRelativo1, errorRelativo2, errorRelativo3);
        }
        x1Aux=x1;
        x2Aux=x2;
        x3Aux=x3;
        x1 =f1();
        x2 =f2();
        x3 =f3();
        iteracion++;
    }
    printf("\n\nValores aproximados ");
    cout<<"x1="<<x1Aux<< " x2=" <<x2Aux<< " x3="<< x3Aux<<endl;
}


void jacobi(int cifras){
    int iteracion = 0;
    double errorPrevio, errorRelativo1, errorRelativo2, errorRelativo3;
    double  x1Aux=0, x2Aux=0, x3Aux=0;
    errorPrevio = (0.5*(double)pow(10, 2-cifras));
    errorRelativo1 = errorPrevio + 1;
    errorRelativo2 = errorPrevio + 1;
    errorRelativo3 = errorPrevio + 1;
    cout<< "Error previo es de: "<<errorPrevio<<endl;

    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "Iteracion", "x1", "x2", "x3",  "%Eax1", "%Eax2", "%Eax3");

    while((abs(errorRelativo1) > errorPrevio || abs(errorRelativo2) > errorPrevio || abs(errorRelativo3) > errorPrevio) && iteracion<INT_MAX){
        if(iteracion==0){
           printf("|%10s\t|%10.10f\t|%10.10f\t|%10.10f\t|%10s\t|%10s\t|%10s\t|\n", "", x1, x2, x3, "","","");
        }else {
            errorRelativo1 = ((x1-x1Aux)/x1)*100.0;
            errorRelativo2 = ((x2-x2Aux)/x2)*100.0;
            errorRelativo3 = ((x3-x3Aux)/x3)*100.0;
            printf("|%10d\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.10f\t|%10.9f\t|\n", iteracion, x1, x2, x3, errorRelativo1, errorRelativo2, errorRelativo3);
        }
        x1Aux=x1;
        x2Aux=x2;
        x3Aux=x3;
        double x1c= f1();
        double x2c= f2();
        double x3c= f3();
        x1 =x1c;
        x2 =x2c;
        x3 =x3c;
        iteracion++;
    }
    printf("\n\nValores aproximados ");
    cout<<"x1="<<x1Aux<< " x2=" <<x2Aux<< " x3="<< x3Aux<<endl;
}
int main(){
    int cifras;
    cout<< "Ingresa cantidad de cifras significativas: ";
    cin>>cifras;
    cout<< "METODO DE JACOBI" << endl;
    jacobi(cifras);
    x1=0, x2=0, x3=0;
    cout<<endl<<endl<<  "METODO DE GAUSS-SEIDEL" << endl;
    gaussseidel(cifras);
    return 0;
}
