/**
*	@file : Executive.h
*	@author :Lu Yin
*	@date : March 12, 2018
*/

#include "Executive.h"
#include "Max_Five_Heap.h"
#include "Min_Five_Heap.h"

using namespace std;

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

//constructor
Executive::Executive()
{

}
Executive::~Executive()
{
    // delete Min;
    // delete Max;
}

//run method
void Executive::run(string name)
{
    Max_Five_Heap<int>* Max = new Max_Five_Heap<int> (name,500);
    Min_Five_Heap<int>* Min = new Min_Five_Heap<int> (name,500);
    int h=0;
    while (h!=3)
    {
        cout<<"-----------------------------------------"<<endl;
        cout<<"1- Max Five Heap"<<endl;
        cout<<"2- Min Five Heap"<<endl;
        cout<<"3- Exit"<<endl;
        cin>>h;

        if (h==1)
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
                        //Max->levelorder();
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
                        //Max->levelorder();
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
            }

        }
        else if (h==2)
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
                        //Min->levelorder();
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
                        //Min->levelorder();
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
            }   
    
        }
        else
        {
            cout<<"Byebye!"<<endl;
        }
    }
    //Min->~Min_Five_Heap();
    //Max->~Max_Five_Heap();
    delete Min;
    delete Max;
}