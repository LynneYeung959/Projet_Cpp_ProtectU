/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|          Choix in C++          |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: choix.hh
	Functions' prototypes for the base class "choix"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>

class Choix{
    public:
        Choix()
        {
            nom = " ";
        }
        virtual ~Choix()
        {
            //std::cout << "appel du destructeur d'article " << std::endl;
        };
        std::string getName(){return nom;};
        /*--------------------------------------------------
            
            les fonctions virtuelles

        --------------------------------------------------*/
        virtual int getPlusProteger() =0;
        virtual int getPlusImmu()=0;
        virtual int getMoinsProtect()=0;
        /*--------------------------------------------------
            
        la fonction à surchargé pour afficher le nom de la classe

        --------------------------------------------------*/
        void show()
        {
            std::cout << "____Objet a bien créé_________CHOIX:"<<nom<<std::endl;
        };
    protected:
        std::string nom;
};