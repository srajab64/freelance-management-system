#ifndef   PROJECT_H
#define   PROJECT_H
#include<iostream>
#include<string>
#include<fstream>
#include "task.h"
#include "expense.h"
#include "payment.h"
using namespace std;
 const int Max_Tasks= 10; //MAXIMUM NUMBER OF TASKS A PROJECT CAN HAVE
class Project   //ABSTRACT BASE CLASS FOR PROJECTS
{
    protected:
    string title; //TITLE OF THE PROJECT
    int taskCount; //NUMBER OF TASKS IN THE PROJECT
    Task tasks[Max_Tasks]; //COMPOSITION FIXED ARRAY SIZE OF TASK OBJECTS
    Expense expense; //COMPOSITION 
    Payment payment; //COMPOSITION
    public:
    Project(string t, Expense e, Payment p):title(t),taskCount(0),expense(e),payment(p){}
    virtual ~Project(){}//Destructor to clean up memory
    void addTask(const Task &task) //FUNCTION TO ADD TASKS TO PROJECT
    {
        ofstream outfile("output.txt",ios::app);
        if (taskCount<Max_Tasks)
        {
            tasks[taskCount++]=task; //FOR ADDING TASKS AND INCREMENT COUNT
        }
        else
        {
            cout<<"CANNOT ADD MORE TASKS!!"<<endl;
        }
    }
    void showTasks()const //FUNCTION TO DISPLAY TASKS ADDED TO PROJECT
    {
        ofstream outfile("output.txt",ios::app);
       for(int i=0; i<taskCount; ++i)
       {
       cout<<"TASK no:"<<(i+1)<<endl;
       tasks[i].show();
       cout<<endl;
       }
    }
    //GETTERS FORE RETRIEVING INDIVIDUAL DATA 
    string getTitle()const
    {
        ofstream outfile("output.txt",ios::app);
        return title;
    }
    void setExpense(Expense e)
    {
        expense = e;
    }
    void setPayment(Payment p)
    {
        payment = p;
    }
    void showExpense()
    {
        ofstream outfile("output.txt",ios::app);
        expense.show();
    }
    void showPayment()
    {
        ofstream outfile("output.txt",ios::app);
        payment.show();
    }
    virtual double calculateTotalCost()=0; //ABSTRACT METHOD FOR CALCULATING TOTAL COST OF PROJECT
    int getTaskCount()const{return taskCount;} //GETTER FOR TASK COUNT
    const Task& getTask(int index)const{return tasks[index];} //GETTER FOR TASK AT INDEX
}; 
#endif