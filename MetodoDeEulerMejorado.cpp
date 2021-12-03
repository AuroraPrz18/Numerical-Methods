#include <bits/stdc++.h>
using namespace std;
double x, xi, yi, h;

double f(double a, double b){
    return -1.0*a*a*a + 7.0*a - 1;
    //-3.0 * a * a + a - 4.0;
    //3.0*a*b + 2.0*b*b;
}

double predictor(double a, double b){
    return b + f(a, b) * h;
}

double corrector(){
    return yi + ( ( f(xi, yi) + f(xi+h, predictor(xi, yi) ) ) / 2.0 ) * h;
}


void heun(){
    for(int i=1; i; i++, xi+=h){
        printf("-----------------------------------------------------");
        printf("Iteracion no.%d\n", i);
        printf("xi = %.5f\n", xi);
        printf("yi = %.5f\n", yi);
        printf("xi+1 = %.5f\n", xi+h);
        printf("f'(xi, yi) = %.5f\n", f(xi, yi));
        printf("predictor = %.5f\n", predictor(xi, yi));
        printf("f'(xi+1, y0i+1) = %.5f\n", f(xi+h, predictor(xi, yi)) );
        printf("y(heun) = %.5f\n", corrector());
        yi = corrector();
        if(xi+h >= x){ // MEJORAR ESTO
            break;
        }
    }
}
int main(){
    cout<<"Ingrese el valor de x0: ";
    cin>>xi;
    cout<<"Ingrese el valor de y0: ";
    cin>>yi;
    cout<<"Ingrese el valor de h: ";
    cin>>h;
    cout<<"Ingrese el valor de x: ";
    cin>>x;
    heun();
    return 0;
}

