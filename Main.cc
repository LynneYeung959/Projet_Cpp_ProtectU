#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <map>

#include "personnage.hh"
#include "manage.hh"
using namespace std;

int main()
{	

	Manage mana;		//Créer un manage
	vector<ROLE> r = mana.listRole();		// récupérer la liste role dans le fichier role.txt
	Personnage *perso;	// Créer un personnage
	Choix *ob;			// Créer un choix
	static vector<Personnage> vect_perso;	//	Créer un vector de personnage pour le classement
	static Rank *_rank;	// Créer un classement
	string reponse;		//pour récupérer le personnage choisi de joueur
	again:				// à la fin d'un tour, si joueur veut continue, recommence par ici
	mana.start(r);		// afficher la notic et la liste de role
	while(1)
	{
	    cin >> reponse;
	    if(!cin)	//eviter l'erreur si la réponse n'est pas du type string
	    {
	    	cin.clear();
	    	cin.sync();
	    	cout << "\t----SYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    	continue;
	    }
	    if (mana.parametreRole(reponse,r)==0)	// si l'entrée est du type string mais ce n'est pas un role dans le fichier
	    {	cout << "\t----SYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    	continue;	
	    }
	    perso = new Personnage(reponse,mana.parametreRole(reponse,r));	//perso est le personnage chois dans le fichier par joueur
	    cout << "\n\t\tSYSTEME: Rôle est bien créé !\n" <<endl;
	    break;
	}
	cout << "\t\tVous allez répondre les questions suivantes. Répondre les questions avec 1 ou 2 ou 3 séparer avec l'espace\n"<<endl;
	string numQuestion;
	int cpt=1;		//le compteur de question, commence par le numéro 1
	map<int,string> script;
	int flag;		// pour récupérer le numéro de la réponse choisi 
	while(1)
	{	
			numQuestion="Q"+to_string(cpt);
			script = perso->lireChoix(numQuestion); 	//prendre la liste de choix
			if(script.empty())		// si ce numéro de question n'exist pas dans le fichier
				break;
			perso->showChoix(script); //afficher les questions et les réponses correspontantes
			cout << "\t----SYSTEME: Entrer votre choix"<<endl;
			while(1)
			{
				cin >> flag;
				redemarre:
				if(!cin)	//eviter l'erreur si la réponse n'est pas du type int
			    {
			    	cin.clear();
			    	cin.sync(); // effacer le flux d'entrée
			    	cin.ignore();
			    	cout << "\t----SYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
			    	cin >> flag;
			    	goto redemarre; //recommence le test de l'entrée
			    }
			    if(flag!=1 && flag!=2 && flag!=3 && flag!=4)	// il y a 4 réponses en totale
			    {
			    	cout << "\t----SYSTEME: Saisir le chiffre entre 1 et 4 \nJoueur :"<<endl;
			    	continue;
			    }	
			    else
			    	break;
			}
			ob = mana.CreatObjet(flag,script);	//selon la réponse choisi, on crée un Choix
			perso->doSth(ob);		// les paramètres de personnage changent selon le "Choix" créé
            delete ob;				// Détruit le "Choix", pour n'avoir pas trop de Choix dans la mémoire
		    numQuestion.clear();
			cpt++;		
	}
	cout<<"\t----SYSTEME: Vous voulez continue le jeu? "<<endl;		//Script est fini, demande si continuer ou arreter
	cout<<"\t1. YES\n\t2. NO\nJoueur :"<<endl;
	int flag_again;
	while(1)
	{
		saisie:
	    cin >> flag_again;
	    if(!cin)	//eviter l'erreur si la réponse n'est pas du type int
	    {
	    	cin.clear();
	    	cin.sync();
	    	cin.ignore();
	    	cout << "\t----SYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    	cin >>flag_again;
	    	goto saisie;
	    }
	    if(flag_again!=1 && flag_again!=2)
		{
			cout << "\t----SYSTEME: Saisir le chiffre entre 1 et 2 \nJoueur :"<<endl;
			continue;
		}
		else
			break;
	}
	if (flag_again == 2) // si joueur veut finir le jeu, le classement sera sortir
	{
		vect_perso.push_back(*perso);	// mettre à jour le vector de personnages
		_rank = new Rank(vect_perso);	// creer un classement
		_rank->sort_rank();				// classer les personnages dans l'ordre decroissant
		cout << "\n\t\t--------THE END--------\n\n";
		cout << "\n\t--------Classement de joueurs--------\n\n";
		_rank->show_rank();				// afficher le classement
		exit(0);
	}
	delete perso;
	vect_perso.push_back(*perso);		// ajouter le personnage dans le vector de personnages
	goto again;
};






