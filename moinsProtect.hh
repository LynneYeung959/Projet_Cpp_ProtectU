/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|    MoinsProtect API in C++     |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: moinsProtect.hh
	Functions' prototypes for the "moinsProtect"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "activity.hh"

class MoinsProtect: public Activity{
    protected:
        int _moinsProtect;
    public:
    	MoinsProtect():_moinsProtect(0){};
 		virtual ~MoinsProtect() = default;

        int getMoinsProtect(){return _moinsProtect;};
        int getPlusProteger(){return 0;}; 
        int getPlusImmu(){return 0;};
        
        void show(){
            std::cout << "C'est un objet < "<< nom<<" >, cette activité réduit le point de protection : - "<<_moinsProtect<<std::endl;
        }
};