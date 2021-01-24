#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <map>

#include "personnage.hh"
//#include "masque.hh"
//#include "gel.hh"
//#include "gant.hh"
//#include "sport.hh"
//#include "soiree.hh"
//#include "carte.hh"

using namespace std;
/*
namespace Caractere{
typedef enum Caractere{Doctor, Infirmiere, Etudiante, Employe, Enfant} Caractere;
};
ostream& operator<<(ostream& out, Caractere::Caractere c);
*/

typedef pair<string,int> ROLE;

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
			else if ((line[i] = ' '))
				go = 1;	
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
	cout << " Selon votre choix, le point de l'immunité et le point de protégé de votre personnage sera augmenter ou diminuer.";
	cout << " Lorsque le point de protégé est inférieur à XX, le point de l'immunité va diminuer.";
	cout << " Lorsque le point de l'immunité de votre de personnage est inférieur à YY, votre personnage sera être contaminé.";
	cout << " Le jeu sera fini.\n\n";
	cout << "\n\t--------GAME START--------\n\n";
    cout << " Saisir le caractére préféré dans la liste suivante : \n\n";
    cout << "--------------------------------------\n";
    cout <<"\tMetier    Point de l'immunité"  << "\n"<< endl;
    for(auto it= r.begin(); it!=r.end(); ++it)
    {
    	cout<<"   "<< it->first << "\t\t"<< it->second<<"\n"<< endl;
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
	for(auto it=lRole.begin(); it!=lRole.end(); ++it)
	{
		if(it->first == choix)
		{
			return it->second;
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

int main()
{	
	// Creer un HITOIRE pour afficher les l'ordre de joueur
	// map? or vector?
	//string nameJoueur;
	vector<ROLE> r = listRole();
	start(r);
	string reponse; //le choix du personnage de joueur
	Personnage *perso;
	//int go = 0; //indiquer si le rôle est bien créé
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
	    if (parametreRole(reponse,r)==0)
	    {	cout << "\t----SYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    	continue;	
	    }
	    perso = new Personnage(reponse,parametreRole(reponse,r));
	    //perso=roleCreer(reponse,parametreRole(reponse,r));
	    cout << "\n\t\tSYSTEME: Rôle est bien créé !\n" <<endl;
	    break;
	}
	cout << "\t\tVous allez répondre les questions suivantes. Répondre les questions avec 1 ou 2 ou 3 séparer avec l'espace"<<endl;
	string numQuestion;
	int cpt=1;
	map<QUESTION,list<CHOIX>> script;
	int flag;
	while(1)
	{	
			numQuestion="Q"+to_string(cpt);
			script = perso->lireScript(numQuestion);
			if(script.empty())	// s'il n'y a pas de question à répondre, le jeu est fini
				break;
			perso->showScript(script); // afficher la question
			cout << "\t----SYSTEME: Entrer votre choix"<<endl;
			while(1)
			{
				cin >> flag;
				if(!cin)	//eviter l'erreur si la réponse n'est pas du type int
			    {
			    	cin.clear();
			    	cin.sync(); // effacer le flux d'entrée
			    	cout << "\t----SYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
			    	continue;
			    }
			    if(flag!=1 && flag!=2 && flag!=3 && flag!=4)
			    {
			    	cout << "\t----SYSTEME: Saisir le chiffre entre 1 et 4 \nJoueur :"<<endl;
			    	continue;
			    }	
			    else
			    	break;
			}

			switch(flag)
			{
				case 1:break;
				default: break;
			}
		    	numQuestion.clear();
				cpt++;		
	}

	//perso->showScript(script);
	//perso->toString();
};






