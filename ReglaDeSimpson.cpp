#include <bits/stdc++.h>
using namespace std;
double f(double x){
    //Write your function here
    return sqrt(x*x*x-x*x+1);
    //0.2+25.0*x-200.0*x*x+675.0*x*x*x-900.0*x*x*x*x+400.0*x*x*x*x*x;
}

void simpson(double a, double b, double n){
    double x=a, hop=(b-a)/n, I, sumatoriaImpar=0.0, sumatoriaPar=0.0;
    printf("\n\nRegla del Simpson\n\n");
    printf("\n\n(b-a) = %.8f\n",(b-a));
    printf("h = %.8f\n\n",(b-a)/n);
    for(int i=0; i<=n; i++){
        printf("x%d = %10.8f      |      f(x%d) = %10.8f\n", i, x, i, f(x));
        if(i>0 and i<n){
            if(i%2==0)sumatoriaPar+=f(x);
            else sumatoriaImpar+=f(x);
        }
        if(i<n) x+=hop;
    }
    I = (b-a) * ( f(a)+4.0*sumatoriaImpar+2.0*sumatoriaPar+f(b) ) / ( 3.0*n );
    printf("\n\nI = %.8f\n",I);
   }



int main(){
    double a, b, n;
    cout<<"Ingrese el valor de a: ";
    cin>>a;
    cout<<"Ingrese el valor de b: ";
    cin>>b;
    cout<<endl<<"Ingrese el valor de n: ";
    cin>>n;
    simpson(a,b,n);
    return 0;
}

