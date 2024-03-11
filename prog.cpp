#include <iostream>
#include <fstream>
using namespace std;

//x^2 - 10 [0, 5]
double f(double a)
{
    return (a * a - 10);
}

double fp(double a)
{
    return 2 * a;
}

double half_dev(double a, double b, double limit)
{
    double c = 0, fa, fb, fc, diff;
    do
    {
        fa = f(a);
        fb = f(b);
        c = (a + b) / 2;
        fc = f(c);
        if((fa * fc) < 0)
        {
            b = c;
            diff = (a - c) > 0 ? (a - c) / 2 : (c - a) / 2;
        }
        else
        {
            a = c;
            diff = (b - c) > 0 ? (b - c) / 2 : (c - b) / 2;
        }
    } while(diff > limit);
    return c;
}

double chord_method(double a, double b, double limit)
{
    double c, fa, fb, fc, diff = 1, last_c;
    fa = f(a);
    fb = f(b);
    c = (a * fb - b * fa) / (fb - fa);
    fc = f(c);
    if((fa * fc) < 0)
        b = c;
    else
        a = c;
    last_c = c;
    while(diff > limit)
    {
        fa = f(a);
        fb = f(b);
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);
        if((fa * fc) < 0)
            b = c;
        else
            a = c;
        diff = c - last_c;
        last_c = c;
    }
    return c;
}

double Newton(double a, double limit)
{
    double fa, fpa, diff = 1, last_a, x;
    while(diff > limit)
    {
        last_a = a;
        fa = f(a);
        fpa = fp(a);
        a = last_a - fa / fpa;
        x = a - last_a;
        diff = x > 0 ? x : x * (-1);
    }
    return a;
}

int main()
{
    double limit = 1E-3;
    double a = 0, b = 5, c = 0;
    cout << "x^2 - 10    [0,5]" << endl;
    c = half_dev(a, b, limit);
    cout << "half devision : " << c << endl;
    c = chord_method(a, b, limit);
    cout << "chord method : " << c << endl;
    c = Newton(b, limit);
    cout << "Newton method : " << c << endl;
    return 0;
}