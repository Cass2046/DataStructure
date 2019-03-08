/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: April 8, 2018
*/
#include "BinaryNode.h"
#include "Executive.h"
#include "BST.h"
#include "Timer.cpp"


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
Executive::~Executive()
{
}

//run method
void Executive::run()
{
    
    int opt=0; //options
    while (opt!=2)
    {
        cout<<". . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"1 - Performance"<<endl;
        cout<<"2 - Exit"<<endl;
       
        cin>>opt;

         if (opt==1) //Insert a number
        {
            int m = 1000000;
            int size = 10000000;
            cout<<"Performance(bst):"<<endl;
            cout<<"1,000,000|2,000,000|3,000,000|4,000,000|5,000,000"<<endl;
            
            Timer T;
            double* avemaxTime = new double [6];
            double* aveminTime = new double [6];
            BST <int>* B;
            cout<<"Build: ";
            for(int k=1;k<=5;k++)
            {
                double bTime= 0.0;
                double maxTime = 0.0;
                double minTime = 0.0;
                for(int i=1; i<=5; i++)
                {
                    srand(i);
                    B = new BST<int>();
                    for(int j=0;j<(k*m);j++)
                    {
                        int num=rand()%(5*m)+1;
                        T.start();
                        B->Insert(num);
                        bTime = bTime + T.stop();
                    } 
                    for(int j=0;j<(0.001*k*m);j++)
                    {
                        T.start();
                        B->DeleteMax();
                        maxTime = maxTime + T.stop();
                    }
                    for(int j=0;j<(0.001*k*m);j++)
                    {
                        T.start();
                        B->DeleteMin();
                        minTime = minTime + T.stop();
                    }
                    delete B;
                }
                avemaxTime[k] = maxTime/5;
                aveminTime[k] = minTime/5;
                cout<<bTime/5<<" ";
            }
            cout<<""<<endl;
            cout<<"Deletemin: "<<aveminTime[1]<<" "<<aveminTime[2]<<" "<<aveminTime[3]<<" "<<aveminTime[4]<<" "<<aveminTime[5]<<endl;
            cout<<"Deletemax: "<<avemaxTime[1]<<" "<<avemaxTime[2]<<" "<<avemaxTime[3]<<" "<<avemaxTime[4]<<" "<<avemaxTime[5]<<endl;

            cout<<"Performance(Min-5 Heap): "<<endl;
            cout<<"1,000,000|2,000,000|3,000,000|4,000,000|5,000,000"<<endl;
            Min_Five_Heap <int>* MinH; 
            cout<<"Build: ";
            for(int k=1;k<=5;k++)
            {
                double bTime= 0.0;
                double maxTime = 0.0;
                double minTime = 0.0;
                for(int i=1; i<=5; i++)
                {
                    srand(i);
                    MinH = new Min_Five_Heap<int>(size);
                    for(int j=0;j<(k*m);j++)
                    //for (int j=0; j<100; j++)
                    {
                        int num=rand()%(5*m)+1;
                        T.start();
                        MinH->insertNoBuild(num);
                        bTime = bTime + T.stop();
                    } 
                    T.start();
                    MinH->buildheap();
                    bTime = bTime + T.stop();

                    for(int j=0;j<(0.001 * k * m);j++)
                    //for (int j=0; j<0; j++)
                    {
                        T.start();
                        MinH->deletemax();
                        maxTime = maxTime + T.stop();
                    }
                    for(int j=0;j<(0.001 * k * m);j++)
                    //for (int j=0; j<10; j++)
                    {
                        T.start();
                        MinH->deletemin();
                        minTime = minTime + T.stop();
                    }
                    delete MinH;
                }
                avemaxTime[k] = maxTime/5;
                aveminTime[k] = minTime/5;
                cout<<bTime/5<<" ";
            }
            cout<<""<<endl;
            cout<<"Deletemin: "<<aveminTime[1]<<" "<<aveminTime[2]<<" "<<aveminTime[3]<<" "<<aveminTime[4]<<" "<<aveminTime[5]<<endl;
            cout<<"Deletemax: "<<avemaxTime[1]<<" "<<avemaxTime[2]<<" "<<avemaxTime[3]<<" "<<avemaxTime[4]<<" "<<avemaxTime[5]<<endl;

            cout<<"Performance(Max-5 Heap): "<<endl;
            cout<<"1,000,000|2,000,000|3,000,000|4,000,000|5,000,000"<<endl;
            Max_Five_Heap <int>* MaxH; 
            cout<<"Build: ";
            for(int k=1;k<=5;k++)
            {
                double bTime= 0.0;
                double maxTime = 0.0;
                double minTime = 0.0;
                for(int i=1; i<=5; i++)
                {
                    srand(i);
                    MaxH = new Max_Five_Heap<int>(size);
                    for(int j=0;j<(k*m);j++)
                    {
                        int num=rand()%(5*m)+1;
                        T.start();
                        MaxH->insertNoBuild(num);
                        bTime = bTime + T.stop();
                    } 
                    T.start();
                    MaxH->buildheap();
                    bTime = bTime + T.stop();
                    for(int j=0;j<(0.001 * k * m);j++)
                    //for (int j=0; j<10; j++)
                    {
                        T.start();
                        MaxH->deletemax();
                        maxTime = maxTime + T.stop();
                    }
                    for(int j=0;j<(0.001 * k * m);j++)
                    //for (int j=0; j<0; j++)
                    {
                        T.start();
                        MaxH->deletemin();
                        minTime = minTime + T.stop();
                    }
                    delete MaxH;
                }
                avemaxTime[k] = maxTime/5;
                aveminTime[k] = minTime/5;
                cout<<bTime/5<<" ";
            }
            cout<<""<<endl;
            cout<<"Deletemin: "<<aveminTime[1]<<" "<<aveminTime[2]<<" "<<aveminTime[3]<<" "<<aveminTime[4]<<" "<<aveminTime[5]<<endl;
            cout<<"Deletemax: "<<avemaxTime[1]<<" "<<avemaxTime[2]<<" "<<avemaxTime[3]<<" "<<avemaxTime[4]<<" "<<avemaxTime[5]<<endl;
            delete[] avemaxTime;
            delete[] aveminTime;
                       
        }
        if (opt==2) //Exit
        {
            cout<<"Bye bye!"<<endl;
            cout<<"______________________________________"<<endl;
        }

    }
}
