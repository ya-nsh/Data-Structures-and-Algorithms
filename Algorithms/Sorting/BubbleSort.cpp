void bubbleSort(int arr[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++) //passes
    {
				flag = 0;
        for (int j = 0; j < n - i - 1; j++) //comparisons
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        std::cout << "==================================" << std::endl;
        std::cout << "Pass " << i + 1 << std::endl;
        display(arr, n);
        if (flag == 0)
        {
            std::cout << "\nGiven array is already sorted. This is the best case." << std::endl;
            break;
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(int argc, char const *argv[])
{
    int size, temp;
    std::cout << "Enter the size of the array: " << std::endl;
    std::cin >> size;
    int arr[size];

    std::cout << "Enter the array: " << std::endl;
    for (int i = 0; i < size; i++)
    {

        std::cin >> arr[i];
    }
    system("CLS");
    std::cout << "\nThe array is  : " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    std::cout << "==================================" << std::endl;
    std::cout << "The sorted array is : " << std::endl;

    bubbleSort(arr, size);
    // display(arr, size);

    return 0;
}
