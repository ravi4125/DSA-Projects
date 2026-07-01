#include <iostream>
#include <climits>
#include <limits>
using namespace std;

int getNumber(string message)
{
    int num;

    while (true)
    {
        cout << message;
        cin >> num;

        if (cin.fail())
        {
            cout << "Invalid Input! Please enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            return num;
        }
    }
}

void removeDuplicate()
{
    int n = getNumber("Enter number of elements: ");

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = getNumber("Enter element " + to_string(i + 1) + ": ");
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
            cout << arr[i] << " ";
    }

    cout << endl;
}

void largestElement()
{
    int n = getNumber("Enter number of elements: ");

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = getNumber("Enter element " + to_string(i + 1) + ": ");
    }

    int largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
    }

    cout << "\nLargest Element = " << largest << endl;
}

void sortArray()
{
    int n = getNumber("Enter number of elements: ");

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = getNumber("Enter element " + to_string(i + 1) + ": ");
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nAscending Order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nDescending Order: ";
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";

    cout << endl;
}

void countNumbers()
{
    int n = getNumber("Enter number of elements: ");

    int arr[n];

    int positive = 0, negative = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = getNumber("Enter element " + to_string(i + 1) + ": ");

        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
    }

    cout << "\nPositive Numbers = " << positive;
    cout << "\nNegative Numbers = " << negative << endl;
}

void magicSorter()
{
    int n = getNumber("Enter number of elements: ");

    int arr[n], even[n], odd[n];
    int e = 0, o = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = getNumber("Enter element " + to_string(i + 1) + ": ");

        if (arr[i] % 2 == 0)
            even[e++] = arr[i];
        else
            odd[o++] = arr[i];
    }

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (even[j] > even[j + 1])
            {
                int temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < o - 1; i++)
    {
        for (int j = 0; j < o - i - 1; j++)
        {
            if (odd[j] < odd[j + 1])
            {
                int temp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = temp;
            }
        }
    }

    cout << "\nFinal Array: ";

    for (int i = 0; i < e; i++)
        cout << even[i] << " ";

    for (int i = 0; i < o; i++)
        cout << odd[i] << " ";

    cout << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== SORTIFY PROJECT ==========\n";
        cout << "1. Remove Duplicate Elements\n";
        cout << "2. Find Largest Element\n";
        cout << "3. Sort Ascending & Descending\n";
        cout << "4. Count Positive & Negative\n";
        cout << "5. Magic Sorter\n";
        cout << "6. Exit\n";

        choice = getNumber("\nEnter your choice: ");

        switch (choice)
        {
        case 1:
            removeDuplicate();
            break;

        case 2:
            largestElement();
            break;

        case 3:
            sortArray();
            break;

        case 4:
            countNumbers();
            break;

        case 5:
            magicSorter();
            break;

        case 6:
            cout << "Thank You!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}