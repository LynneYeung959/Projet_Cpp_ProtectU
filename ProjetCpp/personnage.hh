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
        Personnage(std::string nom, int ptImmu);
        // Deconstructeur
        virtual ~Personnage()
        {
            if(!tabObjet) delete tabObjet;
        }; 

        // Opérateur overload
        Personnage operator()(std::string nom, int ptImmu);
        Personnage& operator=(const Personnage& perso);
        //Personnage& operator==(const Personnage& perso);

        // Fonction à récupérer les informations de personnage
        std::string getName(){return name;};
        char getEtat(){return etat;};
        int getPtImmunite(){return ptImmunite;};
        int getProtect(){return ptProtect;};
        std::vector<std::string>* getObjet(){return tabObjet;};
        void toString();

        // Fonction à changer les propriétés de personnage
        void setPtImmunite(int n){ptImmunite = n;};
        void contamine(){etat = '+';};
        void getObjet(Objet *ob);
        //void doSth(Activity *act);
        
    private:
        std::string name;   //nom de Personnage
        char etat;          //etat de personnage, soit positive soit negative
        int ptImmunite;     //point de l'immunité
        int ptProtect;    //point de protection
        std::vector<std::string> *tabObjet;
};


Personnage::Personnage(std::string nom, int ptImmu){
    name = nom;
    etat = '-';
    ptImmunite = ptImmu;
    ptProtect = 0;
    tabObjet = new Objet();
};

/*
    les operateurs overload

*/
Personnage Personnage::operator()(std::string nom,int ptImmu)
{
    name = nom;
    etat = '-';
    ptImmunite = ptImmu;
    ptProtect = 0;
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
    Afficher les fonctions de la classe personnage

*/
void Personnage::toString(){
    std::cout<< "Role est : " << name << std::endl;
    std::cout<< "Son état : " << etat << std::endl;
    std::cout<< "Point de l'immunité : " << ptImmunite << std::endl;
    std::cout<< "Point de protection : " << ptProtect << std::endl;
    // à améliorer pour montrer le tableau de objet et leurs pt de protection
    std::cout<< "Objet : " << tabObjet<< std::endl;
}

void Personnage::getObjet(Objet *ob)
{
    ptProtect += ob->getPtProteger();
    tabObjet.push_back(ob);
};