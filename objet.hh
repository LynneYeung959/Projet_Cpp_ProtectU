/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
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
#include "choix.hh"

class Objet:public Choix{
    protected:
        int _plusProtect;
    public:
        Objet(){
            nom = "Objet";
            _plusProtect = 0;
        }
        virtual ~Objet()
        {
           // std::cout <<"Destruction Objet"<<std::endl;
        };

        /*
            Fonction à récupérer les informations de l'objet
        */
        int getPlusProteger(){return _plusProtect;};
        int getPlusImmu(){return 0;};
        int getMoinsProtect(){return 0;}; 
        void show(){
            std::cout << "C'est un objet < "<< nom<<" >, son point de protection est "<<_plusProtect<<std::endl;
        }
};