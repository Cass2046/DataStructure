/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: March 10, 2018
*/

#include "List.h"
#include "Node.h"
#include "Hashing.h"
#include "Bucket.h"
#include "Quadratic.h"
#include "DoubleH.h"
#include "Executive.h"
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


//run method
void Executive::run(string file)
{
    int opt=0; //options
    while (opt!=3)
    {
        cout<<". . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"1 - Test HashTables "<<endl;
        cout<<"2 - Performance Comparison "<<endl;
        cout<<"3 - Exit"<<endl;
        cin>>opt;


        if (opt==1)
        {
            int s;
            cout<<"What is the table size? "<<endl;\
            cin>>s;
            //read data from the input file data.txt
            ifstream inp;
            inp.open(file); //open file
            int numb;
            Hashing <int>* H = new Hashing <int> (s); 
            Quadratic <int>* Q=new Quadratic <int> (s, 4);
            DoubleH <int>* D = new DoubleH <int> (s, 5, 4);
            while(!inp.eof()) //read through the whole file till it ends
            {
                inp>>numb;
                H->Insert(numb);
                Q->Insert(numb);
                D->Insert(numb);
            }
            inp.close(); //close the file
    
            cout<<"Open Hashing: "<<endl;
            H->Print();
            cout<<" "<<endl;
            cout<<"Hash Table with Quadratic Probing: "<<endl;
            Q->Print();
            cout<<" "<<endl;
            cout<<"Hash Table with Double Hashing: "<<endl;
            D->Print();
            cout<<" "<<endl;
        }

        if (opt==2) //delete a target value
        {
            int m=1000003;
            Timer in;  //time of insertion
            Timer se;  //time of search
            //insertion
            double OHIns_time;
            double QPIns_time;
            double DHIns_time;
            //search
            double OHsearchS_time=0;
            double OHsearchU_time=0;
            double QPsearchS_time=0;
            double QPsearchU_time=0;
            double DHsearchS_time=0;
            double DHsearchU_time=0;
            
            Hashing <int>* H; 
            Quadratic <int>* Q;
            DoubleH <int>* D;

            int seed;
            cout<<"What is the seed? (1-5) "<<endl;
            cin>>seed;
            srand(seed);

            cout<<"Open Hashing: "<<endl;
            cout<<" "<<endl;
            for (int i=1; i<=5; i++)
            {
                H=new Hashing <int> (m);
                in.start();
                for (int j=1; j<=i*100000; j++)
                {
                    int e=rand()%(5*m)+1;
                    H->Insert(e);
                }
                OHIns_time=in.stop();
                cout<<"Time of insertion "<<i*100000<<" elements :";
                cout<<OHIns_time<<endl;
            
                for (int k=1; k<=10000; k++)
                {
                    int f=rand()%(5*m)+1;
                    se.start();  
                    if (H->Find(f) == true)
                    {
                        OHsearchS_time=se.stop()+OHsearchS_time;
                    }
                    else
                    {
                        OHsearchU_time=se.stop()+OHsearchU_time;
                    }
                }
               
                cout<<"Time of search "<<i*10000<<" elements-";
                cout<<"Successful : "<<OHsearchS_time<<"      ";
                cout<<"Unsuccessful : "<<OHsearchU_time<<endl;
                cout<<""<<endl;
                delete H;
            }
            cout<<""<<endl;
            cout<<"- - - - - - - - - "<<endl;
            cout<<""<<endl;

            cout<<"Quadratic Probing: "<<endl;
            for (int i=1; i<=5; i++)
            {
                Q=new Quadratic <int> (m, 20);
                in.start();
                for (int j=1; j<=i*100000; j++)
                {
                    int e=rand()%(5*m)+1;
                    Q->Insert(e);
                }
                QPIns_time=in.stop();
                cout<<"Time of insertion "<<i*100000<<" elements :";
                cout<<QPIns_time<<endl;

                for (int k=1; k<=10000; k++)
                {
                    int f=rand()%(5*m)+1;
                    se.start();  
                    if (Q->Find(f) == true)
                    {
                        QPsearchS_time=se.stop()+QPsearchS_time;
                    }
                    else
                    {
                        QPsearchU_time=se.stop()+QPsearchU_time;
                    }
                }
               
                cout<<"Time of search "<<i*10000<<" elements-";
                cout<<"Successful : "<<QPsearchS_time<<"      ";
                cout<<"Unsuccessful : "<<QPsearchU_time<<endl;
                cout<<""<<endl;
                delete Q;
            }
            cout<<""<<endl;
            cout<<"- - - - - - - - - "<<endl;
            cout<<""<<endl;

            cout<<"Double Hashing: "<<endl;
            for (int i=1; i<=5; i++)
            {
                D=new DoubleH <int> (m, 997, 20);
                in.start();

                for (int j=1; j<=i*100000; j++)
                {
                    int e=rand()%(5*m)+1;
                    D->Insert(e);
                }
                DHIns_time=in.stop();
                cout<<"Time of insertion "<<i*100000<<" elements :";
                cout<<DHIns_time<<endl;

                for (int k=1; k<=10000; k++)
                {
                    int f=rand()%(5*m)+1;
                    se.start();  
                    if (D->Find(f) == true)
                    {
                        DHsearchS_time=se.stop()+DHsearchS_time;
                    }
                    else
                    {
                        DHsearchU_time=se.stop()+DHsearchU_time;
                    }
                }
                cout<<"Time of search "<<i*10000<<" elements-";
                cout<<"Successful : "<<DHsearchS_time<<"      ";
                cout<<"Unsuccessful : "<<DHsearchU_time<<endl;
                cout<<""<<endl;
                delete D;
            }
            cout<<""<<endl;
        }

        if (opt==3) //Find a target value
        {
            cout<<"Bye bye!"<<endl;
            cout<<"______________________________________"<<endl;
           
        }
        
    }
}
