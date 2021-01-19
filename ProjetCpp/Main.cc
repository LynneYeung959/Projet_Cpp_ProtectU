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
typedef question<int, string> QUESTION;

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

void start(vector<ROLE> r){
	cout << "\n\t--------WELCOME TO XXXXX--------\n\n";
    cout << "Saisir le caractére préféré dans la liste suivante : \n\n";
    cout << "--------------------------------------\n";
    cout <<"\tMetier    Point de l'immunité"  << "\n"<< endl;
    for(auto it= r.begin(); it!=r.end(); ++it)
    {
    	cout<<"   "<< it->first << "\t\t"<< it->second<<"\n"<< endl;
    }
    cout<< "---------------------------------------\nJoueur :"<<endl;

};

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

Personnage roleCreer(string choix, int parametreRole)
{
	return Personnage(choix,parametreRole);
};

vector<QUESTION> qDocteur()
{
	ifstream file("docteur.txt");
	vector<Question > quesDoctor;

}

int main()
{
	vector<ROLE> r = listRole();
	start(r);
	int go = 0;
	while(1)
	{
	    string reponse;
	    cin >> reponse;
	    if (parametreRole(reponse,r)==0)
	    	cout << "\tSYSTEME: Je ne connais pas votre choix. Veuillez entrer à nouveau \nJoueur :"<<endl;
	    else {
	    	Personnage perso=roleCreer(reponse,parametreRole(reponse,r));
	    	cout << "\tSYSTEME: Rôle est bien créé !\n" <<endl;
	    	go = 1;
	    }
	    if (go ==1){
	    	cout << "______"<<endl;
	    }
	}
};






