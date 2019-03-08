/*
/ @file: Executive.h
/ @author: Lu Yin
/ @date: Feb 12, 2018
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "Node.h"
#include "Executive.h"
#include "TwoThreeTree.h"

using namespace std;

class Executive
{
    public:
    //constructor
    Executive();
	~Executive();
    
    //main methods with UI
    void run(char* name);

    private:
	TwoThreeTree <int>* N;

};
#endif
