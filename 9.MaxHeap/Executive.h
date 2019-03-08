/*
/ @file: Executive.h
/ @author: Lu Yin
/ @date: April 8, 2018
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "BinaryNode.h"
#include "Executive.h"
#include "BST.h"
#include "Min_Five_Heap.h"
#include "Max_Five_Heap.h"
#include "Timer.cpp"

using namespace std;

class Executive
{
    public:
    //constructor
    Executive();
	~Executive();
    //main methods with UI
    void run();

    private:
	
};
#endif
