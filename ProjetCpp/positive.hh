/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|        Positive in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: Positive.hh
	Functions' prototypes for positive

2020-2021 Projet C++
*/
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "personnage.hh"

int static cptNega = 0;

class Positive:public virtual Personnage
{
    public:
        //Constructeur par default;
        Positive();
        Positive(std::string nom, int ptImmu);
        //Constructeur par copie
        Positive(const Positive& p);
        // Deconstructeur
        virtual ~Positive()=default;
        virtual void toString()=0;
    protected:
        int symptome;
};

Positive::Positive():Personnage("Perso-Positive"),symptome(1){
    etat = 'P';
    cptNega++;
};

Positive::Positive(std::string nom, int ptImmu):Personnage(nom, ptImmu){
    etat = 'P';
    cptNega++;
};

Positive::Positive(const Positive& p){
    std::string nom = p.name;
    nom +=cptNega;
    etat = p.etat;
    ptImmunite = p.ptImmunite;
    ptProtect = p.ptProtect;
    tabObjet = p.tabObjet;
}