#include <QtCore/QCoreApplication>
#include <iostream>

template <class Item>
void print (Item arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
         std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <class Item>
void exch(Item& A, Item& B)
{
    Item t = A;
    A = B;
    B = t;
}

template <class Item>
void compexch(Item& A, Item& B)
{
    if (A > B)exch(A, B);
}

template <class Item>
void selection(Item arr[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = min; j <= r; j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }
        exch(arr[min], arr[i]);
    }
}

template <class Item>
void bubble(Item arr[], int l, int r){
    for (int i = r; i <= r; i--)
        for (int j = i; j > l; j--)
            compexch(arr[j], arr[j-1]);
}

template <class Item>
void insertion (Item arr[], int l, int r)
{
    for (int i = r; i > l; i--)
        compexch(arr[i-1], arr[i]);
    for(int i = l+2; i <= r; i++)
    {
        int j = i;
        Item v = arr[i];
        while(v < arr[j-1])
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v;
    }
}

template <class Item>
void quick_sort(Item arr[], int l, int r)
{
    int i = l;
    int j = r;
    Item mid = arr[(l+r)/2];
    do
    {
        while(arr[i] < mid)++i;
        while(arr[j] > mid)--j;
        compexch(arr[i], arr[j]);
        i++;
        j--;
    }
    while (i < j);
    if(l < j)quick_sort(arr, l, j);
    if(i < r)quick_sort(arr, i, r);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const int N = 10;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = (100.0/RAND_MAX)*rand();
    }
    print(arr, N);
    //selection(arr, 0, N-1);
    //bubble(arr, 0, N-1);
    insertion(arr, 0, N-1);
    //shellsort(arr, 0, N-1);
    //quick_sort(arr, 0, N-1);
    
    print(arr, N);
    return a.exec();
}
