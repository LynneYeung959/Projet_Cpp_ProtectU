/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|          Fete in C++           |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: fete.hh
	Functions' prototypes for the activity: fete

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "moinsProtect.hh"

class Fete: public MoinsProtect{
    public:
        Fete(){
            nom = "Fête";
            _moinsProtect = 45;
        };
        ~Fete(){};
};