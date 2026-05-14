#ifndef     HOURLYPROJECT_H
#define     HOURLYPROJECT_H
#include<iostream>
#include<fstream>
#include "project.h"
using namespace std;
class HourlyProject :public Project //DERIVED CLASS OF PROJECT FOR CALCULATING TOTAL SUM OF INDIVIDUAL TASK COSTS
{
    public:
    HourlyProject(string t, Expense e, Payment p):Project(t,e,p){}
    // Override of abstract function from base class
    // Computes total cost by summing the cost of all tasks
    double calculateTotalCost() override
    {
        ofstream outfile("output.txt",ios::app);
        double cost=0;
        //FOR ITTERATING THROUGH TASKS AND ACCUMULATE THEIR COST
        for(int i=0; i<taskCount;++i)
        {
            cost+=tasks[i].getCost();
        }
        return cost;
    }
};
#endif // HOURLYPROJECT_H