/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|           Bar in C++           |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: bar.hh
	Functions' prototypes for the activity: go to the bar

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "moinsProtect.hh"

class Bar: public MoinsProtect{
    public:
        Bar(){
            nom = "Bar";
            _moinsProtect = 50;
        };
};