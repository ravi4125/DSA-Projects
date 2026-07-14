#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Class Template
template <class T>
class MemoryCalculate
{
private:
    T id;
    string name;

public:
    // Constructor
    MemoryCalculate(T studentId, string studentName)
    {
        id = studentId;
        name = studentName;
    }

    // Get ID
    T getId()
    {
        return id;
    }

    // Display Student
    void display()
    {
        cout << "\n--------------------------" << endl;
        cout << "Student ID   : " << id << endl;
        cout << "Student Name : " << name << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    vector<MemoryCalculate<int>> students;

    int choice;

    while (true)
    {
        cout << "\n========== Student Management System ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter Choice : ";

        cin >> choice;

        // Handle invalid menu input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input!" << endl;
            continue;
        }

        if (choice == 1)
        {
            int id;
            string name;
            bool found = false;

            cout << "Enter Student ID : ";
            cin >> id;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid ID!" << endl;
                continue;
            }

            // Check duplicate ID
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getId() == id)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "Student ID already exists!" << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter Student Name : ";
                getline(cin, name);

                students.push_back(MemoryCalculate<int>(id, name));

                cout << "Student Added Successfully." << endl;
            }
        }

        else if (choice == 2)
        {
            if (students.empty())
            {
                cout << "No Students Found." << endl;
            }
            else
            {
                cout << "\n========== Student List ==========" << endl;

                for (int i = 0; i < students.size(); i++)
                {
                    students[i].display();
                }
            }
        }

        else if (choice == 3)
        {
            if (students.empty())
            {
                cout << "No Students Available." << endl;
                continue;
            }

            int id;
            bool found = false;

            cout << "Enter Student ID to Remove : ";
            cin >> id;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getId() == id)
                {
                    students.erase(students.begin() + i);
                    found = true;
                    cout << "Student Removed Successfully." << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student ID Not Found." << endl;
            }
        }

        else if (choice == 4)
        {
            if (students.empty())
            {
                cout << "No Students Available." << endl;
                continue;
            }

            int id;
            bool found = false;

            cout << "Enter Student ID to Search : ";
            cin >> id;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getId() == id)
                {
                    cout << "\nStudent Found";
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student ID Not Found." << endl;
            }
        }

        else if (choice == 5)
        {
            cout << "\nThank You!" << endl;
            break;
        }

        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}