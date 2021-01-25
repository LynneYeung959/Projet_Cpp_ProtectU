/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|       Manage API in C++        |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: manage.hh
	Functions' prototypes for the "Manage"

2020-2021 Projet C++
*/

#pragma once
#include <iostream>
#include <string>
#include <map>
#include "personnage.hh"
#include "masque.hh"
#include "gel.hh"
#include "gant.hh"
#include "laver.hh"
#include "transport.hh"
#include "bar.hh"
#include "sport.hh"
#include "fete.hh"
#include "fumer.hh"
#include "sortir.hh"
#include "rank.hh"

using namespace std;
typedef pair<string,int> ROLE;

class Manage{
    public:

        /*--------------------------------------------------

            Fonctin à récupérer les rôles exists dans le ficher role.txt

        --------------------------------------------------*/
        vector<ROLE> listRole(){
            vector<ROLE> role;
            ifstream file("role.txt");
            string line, perso, ptImmu;
            while(getline(file,line))
            {   
                int go = 0;
                for(int i = 0; i<line.size();i++)
                {
                    if( (line[i] != ' ') && go == 0)
                        perso += line[i];
                    else if( (line[i] != ' ') && go ==1)
                        ptImmu += line[i];
                    else if ((line[i] = ' ')) // apres une espace, c'est le point de l'immunité
                        go = 1;     // on active la récupation du point de l'immunité
                }
                role.push_back(pair<string,int>(perso,atoi(ptImmu.c_str())));
                perso.clear();
                ptImmu.clear();
            }
            return role;
        };

        /*--------------------------------------------------
            Fonction du début de jeu, elle affiche la liste des personnages à choisir
            void start(vector<ROLE> r)
                - vector<ROLE> r : la liste des personnages à choisir
                                    cette liste a été enovyé par la fonction vector<ROLE> listRole()
        --------------------------------------------------*/
        void start(vector<ROLE> r){
            cout << "\n\tRègle du jeu:"<<endl;
            cout << "\n\tVous choisissez une personnage, puis répondez une série de questions.";
            cout << " Selon votre choix, le point de l'immunité et le point de protégé de votre personnage sera augmenté ou réduit.";
            cout << " Lorsque le point de protégé est inférieur à 0, le point de l'immunité va diminuer.";
            cout << " Si le point de l'immunité est inférieur à un demi du point initial, votre personnage sera être infecté.";
            cout << "\n\t--------GAME START--------\n\n";
            cout << " Saisir le caractére préféré dans la liste suivante : \n\n";
            cout << "--------------------------------------\n";
            cout <<"\tMetier    Point de l'immunité"  << "\n"<< endl;
            for(auto it:r)
            {
                cout<<"   "<< it.first << "\t\t"<< it.second<<"\n"<< endl;
            }
            cout<< "---------------------------------------\nJoueur :"<<endl;

        };


        /*--------------------------------------------------
            Fonction renvoye le point de l'immunité de personnage choisi par joueur

            int parametreRole(string choix, vector<ROLE> lRole)
                - string choix: le nom de la personnage choisi du joueur,
                - vecotr<ROLE> lRole: la liste de personnages à choisir
                    ce paramètre a été récupéré dans la fonction : vector<ROLE> listRole()
        ----------------------------------------------------*/
        int parametreRole(string choix, vector<ROLE> lRole)
        {
            for(auto it:lRole)//(auto it=lRole.begin(); it!=lRole.end(); ++it)
            {
                if(it.first == choix)
                {
                    return it.second;
                }
            }
            return 0;
        }

        /*--------------------------------------------------
            Fonction à créer la personnage choisi par joueur

            Personnage roleCreer(string choix, int pointImmu)
                - strng choix: le nom de la personnage choisi par joueur
                - int pointImmu: le point de l'immunité de la personnage choisi
        --------------------------------------------------*/
        Personnage* roleCreer(string choix, int pointImmu)
        {
            return new Personnage(choix,pointImmu);
        };

        /*--------------------------------------------------
            Fonction à créer l'objet selon chaque mot de la réponse choisi

            Choix *creation(string mot)
                - strng choix: le mot de la réponse choisi
            return un "Choix" selon le "mot"
            si le "mot" n'a pas son propre classe, return un "Objet"
        --------------------------------------------------*/
        Choix *creation(string mot)
        {
            if((mot == "gel")|| mot == "Gel")
                return new Gel();
            else if(mot == "Gant" || mot == "gant")
                return new Gant();
            else if(mot == "masque" || mot == "Masque")
                return new Masque();
            else if(mot == "Laver" || mot == "laver")
                return new Laver();
            else if(mot == "Bus" || mot =="bus" || mot == "Métro" || mot == "métro")
                return new Transport();
            else if(mot == "bar" || mot == "Bar")
                return new Bar();
            else if(mot == "sport" || mot == "Sport" || mot == "Nager"|| mot =="")
                return new Sport();
            else if(mot == "fête" || mot == "soirée")
                return new Fete();
            else if(mot == "Fumer" || mot == "fumer" || mot == "Promener" || mot == "courses" || mot == "restaurant"|| mot == "jouer" )
                return new Sortir();
            else
                return new Objet();
        }

        /*--------------------------------------------------
            Fonction à créer l'objet par la réponse choisi

            Choix *CreatObjet(int flag, map<int,string> lchoix)
                - int flag: le numéro de réponse
                - map<int, string> lchoix: la liste des réponses à choisir
            cette fonction permet d'élimination des "Choix" inutiles sortie de la fonction d'avant
        --------------------------------------------------*/
        Choix *CreatObjet(int flag, map<int,string> lchoix)
        {
            map<int,std::string>::iterator it=lchoix.find(flag); //récupérer la réponse choisi dans la liste
            string ss = it->second, mot;
            Choix *ob;
            for(int i = 1; i<ss.size();i++)
            {
                if (ss[i] != ' ')   //récupérer chaque mot de la réponse
                    mot+=ss[i];
                else //on regarde le mot par mot
                {
                    ob = creation(mot); // créer le "Choix" par "mot"
                    //si le "Choix" est créé par une classe vituelle
                    // on le desctruit
                    if((ob->getName() == " ") || (ob->getName() == "Activity") || (ob->getName()=="Objet") ) 
                    {
                        delete ob;
                        
                    }else if ((ob->getName() != " ") && (ob->getName() != "Activity") && (ob->getName()!="Objet")){
                        // si "Choix" est une action ou un objet utile
                        return ob;
                    }
                    mot.clear();
                }
            }
            // envoye le "Choix" du dernier mot
            return creation(mot);
        }
};