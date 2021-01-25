/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|     PlusProtect API in C++     |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: plusProtect.hh
	Functions' prototypes for the "PlusProtect"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "activity.hh"

class PlusProtect: public Activity{
    protected:
        int _plusProtect;
    public:
    	PlusProtect():_plusProtect(0){};
    	virtual ~PlusProtect()= default;
     
        int getPlusProteger(){return _plusProtect;};
        int getPlusImmu(){return 0;};
        int getMoinsProtect(){return 0;}; 
        
        void show()
        {
        	std::cout << "C'est un objet < "<< nom <<" >, cette activité augmente le point de protection : - "<<_plusProtect<<std::endl;
        };
};