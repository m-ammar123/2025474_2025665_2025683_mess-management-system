#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>   // for setw, left, right
using namespace std;

const int MAX = 50;

// Student data arrays
string regNo[MAX];
string studentName[MAX];
string hostel[MAX];
string room[MAX];
int breakfast[MAX];
int lunchDinner[MAX];
int pendingDues[MAX];  // Track dues
int totalStudents = 0;

// Meal rates
const int RATE_BREAKFAST = 250;
const int RATE_LUNCH_DINNER = 450;

// Function declarations
void addStudent();
void viewStudents();
void markAttendance();
void generateBill(const string &rNo);
void generateMonthSummary();
void saveToFile();
void loadFromFile();
int  searchStudentRecursive(const string arr[], const string &key, int index);
void updateAttendance(int *bPtr, int *lPtr, int choice);
int  calculateBillRecursive(int *arr, int size, int rate);
void clearDues();


int main()
{
    int choice;
    loadFromFile();

    do 
    {
        cout << "\n============================================================\n";
        cout << "                     MESS MANAGEMENT SYSTEM                  \n";
        cout << "============================================================\n";
        cout << " 1) Add Student\n";
        cout << " 2) View Students\n";
        cout << " 3) Mark Meal Attendance\n";
        cout << " 4) Generate Bill for a Student\n";
        cout << " 5) Generate Month-End Summary\n";
        cout << " 6) Save Data to File\n";
        cout << " 7) Exit\n";
        cout << " 8) Clear Dues\n";
        cout << "------------------------------------------------------------\n";
        cout << " Enter your choice: ";
        cin >> choice;

        cout << "------------------------------------------------------------\n";
        switch (choice)
        {
            case 1: addStudent(); 
                  break;
            case 2: viewStudents(); 
                  break;
            case 3: markAttendance(); 
                  break;
            case 4:
                {
                    string rNo;
                    cout << " Enter Registration Number: ";
                    cin >> rNo;
                    generateBill(rNo);
                    break;
                }
            case 5: generateMonthSummary(); 
                  break;
            case 6: saveToFile(); 
                  break;
            case 7: 
                  cout << " Exiting program...\n"; break;
            case 8: clearDues(); 
                  break;
            default: 
                  cout << " Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
