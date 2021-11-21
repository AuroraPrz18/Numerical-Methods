#include <bits/stdc++.h>
using namespace std;
double x[100], y[100], xI;
double l(int i, int n){
    double answer = 1.0;
    for(int j=0; j<=n; j++){
        if(i!=j){
            printf("(%.2f - %.2f)/(%.2f - %.2f) * ", xI, x[j],x[i],x[j]);
            answer *=(xI-x[j])/(x[i]-x[j]);
        }
    }
    return answer;
}

void lagrange(int n){
    double answer=0.0, aux;
    for(int i=0, j=1; i<=n; i++){
        printf("Termino no.%d = ", j);
        aux = l(i, n) * y[i];
        printf("%.2f = %.2f\n",y[i], aux);
        answer+=aux;
        j++;
    }
    printf("\nf%d(x) = %.2f\n",n, answer);
}
int main(){
    int n;
    cout<<"Ingrese el valor de n: ";
    cin>>n;
    for(int i=0; i<=n; i++){
        cout<<"Ingrese el valor de X"<<i<<": ";
        cin>>x[i];
        cout<<"Ingrese el valor de Y"<<i<<": ";
        cin>>y[i];
    }
    cout<<"Ingrese el valor de x: ";
    cin>>xI;
    lagrange(n);
    return 0;
}
