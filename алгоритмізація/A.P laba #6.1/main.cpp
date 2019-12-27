#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double SN = 0.0, SE = 0.,y;
    const double eps = 0.0001;

    for (double x = 0.1; x <=1; x+=(1-0.1)/10) {
        int n;
        for (n=0;n <= 1; ++n) {
            double a;

            a = pow(-1, n+2) * (pow(x,2*n+3))/(4*pow(n+1,2)-1);
            SN += a;
        }
        n = 0;
        do{
            SE += pow(-1, n+2) * (pow(x,2*n+3))/(4*pow(n+1,2)-1);
            n++;

        }while (abs(pow(-1, n+2) * (pow(x,2*n+3))/(4*pow(n+1,2)-1)) > eps);

        y = ((1+pow(x,2))/2) * atan(x)- x/2;

        cout <<"X = " << x << " " << "\t";
        cout <<"SN = "<< SN << " " << "\t";
        cout <<"SE = "<< SE << " " << "\t";
        cout <<"Y = "<< y << endl;
        SN = 0;
        SE = 0;
    }
}
