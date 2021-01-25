/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|          Fumer in C++          |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: fumer.hh
	Functions' prototypes for the "fumer"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include "moinsProtect.hh"

class Fumer: public MoinsProtect{
    public:
        Fumer(){
            nom = "Fumer";
            _moinsProtect = 20;
        };
        ~Fumer(){};
};