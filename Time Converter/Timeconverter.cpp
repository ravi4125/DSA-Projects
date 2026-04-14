#include <iostream>
#include <iomanip>
using namespace std;

class TimeConverter
{
private:
    int hours;
    int minutes;
    int seconds;
    long long totalSeconds;

public:
    TimeConverter() : hours(0), minutes(0), seconds(0), totalSeconds(0) {}

    // seconds → HH:MM:SS
    void secondsToHMS(long long secs)
    {
        totalSeconds = secs;
        hours = secs / 3600;
        secs %= 3600;
        minutes = secs / 60;
        seconds = secs % 60;
    }

    // HH:MM:SS → total seconds
    void hmsToSeconds(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
        totalSeconds = (long long)h * 3600 + (long long)m * 60 + s;
    }

    // result: seconds → HH:MM:SS
    void displayHMS() const
    {
        cout << "\nHH:MM:SS => "
             << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds
             << endl;
    }

    // result: HH:MM:SS → seconds
    void displaySeconds() const
    {
        cout << "\nTotal seconds: " << totalSeconds << endl;
    }
};

void showMenu()
{
    cout << "     TIME CONVERTER MENU\n";
    cout << "  1. Seconds  →  HH:MM:SS\n";
    cout << "  2. HH:MM:SS →  Seconds\n";
    cout << "  3. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    TimeConverter converter;
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            long long secs;
            cout << "\nEnter total seconds: ";
            cin >> secs;
            if (secs < 0)
            {
                cout << "Error: seconds cannot be negative.\n";
                break;
            }
            converter.secondsToHMS(secs);
            converter.displayHMS();
            break;
        }
        case 2:
        {
            int h, m, s;
            cout << "\nEnter hours: ";
            cin >> h;
            cout << "Enter minutes: ";
            cin >> m;
            cout << "Enter seconds: ";
            cin >> s;
            if (h < 0 || m < 0 || s < 0 || m >= 60 || s >= 60)
            {
                cout << "Error: invalid time values.\n";
                break;
            }
            converter.hmsToSeconds(h, m, s);
            converter.displaySeconds();
            break;
        }
        case 3:
            cout << "\nThank you....\n";
            break;
        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}