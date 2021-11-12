#include <bits/stdc++.h>
using namespace std;
double x1, x2, x3;
double f(double x){
    //Write your function here
    return sqrt(x*x*x-x*x+1);
    //x*x*x-5.0*x+4;
    //sqrt(x*x*x-x*x+1);
    //x*x*x-5.0*x+4;
    //(-3.0*x*x)-(2.0*x)+5;
    //sqrt(1)-x*x*x;
    //
}

void ddfd(double xIni, double h){// Diferencias divididas finitas hacia adelante
    double x[10];
    x[0] = xIni;
    for(int i=1; i<10; i++){
        x[i]=x[i-1]+h;
    }
    printf("\n\nDDFD\n\n");

    printf("--------------------------------------------------------Primera derivada DDFD--------------------------------------------------------\n\n");
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "x0", "x1", "x2", "f(x0)", "f(x1)", "f(x2)", "f'(x0)", "h");
    double primeraDerivada = ( -1.0*f(x[2])+4.0*f(x[1])-3.0*f(x[0]) ) / (2.0*h);
    printf("|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|\n", x[0], x[1], x[2], f(x[0]), f(x[1]), f(x[2]), primeraDerivada, h);
    printf("\n\n--------------------------------------------------------Segunda derivada DDFD--------------------------------------------------------\n\n");
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "x0", "x1", "x2", "x3", "f(x0)", "f(x1)", "f(x2)", "f(x3)","f''(x0)", "h");
    double segundaDerivada = ( -1.0*f(x[3])+4.0*f(x[2])-5.0*f(x[1])+2.0*f(x[0]) ) / (h*h);
    printf("|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.8f\t|%10.6f\t|%10.6f\t|\n", x[0], x[1], x[2], x[3], f(x[0]), f(x[1]), f(x[2]), f(x[3]), segundaDerivada, h);
}

void ddfa(double xIni, double h){// Diferencias divididas finitas hacia atrás
    double x[10];
    x[0] = xIni;
    for(int i=1; i<10; i++){
        x[i]=x[i-1]-h;
    }
    printf("\n\nDDFA\n\n");

    printf("--------------------------------------------------------Primera derivada DDFA--------------------------------------------------------\n\n");
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "x0", "x1", "x2", "f(x0)", "f(x1)", "f(x2)", "f'(x0)", "h");
    double primeraDerivada = ( 3.0*f(x[0])-4.0*f(x[1])+f(x[2]) ) / (2.0*h);
    printf("|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|\n", x[0], x[1], x[2], f(x[0]), f(x[1]), f(x[2]), primeraDerivada, h);
    printf("\n\n--------------------------------------------------------Segunda derivada DDFA--------------------------------------------------------\n\n");
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "x0", "x1", "x2", "x3", "f(x0)", "f(x1)", "f(x2)", "f(x3)","f''(x0)", "h");
    double segundaDerivada = ( 2.0*f(x[0])-5.0*f(x[1])+4.0*f(x[2])-1.0*f(x[3]) ) / (h*h);
    printf("|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|\n", x[0], x[1], x[2], x[3], f(x[0]), f(x[1]), f(x[2]), f(x[3]), segundaDerivada, h);
}

void ddfc(double xIni, double h){// Diferencias divididas finitas hacia adelante
    double x[10];
    x[0] = xIni;
    for(int i=1; i<10; i++){
        x[i]=x[i-1]+h;
    }
    printf("\n\nDDFC\n\n");

    printf("--------------------------------------------------------Primera derivada DDFC--------------------------------------------------------\n\n");
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "x0", "x1", "x2", "f(x0)", "f(x1)", "f(x2)", "f'(x0)", "h");
    double primeraDerivada = ( -1.0*f(x[2])+8.0*f(x[1])-8.0*f(x[0]-h)+f(x[0]-2*h) ) / (12.0*h);
    printf("|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|\n", x[0], x[1], x[2], f(x[0]), f(x[1]), f(x[2]), primeraDerivada, h);
    printf("\n\n--------------------------------------------------------Segunda derivada DDFC--------------------------------------------------------\n\n");
    printf("|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|%10s\t|\n", "x0", "x1", "x2", "x3", "f(x0)", "f(x1)", "f(x2)", "f(x3)","f''(x0)", "h");
    double segundaDerivada = ( -1.0*f(x[2])+16.0*f(x[1])-30.0*f(x[0])+16.0*f(x[0]-h)-f(x[0]-2*h) ) / (12.0*h*h);
    printf("|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.6f\t|%10.8f\t|%10.6f\t|%10.6f\t|\n", x[0], x[1], x[2], x[3], f(x[0]), f(x[1]), f(x[2]), f(x[3]), segundaDerivada, h);
}

int main(){
    double x, h;
    cout<<"Ingrese el valor de x: ";
    cin>>x;
    cout<<endl<<"Ingrese el valor de h: ";
    cin>>h;
    ddfd(x, h);
    ddfa(x, h);
    ddfc(x, h);
    return 0;
}
