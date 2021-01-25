/*

* ------------------------------ *
|                                |
|  -= Coding Screenplay Game =-  |
|                                |
|         Rank API in C++        |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui

File: rank.hh
	Functions' prototypes for the "Rank"

2020-2021 Projet C++
*/

#include <algorithm>
#include <vector>
#include "personnage.hh"
using namespace std;

typedef pair<string, float> POINT;
/*--------------------------------------------------
    Définir l'opération ComparePoint(): comparer deux points
    si le point d'avant est plus grand que le point d'après
    return true

--------------------------------------------------*/
struct ComparePoint{
	bool operator()(const POINT& avant, const POINT& arrier)
	{
		return avant.second > arrier.second;
	}
};

class Rank{
	private:
		vector<Personnage> _perso;
	public:
		Rank(vector<Personnage> des_perso):_perso(des_perso){};
		~Rank(){};
		/*--------------------------------------------------
		    classer les personnages par leurs nombre de points

		--------------------------------------------------*/
		vector<POINT> sort_rank()
		{
			map<string, float> rank_point;
			for(auto &it: _perso)
			{
				rank_point.insert(pair<string,float>(it.getName(),it.getPoint())); // insérer les personnages avec leurs points
			}
			vector<POINT> vector_rank( rank_point.begin(), rank_point.end());
			sort(vector_rank.begin(), vector_rank.end(),ComparePoint());	// classer les personnage avec ComarePoint()

			return vector_rank;
		};
		
		/*--------------------------------------------------
		    afficher le classement

		--------------------------------------------------*/
		void show_rank()
		{
			vector<POINT> vPoint = sort_rank();
			cout<<"\tNom du Personnage\t\tPoint"<<endl;
			for(auto it:vPoint)
			{
				cout <<"\t\t"<< it.first<<"\t\t\t"<< it.second<<endl;
			}
		};
};