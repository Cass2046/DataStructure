/**
*	@file : Executive.h
*	@author :Lu Yin
*	@date : March 12, 2018
*	@brief: A header file for Executive class.
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Max_Five_Heap.h"
#include "Min_Five_Heap.h"

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
using namespace std;
class Executive
{
    public:
    Executive();
	~Executive();

    //main methods with UI
    void run(string name);

    private:
    // Max_Five_Heap<int>* Max;
    // Min_Five_Heap<int>* Min;

};
#endif
