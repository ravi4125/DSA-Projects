#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    int positive = 0;
    int negative = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];

        if (arr[i] > 0)
            positive++;

        else if (arr[i] < 0)
            negative++;
    }

    cout << "\nPositive Numbers = " << positive;
    cout << "\nNegative Numbers = " << negative;

    return 0;
}