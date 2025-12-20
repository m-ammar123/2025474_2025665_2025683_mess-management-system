Mess Management System

 Overview

The Mess Management System is a C++ console-based application designed to manage student meal attendance and billing in a hostel mess. It provides functionalities for adding students, marking meal attendance, generating bills, and maintaining pending dues with persistent storage.

 Features

Student Management

Add new students with duplicate registration number check.
View all students in a clean tabular format.


Meal Attendance

Mark attendance for Breakfast, Lunch + Dinner, or Both.


Billing

Automatic calculation of bills based on meal rates.
Includes pending dues in total bill.


Dues Management

Clear dues and reset monthly attendance.


Month-End Summary

Display all students with detailed billing summary.


File Handling

Save and load student data for persistence.




🛠 Technologies Used

Language: C++
Concepts: Arrays, Functions, Recursion, Pointers, File Handling
File I/O: Text file for saving/loading student data


 Project Structure
├── main.cpp        # Source code
├── mess_data.txt   # Data file (auto-generated)
└── README.md       # Project documentation


▶ How to Run

Compile the program:
g++ main.cpp -o mess_management

Run the executable:

./mess_management




⚙ Configuration

Meal Rates:

Breakfast: Rs. 250
Lunch + Dinner: Rs. 450


Maximum Students: 50 (can be changed in MAX constant)



👨‍💻 Author

Muhammad Ammar
Reg#: 2025474
Degree: BSAI

Muhammad Zohran
Reg#: 2025665
Degree: BSAI

Mustafa Khan
Reg#: 2025683
Degree: BSAI

