#include <iostream>
#include <vector>
#include <string.h>
void merge(int arr[], int low, int mid, int high, int size)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    std::cout << "Iteration: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}
void mergeSort(int arr[], int low, int high, int size)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        //sort first and second halves
        mergeSort(arr, low, mid, size);
        mergeSort(arr, mid + 1, high, size);
        merge(arr, low, mid, high, size);
    }
}
int main(int argc, char const *argv[])
{
    //initialization user inputs
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
        std::cout << a[i] << " ";
    }
    std::cout << "\n\n";
    //sorting the array
    mergeSort(a, 0, n - 1, n);
    std::cout << "Sorted Array is: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n\n";
    return 0;
}