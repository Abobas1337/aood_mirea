#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) 
{
    return sin(M_PI * x * x / 2);
}


double Newton(double a, double b, double eps, int& n)
 {
    double h = (b - a) / n;
    double integral = 0.0;
    double z = h / 4;
    for (int i = 0; i < n; ++i) 
    {
        double x0 = a + i * h;
        double x1 = x0 + h / 4;
        double x2 = x0 + h / 2;
        double x3 = x0 + 3 * h / 4;
        double x4 = x0 + h;

        integral += (7 * f(x0) + 32 * f(x1) + 12 * f(x2) + 32 * f(x3) + 7 * f(x4)) * ((2 * z) / 90);
    }


    double integralPrev = 0.0;
    do 
    {
        integralPrev = integral;
        n *= 2;
        h = (b - a) / n;
        integral = 0.0;
        z = h / 4;
        for (int i = 0; i < n; ++i) 
        {
            double x0 = a + i * h;
            double x1 = x0 + h / 4;
            double x2 = x0 + h / 2;
            double x3 = x0 + 3 * h / 4;
            double x4 = x0 + h;

            integral += (7 * f(x0) + 32 * f(x1) + 12 * f(x2) + 32 * f(x3) + 7 * f(x4)) * ((2 * z) / 90);
        }
    } while (fabs(integral - integralPrev) > eps);

    return integral;
}

int main() 
{
    double a = 0.0;
    double eps = 1e-6;
    double b[] = {0.5, 1.0, 1.5, 2.0};

    cout << setw(10) << "b" << setw(20) << "Integral" << setw(20) << "n" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < 4; ++i) 
    {
        int n = 1; 
        double integral = Newton(a, b[i], eps, n);
        cout << setw(10) << b[i] << setw(20) << integral << setw(20) << n << endl;
    }

    return 0;
}
