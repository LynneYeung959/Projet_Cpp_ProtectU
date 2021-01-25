/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|         Sport in C++           |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: sport.hh
	Functions' prototypes for sport
2020-2021 Projet C++
*/


#pragma once
#include <iostream>
#include "plusImmu.hh"

class Sport: public PlusImmu{
	public:
		Sport(){
            nom = "Sport";
            _plusImmu = 15;
        };
        ~Sport(){};
};