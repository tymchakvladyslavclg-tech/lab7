// задача 2.7
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
bool contains(T arr[], int size, T value)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return true;
    return false;
}

template <typename T>
void mergeArrays(T a[], int n, T b[], int m, T result[], int &resSize)
{
    resSize = 0;

    for (int i = 0; i < n; i++)
    {
        if (!contains(result, resSize, a[i]))
            result[resSize++] = a[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (!contains(result, resSize, b[i]))
            result[resSize++] = b[i];
    }
}

bool contains(char* arr[], int size, char* value)
{
    for (int i = 0; i < size; i++)
        if (strcmp(arr[i], value) == 0)
            return true;
    return false;
}

template <>
void mergeArrays<char*>(char* a[], int n, char* b[], int m, char* result[], int &resSize)
{
    resSize = 0;

    for (int i = 0; i < n; i++)
    {
        if (!contains(result, resSize, a[i]))
            result[resSize++] = a[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (!contains(result, resSize, b[i]))
            result[resSize++] = b[i];
    }
}

int main()
{
    int a[] = {1, 2, 3, 2};
    int b[] = {3, 4, 5};
    int res[10];
    int size;

    mergeArrays(a, 4, b, 3, res, size);

    for (int i = 0; i < size; i++)
        cout << res[i] << " ";
    cout << endl;

    char* s1[] = {(char*)"apple", (char*)"banana"};
    char* s2[] = {(char*)"banana", (char*)"pear"};
    char* res2[10];
    int size2;

    mergeArrays(s1, 2, s2, 2, res2, size2);

    for (int i = 0; i < size2; i++)
        cout << res2[i] << " ";
    cout << endl;

    return 0;
}