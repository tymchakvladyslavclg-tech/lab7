//задача 1.5

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void findMin(T arr[], int size, T& minValue, int& count)
{
    minValue = arr[0];
    count = 1;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
            count = 1;
        }
        else if (arr[i] == minValue)
        {
            count++;
        }
    }
}

template <>
void findMin<char*>(char* arr[], int size, char*& minValue, int& count)
{
    minValue = arr[0];
    count = 1;

    for (int i = 1; i < size; i++)
    {
        int cmp = strcmp(arr[i], minValue);

        if (cmp < 0)
        {
            minValue = arr[i];
            count = 1;
        }
        else if (cmp == 0)
        {
            count++;
        }
    }
}

int main()
{
    int arr1[] = {4, 2, 7, 2, 9, 2};
    int minInt, countInt;

    findMin(arr1, 6, minInt, countInt);

    cout << "Мінімум int: " << minInt << endl;
    cout << "Кількість повторень: " << countInt << endl;

    char* arr2[] = {
        (char*)"pear",
        (char*)"apple",
        (char*)"banana",
        (char*)"apple"
    };

    char* minStr;
    int countStr;

    findMin(arr2, 4, minStr, countStr);

    cout << "\nМінімум char*: " << minStr << endl;
    cout << "Кількість повторень: " << countStr << endl;

    return 0;
}