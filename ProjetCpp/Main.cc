#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <map>
//#include "Grave.hh"
//#include "leger.hh"
//#include "Docteur.hh"
#include "personnage.hh"
//#include "Employe.hh"
//#include "Enfant.hh"
//#include "Etudiant.hh"
//#include "Infirmiere.hh"
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
/*
list<Personnage> create(){
	list<Personnage> les_perso;
	Docteur d("Docteur Alex");
	les_perso.push_back(d);
	return les_perso;
};
*/
typedef pair<string,int> ROLE;
typedef pair<int, string> QUESTION;

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
/*
	Fonction du début de jeu, elle affiche la liste des personnages à choisir
	void start(vector<ROLE> r)
		- vector<ROLE> r : la liste des personnages à choisir
							cette liste a été enovyé par la fonction vector<ROLE> listRole()
*/
void start(vector<ROLE> r){
	cout << "\n\t--------GAME START--------\n\n";
    cout << "Saisir le caractére préféré dans la liste suivante : \n\n";
    cout << "--------------------------------------\n";
    cout <<"\tMetier    Point de l'immunité"  << "\n"<< endl;
    for(auto it= r.begin(); it!=r.end(); ++it)
    {
    	cout<<"   "<< it->first << "\t\t"<< it->second<<"\n"<< endl;
    }
    cout<< "---------------------------------------\nJoueur :"<<endl;

};
/*
	Fonction renvoye le point de l'immunité de personnage choisi par joueur

	int parametreRole(string choix, vector<ROLE> lRole)
		- string choix: le nom de la personnage choisi du joueur,
		- vecotr<ROLE> lRole: la liste de personnages à choisir
			ce paramètre a été récupéré dans la fonction : vector<ROLE> listRole()
*/
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
/*
	Fonction à créer la personnage choisi par joueur

	Personnage roleCreer(string choix, int pointImmu)
		- strng choix: le nom de la personnage choisi par joueur
		- int pointImmu: le point de l'immunité de la personnage choisi
*/
Personnage* roleCreer(string choix, int pointImmu)
{
	return new Personnage(choix,pointImmu);
};
/*
vector<QUESTION> qDocteur()
{
	ifstream file("docteur.txt");
	vector<QUESTION > quesDoctor;
}
*/
/*vector<QUESTION> */void qDocteur()
{
	ifstream file("docteur.txt");
	vector<QUESTION> quesDoctor;
	string line;
	while(getline(file,line))
	{
		cout<< "BRAVO" << endl;
	}

}

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
	    	cout << "\tSYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    	continue;
	    }
	    if (parametreRole(reponse,r)==0)
	    {	cout << "\tSYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    	continue;	
	    }
	    perso=roleCreer(reponse,parametreRole(reponse,r));
	    cout << "\tSYSTEME: Rôle est bien créé !\n" <<endl;
	    break;
	}

	 if(reponse == "Docteur")
	    	{
	    		qDocteur();
	    	/*else if(reponse == "Vieillard")*/
	    }
	perso->toString();
	
};






