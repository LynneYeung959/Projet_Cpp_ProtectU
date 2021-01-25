/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|       Activity in C++          |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: activity.hh
	Functions' prototypes for the virtual class "Activity"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "choix.hh"

class Activity:public Choix{
    public:
    	Activity(){
    		nom = "Activity";
    	}
        virtual ~Activity()
        {
        	//std::cout <<"Destruction Activity"<<std::endl;
        };
        /*--------------------------------------------------
            les fonctions virtuelles

        --------------------------------------------------*/
        virtual int getPlusProteger() =0;
        virtual int getPlusImmu()=0;
        virtual int getMoinsProtect()=0;
        virtual void show() = 0;
};