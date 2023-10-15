#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.141592

long double dist(long double x1, long double y1, long double x2, long double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

long double cosf(long double a, long double b, long double c)
{
    return (a * a + b * b - c * c) / (a * b * 2.0);
}

long double median(long double a, long double b, long double c)
{
    return sqrt(2.0 * a * a + 2.0 * b * b - c * c)/2.0;
}

long double bissec(long double a, long double b, long double c)
{
    return sqrt(a * b * (a + b + c) * (a + b - c))/(a + b);
}

int main()
{
    long double x1, y1, x2, y2, x3, y3;
    long double a, b, c, alpha, beta, gama, h, s1, s2, s3, p, r, R;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    std::cout.precision(5);
    a = dist(x1, y1, x2, y2);
    b = dist(x2, y2, x3, y3);
    c = dist(x1, y1, x3, y3);
    gama = acosl(cosf(a, b, c));
    beta = acosl(cosf(a, c, b));
    alpha = acosl(cosf(b, c, a));
    p = (a + b + c)/ 2.0;
    s1 = sqrt(p * (p - a) * (p - b) * (p - c));
    s3 = 0.5 * a * b * sin(gama);
    h = 2.0 * s3 / a;
    s2 = 0.5 * h * a;
    r = s3 / p;
    R = a * b * c / (4.0 * s3);
    std::cout << a << '\n' << b << '\n' << c << '\n';
    std::cout << h << '\n' << 2.0 * s3 / b << '\n' << 2.0 * s3 / c << '\n';
    std::cout << median(b, c, a)  << '\n' << median(a, c, b) << '\n' << median(a, b, c) << '\n';
    std::cout << bissec(b, c, a)  << '\n' << bissec(a, c, b) << '\n' << bissec(a, b, c) << '\n';
    std::cout << beta << " " << beta * 180 / PI  << '\n' << gama << " " << gama * 180 / PI << '\n' << alpha << " " << alpha * 180 / PI << '\n';
    std::cout << R << '\n' << r << '\n';
    std::cout << 2.0 * PI * r << '\n' << PI * r * r << '\n';
    std::cout << 2.0 * PI * R << '\n' << PI * R * R << '\n';
    std::cout << "Square of triangle = " << s1 << " or " << s2 << " or " << s3 << '\n';
    std::cout << a + b + c;
    return 0;
}