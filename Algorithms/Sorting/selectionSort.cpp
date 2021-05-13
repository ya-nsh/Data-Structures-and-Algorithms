#include <iostream>
#include <vector>
#include <string.h>

int main(int argc, char const *argv[])
{
    int n, min, temp;
    std::cout << "Enter Size: " << std::endl;
    std::cin >> n;
    int a[n];

    std::cout << "Enter values: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Element: ";
        std::cin >> a[i];
    }

    std::cout << "Array is: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << std::endl;
    }

    // logic
    for (int i = 0; i < n - 1; i++)    //for swapping and accessing array
    {
        min = i;                 //min is the index of least valued element
        for (int j = i + 1; j < n; j++)    //for finding the miniumum
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
				 
    }

    std::cout << "Sorted Array is: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << std::endl;
    }

    return 0;
}
