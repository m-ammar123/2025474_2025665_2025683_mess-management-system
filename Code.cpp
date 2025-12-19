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

// Add student function:
void addStudent()
{
    cout << "\n==================== ADD STUDENT ====================\n";
    if (totalStudents >= MAX)
    {
        cout << " Maximum student limit reached!\n";
        return;
    }

    // Clear a single newline left by previous "cin >> choice"
    cin.ignore();       //To remove leftover '\n'

    cout << " Enter Registration Number: ";
    getline(cin , regNo[totalStudents]);

    //  do not add if regNo already exists
    int existingIndex = searchStudentRecursive(regNo, regNo[totalStudents], totalStudents - 1);
    if (existingIndex != -1)
    {
        cout << " Student with RegNo '" << regNo[totalStudents] << "' already exists.\n";
        cout << "------------------------------------------------------------\n";
        return;
    }

    cout << " Enter Name: ";
    getline(cin , studentName[totalStudents]);
    cout << " Enter Hostel: ";
    getline(cin , hostel[totalStudents]);
    cout << " Enter Room Number: ";
    getline(cin , room[totalStudents]);

    breakfast[totalStudents]   = 0;
    lunchDinner[totalStudents] = 0;
    pendingDues[totalStudents] = 0;

    totalStudents++;
    cout << " Student added successfully!\n";
    cout << "------------------------------------------------------------\n";
}


// View students function
void viewStudents()
{
    
    cout << "\n====================== STUDENTS ======================\n";

    // Handle empty list case if no students are enrolled
    if (totalStudents == 0) {
        cout << " No students enrolled.\n";
        return; 
    }

    // Fixed column widths to achieve table-like alignment
    const int W_REG   = 14; // Registration number width
    const int W_NAME  = 20; // Name width
    const int W_HOST  = 14; // Hostel width
    const int W_ROOM  = 10; // Room width
    const int W_BF    = 12; // Breakfast count width
    const int W_LD    = 14; // Lunch+Dinner count width
    const int W_DUES  = 14; // Pending dues width

    // Header row:
    // Using manipulators (left/right/setw) for alignment—kept exactly as in your code.
    cout << left << setw(W_REG)  << "RegNo"
         << setw(W_NAME)         << "Name"
         << setw(W_HOST)         << "Hostel"
         << setw(W_ROOM)         << "Room"
         << right << setw(W_BF)  << "Breakfast"
         << setw(W_LD)           << "Lunch+Dinner"
         << setw(W_DUES)         << "Pending Dues"
         << "\n";

    // Divider under the header whose length equals the sum of column widths
    cout << string(W_REG + W_NAME + W_HOST + W_ROOM + W_BF + W_LD + W_DUES, '-') << "\n";

    // Data rows: iterate over all students and print their fields aligned to columns
    for (int i = 0; i < totalStudents; i++)
    {
        // Text columns printed left-aligned; numeric columns printed right-aligned
        cout << left << setw(W_REG)  << regNo[i]
             << setw(W_NAME)         << studentName[i]
             << setw(W_HOST)         << hostel[i]
             << setw(W_ROOM)         << room[i]
             << right << setw(W_BF)  << breakfast[i]
             << setw(W_LD)           << lunchDinner[i]
             << setw(W_DUES)         << pendingDues[i]
             << "\n";
    }

    // Closing divider to finish the table view
       cout << string(W_REG + W_NAME + W_HOST + W_ROOM + W_BF + W_LD + W_DUES,'-')<<"\n";
}

// Mark attendance
void markAttendance() 
 {
    cout << "\n================= MARK ATTENDANCE ====================\n";
    string rNo;
    int choice;
    cout << " Enter Registration Number: ";
    cin >> rNo;
//using recursion to search for a student by entering registration number to mark attendance
    int index = searchStudentRecursive(regNo, rNo, totalStudents - 1);
    //if the index is -1 then no student will be showed
    if (index == -1)
     {
        cout << " Student not found!\n";
        return;
    }
// this part of code will mark attendance of student if he/she attend any meal
    cout << " Select meal attended:\n";
    cout << "  1) Breakfast\n";
    cout << "  2) Lunch + Dinner\n";
    cout << "  3) Both Breakfast and Lunch+Dinner\n";
    cout << " Enter choice: ";
    cin >> choice;
//calling updated function to update attendance
  updateAttendance(&breakfast[index], &lunchDinner[index], choice);
    cout << " Attendance updated successfully!\n";
    cout << "------------------------------------------------------------\n";
}

// Update attendance using pointers
void updateAttendance(int *bPtr, int *lPtr, int choice) 
{
    switch (choice)
    {
        case 1: (*bPtr)++; break;
        case 2: (*lPtr)++; break;
        case 3: (*bPtr)++; (*lPtr)++; break;
        default: cout << " Invalid choice!\n"; break;
    }
}