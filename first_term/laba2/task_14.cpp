#include <iostream>
#include <cmath>

long double max(long double a, long double b)
{
    return (a > b ? a : b);
}

int main() {
    //int t;
    long double W, H, x1, y1, x2, y2, w, h, Wmax, Hmax;
    //std::cin >> t;
    //std::cout.precision(9);
    //while(t) {
        std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
        if (x2 - x1 < 0 && y2 - y1 < 0) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        if (W - (x2 - x1) - w >= 0 || H - (y2 - y1) - h >= 0) {
            Wmax = max(x1, W - x2);
            Hmax = max(H - y2, y1);
            if (W - (x2 - x1) - w < 0) {
                std::cout << fabsl(Hmax - h) << '\n';
            } else if (H - (y2 - y1) - h < 0) {
                std::cout << fabsl(Wmax - w) << '\n';
            } else
                std::cout << sqrtl(powl(Wmax - w < 0 ? Wmax - w : 0, 2) + powl(Hmax - h < 0 ? Hmax : 0, 2)) << '\n';
        }
        else std::cout << -1 << '\n';
        //t--;
    //}
    return 0;
}