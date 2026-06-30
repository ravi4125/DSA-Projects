#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "\nEnter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nUnique Elements: ";

    for (int i = 0; i < n; i++)
    {
        bool duplicate = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}