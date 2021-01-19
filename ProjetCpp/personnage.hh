/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|      Personnage in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: Personnage.hh
	Functions' prototypes for personnel

2020-2021 Projet C++
*/
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "objet.hh"

/*
namespace Carte{
typedef enum Carte{Personnage, Objet, Activite} Carte;
};
*/
class Personnage
{
    public:
        // Constructeur par défaut
        Personnage();
        // Constructeur overload
        Personnage(std::string nom);
        Personnage(std::string nom, int ptImmu);
        // Deconstructeur
        //~Personnage(); 

        // Opérateur overload
        Personnage operator()(std::string nom, int ptImmu);
        Personnage& operator=(const Personnage& perso);
        //Personnage& operator==(const Personnage& perso);

        // Fonction
        int getPtImmunite();
        int setPtImmunite(int n);
        char contamine();
        void toString();
        
    private:
        std::string name;
        char etat;
        int ptImmunite;
        int ptProtect=0;
        std::vector<std::string> tabObjet;
};

Personnage::Personnage(std::string nom):name(nom){};

//Personnage::Personnage(char e):etat(e){};

Personnage::Personnage(std::string nom, int ptImmu):name(nom),etat('-'),ptImmunite(ptImmu){};

/*
Personnage::Personnage(std::string name,char etat,int immunite)
{
    name = name;
    etat = etat;
    immunite = immunite;
}
*/

/*
    les operateurs overload

*/
Personnage Personnage::operator()(std::string nom,int ptImmu)
{
    name = nom;
    ptImmunite = ptImmu;
    etat = '-';
    return *this;
};

Personnage& Personnage::operator=(const Personnage& perso)
{
    this->name = perso.name;
    this->etat = perso.etat;
    this->ptImmunite = perso.ptImmunite;
    this->ptProtect = perso.ptProtect;
    this->tabObjet = perso.tabObjet;
    return *this;
};



/*
    Les fonctions de la classe personnage

*/
int Personnage::getPtImmunite(){
    return ptImmunite;
};

int Personnage::setPtImmunite(int n){
    ptImmunite = n;
    return ptImmunite;
};

char Personnage::contamine(){
    etat = 'P';
    return etat;
};

void Personnage::toString(){
    std::cout<< "Role est :" << this->name << " Point de l'immunité est : " << this->ptImmunite << std::endl;
}