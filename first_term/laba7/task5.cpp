#include <iostream>

int CountInterestingInInterval(int interval_end)
{
    return (interval_end + 1) / 10;
}

int main()
{
    int n;
    std::cin >> n;
    while (n--) {
        int t;
        std::cin >> t;
        std::cout << CountInterestingInInterval(t) << "\n";
    }
}