/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|       objet API in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

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
        Objet();
        Objet(std::string name):nom(name),porte("0"){};
        ~Objet()=default;
        bool estPorte();
        std::string estUtilise();
        std::string getName();
};