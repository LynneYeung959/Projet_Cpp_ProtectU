/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|       PlusImmu API in C++      |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: plusImmu.hh
	Functions' prototypes for the "PlusImmu"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "activity.hh"

class PlusImmu: public Activity{
    protected:
        int _plusImmu;
    public:
    	PlusImmu():_plusImmu(0){};
        virtual ~PlusImmu()= default;

        int getPlusImmu(){return _plusImmu;};
        int getPlusProteger(){return 0;};
        int getMoinsProtect(){return 0;};
        
        void show()
        {
        	std::cout << "C'est un objet < "<< nom <<" >, cette activité augmente le point de l'immunité : - "<<_plusImmu<<std::endl;
        };

};