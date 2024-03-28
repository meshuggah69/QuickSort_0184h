#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparisons
int mov_count = 0; // number of data movements
int n;

void input() {
    while (true)
    {
        cout << "Masukan panjang elemen array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }

    cout << "\n----------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}

//swaps the element at index x with the element at index y
void swaps(int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp; // menggunakan nilai sementara 'temp'
    mov_count++;
}

void q_short(int low, int high)
{
    int pivot, i, j;
    if (low >= high) { // base case: jika sudah terurut atau array kosong
        return;
    }

    pivot = arr[low];
    i = low + 1;
    j = high;

    while (i <= j)
    {
        //search for an element greater than pivot
        while (arr[i] <= pivot && i <= high)
        {
            i++;
            cmp_count++;
        }
        cmp_count++;
        //search for an element less or equal to pivot
        while (arr[j] > pivot && j >= low)
        {
            j--;
            cmp_count++;
        }
        cmp_count++;
        if (i < j)
        {
            //swap the element at index i with the element at index j
            swaps(i, j); // menggunakan fungsi swap yang sudah didefinisikan sebelumnya
        }
    }

    //swap the pivot element with the element at index j
    swaps(low, j);

    //recursive call to sort the left sub array
    q_short(low, j - 1); // perbaiki indeks rekursi

    //recursive call to sort the right sub array
    q_short(j + 1, high); // perbaiki indeks rekursi
}

void display() {
    cout << "\n------------------" << endl;
    cout << "Sorted array" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparisons: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
    char ch;

    do {
        input();
        q_short(0, n - 1);
        display();
        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}