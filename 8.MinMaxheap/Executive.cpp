/**
*	@file : Executive.h
*	@author :Lu Yin
*	@date : March 12, 2018
*/

#include "Executive.h"
#include "MaxMinHeap.h"
#include "MinMaxHeap.h"

using namespace std;

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

//constructor
Executive::Executive(char*file)
{
    string str(file);
    if (str=="maxmin")
    {
        option = 1;
    }
    else if (str=="minmax")
    {
        option = 2;
    }
}
Executive::~Executive()
{

}

//run method
void Executive::run(string name)
{
    MaxMinHeap<int>* Max = new MaxMinHeap<int> (name,500);
    MinMaxHeap<int>* Min = new MinMaxHeap<int> (name,500);
    int h=0;

    if (option==1)
    {
        //Max = new Max_Five_Heap<int> (name,500);
        int opt=0; 
        while (opt!=7)
        {
            cout<<"............................................."<<endl;
            cout<<"Please choose one of the following commands: "<<endl;
            cout<<"1-	insert"<<endl;
            cout<<"2-	deleteMin"<<endl;
            cout<<"3-	findMin"<<endl;
            cout<<"4-	findMax"<<endl;
            cout<<"5-	deleteMax"<<endl;
            cout<<"6-	levelOrder"<<endl;
            cout<<"7-	exit"<<endl;
            cin>>opt;
            if (opt==1)
            {
                int num;
                cout<<"Enter a value to be inserted:"<<endl;
                cin>>num;

                Max->insert(num);

                Max->levelorder();
            }
            else if (opt==2)
            {
                if (Max->deletemin()==false)
                {
                    cout<<"There is no minmum to delete. "<<endl;
                }
                else
                {
                    Max->levelorder();
                }
            }
            else if(opt==3)
            {
                if (Max->findmin()==-1)
                {
                    cout<<"There is no minmum to delete."<<endl;
                }
                else
                {
                    cout<<"Min value is: "<<Max->findmin()<<endl;
                }
            }
            else if(opt==4)
            {
                if (Max->findmax()==-1)
                {
                    cout<<"There is no minmum."<<endl;
                }
                else
                {
                    cout<<"Max value is: "<<Max->findmax()<<endl;
                }
            }
            else if(opt==5)
            {
                if (Max->deletemax()==false)
                {
                    cout<<"There is no maximum to delete."<<endl;
                }
                else
                {
                    Max->levelorder();
                }
                
            }
            else if(opt==6)
            {
                Max->levelorder();
            }
            else
            {
                cout<<"Byebye!"<<endl;
            }
        }
    }

    else if (option==2)
    {
        //read data from the input file data.txt
        //Min = new Min_Five_Heap<int> (name,500);

        int opt=0; 
        while (opt!=7)
        {
            cout<<"............................................."<<endl;
            cout<<"Please choose one of the following commands: "<<endl;
            cout<<"1-	insert"<<endl;
            cout<<"2-	deleteMin"<<endl;
            cout<<"3-	findMin"<<endl;
            cout<<"4-	findMax"<<endl;
            cout<<"5-	deleteMax"<<endl;
            cout<<"6-	levelOrder"<<endl;
            cout<<"7-	exit"<<endl;
            cin>>opt;

            if (opt==1)
            {
                int num;
                cout<<"Enter a value to be inserted:"<<endl;
                cin>>num;

                Min->insert(num);
                Min->levelorder();
            }
            else if (opt==2)
            {
                if (Min->deletemin()==false)
                {
                    cout<<"There is no minmum to delete. "<<endl;
                }
                else
                {
                    Min->levelorder();
                }
            }
            else if(opt==3)
            {
                if (Min->findmin()==-1)
                {
                    cout<<"There is no minmum to delete."<<endl;
                }
                else
                {
                    cout<<"Min value is: "<<Min->findmin()<<endl;
                }
            }
            else if(opt==4)
            {
                if (Min->findmax()==-1)
                {
                    cout<<"There is no minmum."<<endl;
                }
                else
                {
                    cout<<"Max value is: "<<Min->findmax()<<endl;
                }
            }
            else if(opt==5)
            {
                if (Min->deletemax()==false)
                {
                    cout<<"There is no maximum to delete."<<endl;
                }
                else
                {
                    Min->levelorder();
                }
                
            }
            else if(opt==6)
            {
                Min->levelorder();
            }
            else
            {
                cout<<"Byebye!"<<endl;
            }
        }   
    }
    
    delete Min;
    delete Max;
}