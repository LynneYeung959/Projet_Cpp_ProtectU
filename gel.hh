/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|         Gel API in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: gel.hh
	Functions' prototypes for the carte "gel"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "objet.hh"

class Gel:public Objet{
    public:
        Gel(){
            nom = "Gel";
            _plusProtect = 10;
        };
        ~Gel(){};
};