#include <iostream>
using namespace std;

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);
    int factor;

    cin >> factor;

    for (int i : arr)
    {
        cout << i << " ";
    }

    while (factor--)
    {
        int temp = arr[0];
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
    }

    cout << endl;

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}