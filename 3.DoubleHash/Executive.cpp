/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: Jan 30, 2018
*/
#include "Bucket.h"
#include "Quadratic.h"
#include "DoubleH.h"
#include "Executive.h"

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

//constructor
Executive::Executive()
{

}


//run method
void Executive::run(string file)
{
    //read data from the input file data.txt
    
    ifstream inp;
    inp.open(file);//open file
    
    int numb;  //constant number of buckets
    //inp>>numb; //get the size of the array

    Quadratic <int>* Q=new Quadratic <int> ();
    DoubleH <int>* D = new DoubleH <int> ();
    
    //Hashing <int>* H = new Hashing <int> (numb); //set the size to the array (using constructer to create an array with empty list in each bucket)
    //cout<<"size:"<<numb<<endl;
    while(!inp.eof()) //read through the whole file till it ends
    {
      inp>>numb;
      Q->Insert(numb);
      D->Insert(numb);
    }
    inp.close(); //close the file
    
    int opt=0; //options
    while (opt!=5)
    {
        cout<<". . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"1 - Insert"<<endl;
        cout<<"2 - Delete"<<endl;
        cout<<"3 - Find"<<endl;
        cout<<"4 - Print"<<endl;
        cout<<"5 - Exit"<<endl;

        // cout<<" Load factor of hash table with quadratic probing is "<<Q->loadFactor()<<endl;
        // cout<<" Load factor of hash table with double hashing is "<<D->loadFactor()<<endl;
        cin>>opt;

         if (opt==1) //Insert a number
        {
            int num;
            cout<<"Please Enter a number to be inserted: "<<endl;
            cin>>num;

            if(Q->Insert(num) == false) // the number is already exist
            {
                cout<<"Failed to insert "<<num<<" into hash table with quadratic probing"<<endl;
            }
            else
            {
                Q->Insert(num);
            }

            if (D->Insert(num) == false)
            {
               cout<<"Failed to insert "<<num<<" into hash table with double hashing"<<endl;
            }
            else
            {
                D->Insert(num);
            }

            cout<<" Load factor of hash table with quadratic probing is "<<Q->loadFactor()<<endl;
            cout<<" Load factor of hash table with double hashing is "<<D->loadFactor()<<endl;

        }

        if (opt==2) //delete a target value
        {
            int num;
            cout<<"Enter a number to be deleted : "<<endl;
            cin>>num;

            if(Q->Find(num) == false) //the numer is not exist.
            {
                cout<<num<<" doesn't exist in the hash table with quadratic probing. "<<endl;
            }
            else
            {
                Q->Remove(num);
                cout<<" Successfully deleted "<<num<<" from the hash table with quadratic probing. "<<endl;
            }

            if (D->Find(num) == false)
            {
                cout<<num<<" doesn't exist in the hash table with double hashing. "<<endl;
            }
            else
            {
                D->Remove(num);
                cout<<" Successfully deleted "<<num<<" from the hash table with double hashing. "<<endl;
            }

                cout<<" Load factor of hash table with quadratic probing is "<<Q->loadFactor()<<endl;
                cout<<" Load factor of hash table with double hashing is "<<D->loadFactor()<<endl;
        }
        

        if (opt==3) //Find a target value
        {
            int num;
            cout<<"Enter a number to be found: "<<endl;
            cin>>num;

            if(Q->Find(num) == false) //the numer is not exist.
            {
                cout<<num<<" does not exist in the hash table with quadratic probing. "<<endl;
            }
            else
            {
                cout<<num<<" exists in the hash table with quadratic probing."<<endl;
            }
            
            if(D->Find(num) == false) //the numer is not exist.
            {
                cout<<num<<" does not exist in the hash table with double hashing. "<<endl;
            }
            else
            {
                cout<<num<<" exists in the hash table with double hashing."<<endl;
            }
            
        }

        if (opt==4) //Print the whole list
        {
            cout<<"Hash table with quadratic probing:"<<endl;
            Q->Print();

            cout<<"Hash table with double hashing:"<<endl;
            D->Print();
           
        }

        if (opt==5) //Exit
        {
            cout<<"Bye bye!"<<endl;
            cout<<"______________________________________"<<endl;
            delete Q;
            delete D;
        }

    }
}
