#include <iostream>

using namespace std;

template<typename T>
T max(T arr[], size_t size)
{
    T max = arr[0];
    for (auto i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

template<typename T>
T min(T arr[], size_t size)
{
    T min = arr[0];
    for (auto i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

template<typename T>
T sort(T arr[], size_t size)
{
    T buf;
    for (auto i = 0; i < size - 1; i++)
    {
        for (auto j = 0; j < (size - i - 1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                buf = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buf;
            }
        }
    }
    return *arr;
}

template<typename T>
int find(T arr[], int size, T find)
{
    int left{0}, right{size}, middle{0};
    T key = find;
    while (true)
    {
        middle = (left + right) / 2;
        if (key < arr[middle])
        {
            right = middle - 1;
        }
        else if (key > arr[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }

        if (left > right)
            return -1;
    }
}

template<typename T>
T replace(T arr[], size_t size, T r, size_t place)
{
    return arr[place] = r;
}

template<typename T>
void show(T arr[], size_t size)
{
    for (auto i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    string str = "l";
    int arr_int[SIZE] = { 1, 2, 3, 4, 5 };
    double arr_double[SIZE] = { 1.0, 2.7, 6.2, 7.1, 9.9 };
    string arr_string[SIZE] = { "v", "a", "r", "l", "q" };

    int max_int, min_int;
    double max_double, min_double;
    string max_string, min_string;

    max_int = max(arr_int, SIZE);
    min_int = min(arr_int, SIZE);

    std::cout << "MAX_int: " << max_int << " " << "MIN_int: " << min_int << std::endl;

    max_double = max(arr_double, SIZE);
    min_double = min(arr_double, SIZE);

    std::cout << "MAX_double: " << max_double << " " << "MIN_double: " << min_double << std::endl;

    max_string = max(arr_string, SIZE);
    min_string = min(arr_string, SIZE);

    std::cout << "MAX_string: " << max_string << " " << "MIN_string: " << min_string << std::endl;

    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    sort(arr_int, SIZE);
    show(arr_int, SIZE);

    sort(arr_double, SIZE);
    show(arr_double, SIZE);

    sort(arr_string, SIZE);
    show(arr_string, SIZE);

    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    
    int index_int = find(arr_int, SIZE, 4);
    std::cout << index_int << std::endl;

    int index_double = find(arr_double, SIZE, 2.7);
    std::cout << index_double << std::endl;

    int index_string = find(arr_string, SIZE, str);
    std::cout << index_string << std::endl;

    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    replace(arr_int, SIZE, 0, 4);
    show(arr_int, SIZE);

    replace(arr_double, SIZE, 0.0, 3);
    show(arr_double, SIZE);

    replace(arr_string, SIZE, str, 0);
    show(arr_string, SIZE);
    
    return 0;
}
