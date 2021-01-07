/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|       objet API in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: objet.hh
	Functions' prototypes for the carte "objet"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>

class Objet{
    public:
        std::string nom;
        std::string porte;
    protected:
        Objet(std::string name):nom(name),porte("0"){};
        //virtual ~Objet()=default;
        virtual std::string estUtilise() = 0;
        virtual std::string getName() = 0;
};