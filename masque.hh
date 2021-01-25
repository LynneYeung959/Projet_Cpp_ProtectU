/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|       Masque API in C++        |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: masque.hh
	Functions' prototypes for the carte "masque"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "objet.hh"

class Masque:public Objet{
    public:
        Masque(){
            nom = "Masque";
            _plusProtect = 20;
        };
        ~Masque(){};
};