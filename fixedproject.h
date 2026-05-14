#ifndef FIXEDPROJECT_H
#define FIXEDPROJECT_H
#include<iostream>
#include<string>
#include "project.h"
using namespace std;
class FixedProject :public Project //DERIVED CLASS OF PROJECT
//REPRESENTS A PROJECT WITH A FIXED TOTAL COST
{
    double totalcost; //FIXED TOTAL COST OF THE PROJECT
    public:
    FixedProject(string t="", Expense e=Expense(), Payment p=Payment(), double cost=0.0):Project(t,e,p),totalcost(cost){}
    // Overrides the abstract method from Project
    // Returns the predetermined total cost
    double calculateTotalCost() 
    {
        ofstream outfile("output.txt",ios::app);
        return totalcost;
    }
    void setTotalCost(double cost){totalcost = cost;}
};
#endif // FIXEDPROJECT_H