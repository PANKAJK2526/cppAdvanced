#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 9};

    int first = 0;
    int last = sizeof(arr) / sizeof(int);
    int target = 5;

    while (last > first)
    {
        int mid = (last + first) / 2;
        if (arr[mid] == target)
        {
            cout << "Found at Position: " << mid + 1;
            break;
        }
        else if (arr[mid] > target)
        {
            last = mid;
        }
        else if (arr[mid] < target)
        {
            first = mid;
        }
    }

    return 0;
}