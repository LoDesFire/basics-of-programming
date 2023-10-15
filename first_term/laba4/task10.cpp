#include <iostream>
int main()
{
    long long n, n1, n2, SIZE=100, l1=1, l2=1, p=0, min=60;
    std::cin >> n;
    if (n % 2 == 0) {
        n1 = n / 2;
        n2 = n - 1;
    }
    else {
        n1 = (n - 1) / 2;
        n2 =n;
    }
    
    long long* arr1 = new long long [SIZE]();
    long long* arr2 = new long long [SIZE]();
    long long* arr3 = new long long[SIZE]();
    
    long long copy = n1;
    while (copy /= 10) l1++;
    copy = n2;
    while (copy /= 10) l2++;
    for (int i = SIZE - 1; i >= SIZE-1-l1; i--) {
        arr1[i] =  n1% 10;
        n1 /= 10;
    }
    for (int i = SIZE - 1; i >= SIZE-1-l2; i--) {
        arr2[i] = n2 % 10;
        n2 /= 10;
    }


    arr3[SIZE - 1] = 1;

    for (int i = SIZE - 1; i >= SIZE - 1 - l1; i--) {
        for (int j = SIZE - 1; j >= SIZE - 1 - l2; j--) {
            arr3[j-p] += arr1[i] * arr2[j];
            arr3[j - p - 1] += arr3[j - p] / 10;
            arr3[j - p] %= 10;
        }
        p++;
    }

    bool isNumber = false;
    for (int i = 0; i < SIZE; i++) {
        if (arr3[i] != 0)
            isNumber = true;
        if (isNumber) std::cout << arr3[i];
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}