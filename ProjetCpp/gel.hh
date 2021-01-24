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
#include "objet.hh"

class Gel:public Objet{
    public:
        Gel(std::string name = "Gel",std::string niveau = "1", int ptP = 10):Objet(name,niveau,ptP){};
        virtual ~Objet()=default;

        /*
            Fonction à récupérer les informations de l'objet
        
        std::string getName(){return nom;};
        std::string getRank(){return rank;};
        int getPtProteger(){return ptProteger;};*/
};