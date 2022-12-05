#include <cstdlib>
#include <time.h>
#include <iostream>
using std::swap, std::cout, std::endl;

template <typename T>
void selectionSort(T arr[], int length)
{
    int i, j, min_ind;

    for (i = 0; i < length - 1; i++)
    {

        // находит индекс минимального элемент
        min_ind = i;
        for (j = i + 1; j < length; j++)
        if (arr[j] < arr[min_ind])
            min_ind = j;

        // меняет минимальный с первым
        if (min_ind != i)
            swap(arr[min_ind], arr[i]);
    }
}

template <typename T>
void insertionSort(T arr[], int length)
{
    int i, j, a;
    for (j = 1; j < length; j++)
    {
        a = arr[j];
        i = j - 1;

        // сдвигает все элементы > a на 1 вправо
        // для каждого элемента массива
        while (i >= 0 && arr[i] > a)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = a;
    }
}

template <typename T>
int partition(T arr[], int ind_start, int ind_end)
{
    // последний элемент берется pivot-элементом
    int pivot = arr[ind_end];

    // i - индекс элемента, меньшего пивота
    // j - индекс текущего элемента
    int i = (ind_start - 1);
    for (int j = ind_start; j <= ind_end - 1; j++)
    {
        // если текущий элемент <= пивоту
        if (arr[j] <= pivot) {

            //граница меньших элементов сдвигается право
            i++;
            //меньший элемент добавляется к другим меньшим справа
            swap(arr[i], arr[j]);
        }
    }
    // ставит пивот на его порядковую позицию
    // и возваращает его индекс
    swap(arr[i + 1], arr[ind_end]);
    return (i + 1);
}

template <typename T>
int partition_rand(T arr[], int ind_start, int ind_end)
{
    // выбирает случайный инлекс для пивота
    //srand(time(NULL));
    int random = ind_start + rand() % (ind_end - ind_start);

    // переставляет пивот с последним элементом
    // и применяет partition
    swap(arr[random], arr[ind_end]);
    return partition(arr, ind_start, ind_end);
}

template <typename T>
void quickSort(T arr[], int ind_start, int ind_end)
{
    if (ind_start < ind_end) {

        //получает индекс пивота разделенного массива
        int pi = partition_rand(arr, ind_start, ind_end);

        // отдельно сортирует подмассивы
        // до пивота и после пивота
        quickSort(arr, ind_start, pi - 1);
        quickSort(arr, pi + 1, ind_end);
    }
}

// выводит массив
template <typename T>
void printArray(T arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    int arr1[10];
    int arr2[10];
    int arr3[10];
    for (int i; i <=10; i++){
        arr1[i] = rand();
        arr2[i] = rand();
        arr3[i] = rand();
    }

    int arrayLength = sizeof(arr1) / sizeof(arr1[0]);

    quickSort(arr1, 0, arrayLength - 1);
    cout << "QuickSort:" << endl;
    printArray(arr1, arrayLength);
    arrayLength = sizeof(arr2) / sizeof(arr2[0]);
    selectionSort(arr2, arrayLength);
    cout << "SelectionSort:" << endl;
    printArray(arr2, arrayLength);
    arrayLength = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr2, arrayLength);
    cout << "InsertSort:" << endl;
    printArray(arr3, arrayLength);

    return 0;
}
