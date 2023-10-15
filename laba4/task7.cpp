
#include <iostream>
#include <string>

int main()
{
    int a[10000], length = 0, max = 0, min = 0, zeros = 0;
    while(std::cin >> a[length++]) {
        if (a[length - 1] < a[min]) min = length - 1;
        if (a[length - 1] > a[max]) max = length - 1;
        if (a[length - 1] == 0) zeros++;
    }
    length--;
    if (min > max) std::swap(min, max);
    for (int i = min + 1; i < max; i++) {
        a[i] = 0;
        zeros++;
    }
    if (length - 2 * zeros < 0)  zeros = 1;
    else zeros = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (zeros) {
            if (a[i] != 0) std::cout << a[i] << " ";
        }   
        else 
            std::cout << a[i] << " " ;
           
    }
        

    return 0;
}