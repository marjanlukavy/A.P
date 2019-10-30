#include <iostream>
#include <cmath>
using namespace std;

int fact(int a) {
    if (a == 1 || a == 0) {
        return 1;
    }
    else {
        return a * fact(a - 1);
    }
}

int main() {
    int n = 1.0;
//    double a = 0;
    double sum = 0;
    double eps = 0.0001;

//    double a = ((2 * n) - 1) / pow(2,n);
    double a = log10(fact(n))*exp((-n)*sqrt(n));

    do{
        sum += a;
        cout << a << endl;
        n++;
//        a = (a*(2*n+1))/((4*n)-2);
        a = a*log10(fact(n+1))*exp((-n+1)*sqrt(n+1))/log10(fact(n))*exp((-n)*sqrt(n));
//         a = log10(fact(n))*exp((-n)*sqrt(n));

    }
    while(abs(a)>eps);
    cout << "Sum is " << sum << endl;
}

