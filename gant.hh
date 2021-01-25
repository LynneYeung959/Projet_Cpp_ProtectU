/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|         Gant API in C++        |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: gant.hh
	Functions' prototypes for the "gant"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "objet.hh"

class Gant:public Objet{
    public:
        Gant(){
            nom = "Gant";
            _plusProtect = 15;
        };
        ~Gant(){};
};