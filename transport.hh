/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|       Transport in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: transport.hh
	Functions' prototypes for the "Transport"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "moinsProtect.hh"

class Transport: public MoinsProtect{
    public:
        Transport(){
            nom = "Transport";
            _moinsProtect = 30;
        };
        ~Transport(){};
};