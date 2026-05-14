#include <iostream>
#include <fstream> //FOR FILE HANDLING
#include <string>
// CLASSES AND DERIVED CLASSES
#include "user.h"
#include "admin.h"
#include "client.h"
#include "expense.h"
#include "freelancer.h"
#include "project.h"
#include "payment.h"
#include "review.h"
#include "task.h"
#include "fixedproject.h"
#include "hourlyproject.h"
using namespace std;
int main()
{
    //OPENING FILE FOR FILE HANDLING
    ofstream outfile("output.txt",ios::app);
    if(!outfile)//ERROR MESSAGE INCASE FILE DOESNT OPEN
    {
        cerr<<"failed to open file"<<endl;
    }
    streambuf* originalCout=cout.rdbuf();
    // CREATING OBJECTS AND CALLING FUNCTIONS
    // USER
    cout << "*USER DETAILS*" << endl;
    User u1;
    u1.input(); // FUNCTION CALLING
    u1.show();
    cout << "*__________________________________________________________________________________*" << endl;
    // ADMIN INPUT
    cout << "*ADMIN DETAILS*" << endl;
    Admin a1;
    a1.input();
    a1.show();
    cout << "*___________________________________________________________________________________*" << endl;
    // FREELANCER INPUT
    cout << "*FREELANCER DETAILS*" << endl;
    Freelancer f1;
    f1.input();
    f1.show();
    cout << "____________________________________________________________________________________" << endl;
    // CLIENT INPUT
    cout << "*CLIENT DETAILS*" << endl;
    Client c1;
    c1.input();
    c1.show();
    cout << "*______________________________________________________________________________________*" << endl;
    // EXPENSE INPUT
    cout << "*EXPENSE*" << endl;
    Expense ex;
    ex.getExpense();
    ex.show();
    cout << "*______________________________________________________________________________________*" << endl;
    // PAYMENT INPUT
    cout << "*PAYMENT*" << endl;
    Payment p1;
    p1.getPayment();
    p1.show();
    cout << "*______________________________________________________________________________________*" << endl;
    // TASK INPUT
    cout << "*TASK DETAILS*" << endl;
    Task t1;
    t1.setTask("Design UI", "Design the user interface", "2025-06-01", 5, f1.getHourlyRate());
    t1.show();
    cout << "*_______________________________________________________________________________________*" << endl;
    // PROJECT INPUT
    cout << "*FIXED PROJECT*" << endl;
    FixedProject fp("Website Development", ex, p1, 5000); // CREATING FIXED PRICE PROJECT
    fp.addTask(t1);                                       // ADDING TASK TO PROJECT
    fp.showTasks();                                       // SHOWING TASKS IN PROJECT
    fp.showExpense();                                     // SHOWING EXPENSE IN PROJECT
    fp.showPayment();                                     // SHOWING PAYMENT IN PROJECT
    cout << "Total Cost: $" << fp.calculateTotalCost() << endl;
    cout << "*_______________________________________________________________________________________*" << endl;
    // HOURLY PROJECT INPUT
    cout << "*HOURLY PROJECT*" << endl;
    HourlyProject hp("MOBILE APPLICATION", ex, p1); // CREATING HOURLY PROJECT
    hp.addTask(t1);                                 // ADDING TASK TO PROJECT
    hp.showTasks();                                 // SHOWING TASKS IN PROJECT
    hp.showExpense();                               // SHOWING EXPENSE IN PROJECT
    hp.showPayment();                               // SHOWING PAYMENT IN PROJECT
    cout << "Total Cost (calculated from tasks): $" << hp.calculateTotalCost() << endl;
    cout << "*_______________________________________________________________________________________*" << endl;

    Review review(&f1, &c1, 4, "Excellent work but a bit late");
    review.show();

    cout.rdbuf(originalCout);
    outfile.close();
    return 0;
  
 }
