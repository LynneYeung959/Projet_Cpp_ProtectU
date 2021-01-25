/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|        Laver API in C++        |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: laver.hh
	Functions' prototypes for the "laver"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "plusProtect.hh"

class Laver: public PlusProtect{
    public:
        Laver(){
        	nom = "Laver";
        	_plusProtect = 5;
        };
        ~Laver(){};
};