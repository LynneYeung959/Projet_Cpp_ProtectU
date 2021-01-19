/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|       Negative in C++          |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: negative.hh
	Functions' prototypes for personel negatif

2020-2021 Projet C++
*/

#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include "personnage.hh"

class Negative:public virtual Personnage
{
    public:
        // Constructeur par défault
        Negative();
        // Constructeur overload
        Negative(std::string nom, int ptImmu);
        virtual ~Negative()=default; 
        virtual void toString()=0;
};

Negative::Negative():Personnage("Perso_Negative"){
    etat = 'N';
};

Negative::Negative(std::string nom, int ptImmu):Personnage(nom, ptImmu){
    etat = 'N';
};