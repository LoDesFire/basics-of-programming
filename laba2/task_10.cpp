#include <iostream>
#include <cmath>

long double dist(long double x1, long double y1, long double x2, long double y2)
{
    return sqrtl(powl(x1 - x2, 2.0) + powl(y1 - y2, 2.0));
}

int main() {
    setlocale(0, "Russian");
    long double x1, y1, x2, y2, r, R;
    bool fl = false;
    std::cout << "Введите координаты и радиус первого круга: ";
    std::cin >> x1 >> y1 >> r;
    std::cout << "Введите координаты и радиус второго круга: ";
    std:: cin >> x2 >> y2 >> R;

    if (r > R) {
        std::swap(R, r);
        fl = true;
    }
    if (R - dist(x1, y1, x2, y2) - r >= 0)
        std::cout << (fl ? "Да, но справедливо обратное для двух фигур" : "Да");
    else
        if (R + r >= dist(x1, y1, x2, y2))
            std::cout << "Фигуры пересекаются";
    return 0;
}
