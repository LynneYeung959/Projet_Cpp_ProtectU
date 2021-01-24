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
#include <map>
#include <list>
#include "objet.hh"

typedef std::pair<std::string, std::string> QUESTION;
typedef std::pair<int, std::string> CHOIX;

/*
namespace Carte{
typedef enum Carte{Personnage, Objet, Activite} Carte;
};
*/
//template<typename T>
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
        std::vector<Objet>* getObjet(){return tabObjet;};
        void toString();

        // Fonction à changer les propriétés de personnage
        void setPtImmunite(int n){ptImmunite = n;};
        void contamine(){etat = '+';};
        void useObjet(Objet *ob);
        //void doSth(Activity *act);

        //Fonction à récupérer le script de Personnage
        //std::map<QUESTION,std::list<CHOIX>> lireScript(std::string perso);
        std::map<QUESTION,std::list<CHOIX>> lireScript(std::string nQuestion);
        void showScript(std::map<QUESTION,std::list<CHOIX>> s);
        
    private:
        std::string name;   //nom de Personnage
        char etat;          //etat de personnage, soit positive soit negative
        int ptImmunite;     //point de l'immunité
        int ptProtect;    //point de protection
        std::vector<Objet> *tabObjet;
        std::string fileName;
};


Personnage::Personnage(std::string nom, int ptImmu){
    name = nom;
    etat = '-';
    ptImmunite = ptImmu;
    ptProtect = 0;
    fileName = nom+".txt";

    //tabObjet.push_back( new Objet());
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

/*--------------------------------------------------
    Afficher les fonctions de la classe personnage

--------------------------------------------------*/
void Personnage::toString(){
    std::cout<< "Role est : " << name << std::endl;
    std::cout<< "Son état : " << etat << std::endl;
    std::cout<< "Point de l'immunité : " << ptImmunite << std::endl;
    std::cout<< "Point de protection : " << ptProtect << std::endl;
    // à améliorer pour montrer le tableau de objet et leurs pt de protection
    std::cout<< "Objet : " << tabObjet<< std::endl;
}

void Personnage::useObjet(Objet *ob)
{
    ptProtect += ob->getPtProteger();
    //tabObjet->push_back(ob);
};

/*--------------------------------------------------
    Récupérer le script de personnage

--------------------------------------------------*/
/*
std::map<QUESTION,std::list<CHOIX>> Personnage::lireScript(std::string perso)
{
    std::ifstream file(perso+".txt");
    QUESTION q;
    CHOIX c;
    std::list<CHOIX> lChoix;
    std::map<QUESTION, std::list<CHOIX>> script;
    std::string line;
    while(std::getline(file,line))
    {
        
        if(line[0] == 'Q') //ligne de la question
        {
            std::string numQ, question;
            for(int i = 0; i< line.size(); i++)
            {
                if(i<=2) numQ+=line[i];
                else if(i>2) question+=line[i]; 
            }
            q = make_pair(numQ,question);
            numQ.clear();
            question.clear();    
        }
        else if(line.empty()) // une ligne vide
        {
            script.insert(std::pair<QUESTION,std::list<CHOIX>>(q,lChoix));
            lChoix.clear();
        }    
        else //les lignes des reponse à choisir
        {   
            std::string chose;   
            for(int i=1; i<line.size();i++)
            {
                chose += line[i];
            }
            c = make_pair(line[0] -'0',chose);
            chose.clear();
            lChoix.push_back(c);
        }
    }
    script.insert(std::pair<QUESTION,std::list<CHOIX>>(q,lChoix));
    return script;
};*/

/*--------------------------------------------------
    Récupérer la question indiquée dans le script de personnage

--------------------------------------------------*/
std::map<QUESTION,std::list<CHOIX>> Personnage::lireScript(std::string nQuestion)
{
    std::ifstream file(fileName);
    QUESTION q;
    CHOIX c;
    std::list<CHOIX> lChoix;
    std::map<QUESTION, std::list<CHOIX>> script;
    std::string line;
    int go = 0;
    while(std::getline(file,line))
    {
        if((line[0] == 'Q') && go == 0)//ligne de la question
        {
            std::string numQ, question;
            for(int i = 0; i<2; i++) // récupérer le numéro de la question
                numQ += line[i];

            if(numQ == nQuestion)
            {
                go = 1;
                for(int i = 3; i< line.size();i++)
                {
                    if(i>2) question+=line[i];
                }
                q = make_pair(numQ,question);
                numQ.clear();
                question.clear();
            } 
        }  
        else if (go == 1 && line.empty() ) // les réponses sont tous récupérés
        {   
                script.insert(std::pair<QUESTION,std::list<CHOIX>>(q,lChoix));
                return script; 
        }
        else if ( go == 1)//récupérer la liste des reponse de la quesiton choisi
        { 
            std::string chose;   
            for(int i=1; i<line.size();i++)
            {
                chose += line[i];
            }
            c = make_pair(line[0] -'0',chose);
            chose.clear();
            lChoix.push_back(c);
        }
    }
    if(go == 1)
        script.insert(std::pair<QUESTION,std::list<CHOIX>>(q,lChoix));
    return script;
};

/*--------------------------------------------------
    Afficher le script de personnage

--------------------------------------------------*/
void Personnage::showScript(std::map<QUESTION,std::list<CHOIX>> s)
{
    for(auto it = s.begin(); it!=s.end(); ++it){
        QUESTION q = it->first;
        std::list<CHOIX> lChoix = it->second;
        std::cout<< "\n"<<q.first<<" "<< q.second<<std::endl;
        for(auto i = lChoix.begin(); i!=lChoix.end();++i)
        {
            std::cout << i->first << " "<< i->second<<std::endl;
        }
    }
}

















