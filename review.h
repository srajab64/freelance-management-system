#ifndef REVIEW_H
#define REVIEW_H
#include<iostream>
#include<string>
#include<fstream>
#include"freelancer.h"
#include "client.h"
using namespace std;
class Review //CLASS FOR CLIENT FEEDBACK ON FREELANCER
{
    Freelancer *freelancer; //composition pointer to freelancer instance
    Client *client;    //composition pointer to client instance
    int rating; //rating of freelancer by client
    string comments; //comments of client on freelancers work
    public:
    //CONSTRUCTORS WITH DEFAULT PARAMETERS FOR INTIALIZATION
    Review(Freelancer *f, Client *c, int r, string com):freelancer(f),client(c),rating(r),comments(com){}
    void show() //FUNCTION TO SHOW REVIEW DETAILS
    {
        ofstream outfile("output.txt",ios::app);
        cout<<"REVIEW BY CLIENT: "<<endl;
        if(client!=nullptr)
        {
            client->show();
        }
        if(freelancer)
        {
            freelancer->show();
        }
        cout<<"RATING:"<<rating<<"/5"<<endl;
        cout<<"COMMENTS: "<<comments<<endl;
    }
    //getters for rating and comments
    int getRating()
    {
        return rating;
    }
    string getcomments()const
    {
        return comments;
    }
    Client * getClient() const
    {
        return client;
    }
    Freelancer* getFreelancer() const
    {
        return freelancer;
    }
};
#endif