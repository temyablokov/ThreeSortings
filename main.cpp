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

        // ������� ������ ������������ �������
        min_ind = i;
        for (j = i + 1; j < length; j++)
        if (arr[j] < arr[min_ind])
            min_ind = j;

        // ������ ����������� � ������
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

        // �������� ��� �������� > a �� 1 ������
        // ��� ������� �������� �������
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
    // ��������� ������� ������� pivot-���������
    int pivot = arr[ind_end];

    // i - ������ ��������, �������� ������
    // j - ������ �������� ��������
    int i = (ind_start - 1);
    for (int j = ind_start; j <= ind_end - 1; j++)
    {
        // ���� ������� ������� <= ������
        if (arr[j] <= pivot) {

            //������� ������� ��������� ���������� �����
            i++;
            //������� ������� ����������� � ������ ������� ������
            swap(arr[i], arr[j]);
        }
    }
    // ������ ����� �� ��� ���������� �������
    // � ����������� ��� ������
    swap(arr[i + 1], arr[ind_end]);
    return (i + 1);
}

template <typename T>
int partition_rand(T arr[], int ind_start, int ind_end)
{
    // �������� ��������� ������ ��� ������
    //srand(time(NULL));
    int random = ind_start + rand() % (ind_end - ind_start);

    // ������������ ����� � ��������� ���������
    // � ��������� partition
    swap(arr[random], arr[ind_end]);
    return partition(arr, ind_start, ind_end);
}

template <typename T>
void quickSort(T arr[], int ind_start, int ind_end)
{
    if (ind_start < ind_end) {

        //�������� ������ ������ ������������ �������
        int pi = partition_rand(arr, ind_start, ind_end);

        // �������� ��������� ����������
        // �� ������ � ����� ������
        quickSort(arr, ind_start, pi - 1);
        quickSort(arr, pi + 1, ind_end);
    }
}

// ������� ������
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
