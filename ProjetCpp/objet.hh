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
    protected:
        std::string nom;
        std::string rank;   //niveau de protection
        int ptProteger;     //pt de protection
    public:
        Objet(std::string namem="",std::string niveau="", int ptP = 0){
            nom = name;
            rank = niveau;
            ptProteger = ptP;
        };
        ~Objet()=default;

        /*
            Fonction à récupérer les informations de l'objet
        */
        std::string getName(){return nom;};
        std::string getRank(){return rank;};
        int getPtProteger(){return ptProteger;};
};