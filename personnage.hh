/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|      Personnage API in C++     |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: Personnage.hh
	Functions' prototypes for "Personnage"

2020-2021 Projet C++
*/
#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "choix.hh"

class Personnage
{
    public:
        // Constructeur par défaut
        Personnage();
        // Constructeur overload
        Personnage(std::string nom, int ptImmu);
        // Deconstructeur
        ~Personnage(){};

        // Opérateur overload
        Personnage operator()(std::string nom, int ptImmu);
        Personnage& operator=(const Personnage& perso);
        //Personnage& operator==(const Personnage& perso) const;

        // Fonction à récupérer les informations de personnage
        std::string getName(){return name;};
        int getPtImmu_Init() const {return ptImmunite;};
        int getProtect(){return ptProtect;};
        char getEtat(){return etat;};
        void toString();
        float getPoint();

        // Fonction à changer les propriétés de personnage
        void doSth(Choix *sth);
        
        //Fonction à récupérer le script de Personnage
        std::map<int,std::string> lireChoix(std::string nQuestion);
        void showChoix(std::map<int,std::string> c);

    private:
        std::string name;   //nom de Personnage
        char etat;          //etat de personnage, soit positive soit negative
        int ptImmunite;     //point de l'immunité
        int ptProtect;    //point de protection
        std::string fileName;   //fichier du script de personnage
};

/*--------------------------------------------------
    Constructeur

--------------------------------------------------*/
Personnage::Personnage(std::string nom, int ptImmu){
    name = nom;
    etat = '-';
    ptImmunite = ptImmu;
    ptProtect = 0;
    fileName = nom+".txt";
};

/*--------------------------------------------------
    les operateurs overload

--------------------------------------------------*/
Personnage Personnage::operator()(std::string nom,int ptImmu)
{
    name = nom;
    etat = '-';
    ptImmunite = ptImmu;
    ptProtect = 0;
    fileName = " ";
    return *this;
};

Personnage& Personnage::operator=(const Personnage& perso)
{
    this->name = perso.name;
    this->etat = perso.etat;
    this->ptImmunite = perso.ptImmunite;
    this->ptProtect = perso.ptProtect;
    return *this;
};
/*
Personnage& Personnage::operator==(const Personnage& perso) const
{
    if(name== perso.name && ptImmunite == perso.ptImmunite && etat == perso.etat && ptProtect == perso.ptProtect)
        return true;
    return false;
}*/


/*--------------------------------------------------
    Afficher les paramètres de personnage

--------------------------------------------------*/
void Personnage::toString(){
    std::cout<< "Role est : " << name << std::endl;
    std::cout<< "Son état : " << etat << std::endl;
    std::cout<< "Point de l'immunité : " << ptImmunite << std::endl;
    std::cout<< "Point de protection : " << ptProtect << std::endl;
}



/*--------------------------------------------------
    Selon la choix de joueur
    le personnage de joueur va augmenter/réduire le point de protection
    ou augmenter le point de l'immunité

--------------------------------------------------*/
void Personnage::doSth(Choix *sth)
{
    int ptImmu_initial = getPtImmu_Init();
    int plusProtect = sth->getPlusProteger();
    int plusImmu = sth->getPlusImmu();
    int moinsProtect = sth->getMoinsProtect();
    if(plusProtect != 0) // si *sth est pour protéger le personnage
       ptProtect +=plusProtect;
    if(plusImmu != 0)
    {
        ptImmunite += plusImmu; // si *sth est pour renforcer la santé du personnage
        // si le personnage était POSITIF, le ptImmunite est plus grand que 1/2 du ptImmunite initial
        // le personnage sera NEGATIF
        if( etat == '+' && ptImmunite > ptImmu_initial/2 ) 
            etat = '-';
    }
    if(moinsProtect != 0)   // si *sth est pour réduire le pt de protection du personnage
    {
        ptProtect -= moinsProtect;
        // si le personnage était NEGATIF, le pt Protection est inférieur à 0
        if(etat == '-' && ptProtect <0 )
        {
            ptImmunite -=20;    
            // si le ptImmunite est plus petit que 1/2 du ptImmunite initialle
            // personnage sera POSITIF (infecté)
            if (ptImmunite <= ptImmu_initial/2)
                etat = '+';
        }       
    }  
};
/*--------------------------------------------------
    Calculer le point final du personnage
    10 points de protection = 2 pt
    10 points de immunité = 5 pt
--------------------------------------------------*/
float Personnage::getPoint()
{
    return ptProtect/10*2+ptImmunite/10*5;
}

/*--------------------------------------------------

    Selon le numéro de question
    Récupérer les réponses correspondantes

--------------------------------------------------*/
std::map<int,std::string> Personnage::lireChoix(std::string nQuestion)
{
    std::ifstream file(fileName);
    std::map<int, std::string> lchoix;
    std::string line;
    int go = 0;
    while(std::getline(file,line))
    {
        if((line[0] == 'Q') && go == 0)//ligne de la question
        {
            std::string numQ, question;
            for(int i = 0; i<2; i++) // récupérer le numéro de la question :Q1/Q2/Q3.....
                numQ += line[i];
            if(numQ == nQuestion) // la question choisie
            {
                go = 1; //activé la récupération des réponses
                for(int i = 3; i< line.size();i++)
                    question+=line[i];  //récupérer la question
                std::cout << numQ << " "<< question <<std::endl; // afficher la question soisie
            } 
        }  
        else if ( go == 1)//récupérer la liste des reponse de la quesiton choisi
        { 
            if(line.empty())    //ligne vide, la ligne avant la question suicante
                return lchoix;
            std::string c;
            for(int i=1; i<line.size();i++)     // la ligne de la réponse
            {
                c += line[i];
            }
            lchoix.insert(std::pair<int,std::string>(line[0] -'0',c));  // insérer les réponses dans map
            c.clear(); 
        }
    }
    return lchoix; 
};

/*--------------------------------------------------

    afficher les réponses à choisir de la question par 

--------------------------------------------------*/
void Personnage::showChoix(std::map<int,std::string> c)
{
    for(auto it:c)
    {
        std::cout<< it.first << " "<< it.second << std::endl; 
    }
};
