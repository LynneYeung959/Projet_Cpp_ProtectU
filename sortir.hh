/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|         Sortir in C++          |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: sortir.hh
	Functions' prototypes for the "Sortir"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "moinsProtect.hh"

class Sortir: public MoinsProtect{
    public:
        Sortir(){
            nom = "Sortir";
            _moinsProtect = 10;
        };
        ~Objet(){};
};