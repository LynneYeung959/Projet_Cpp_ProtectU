/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|   Alimentation Protéine in C++ |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: alimProteine.hh
	Functions' prototypes for alimProteine

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
//#include "soiree.hpp"
#include "actRenforce.hh"

class AlimProteine: public ActRenforce{
	public:
		AlimProteine():ActRenforce(15){
            nom = "Prend Alim Proteine";
        };
		std::string estFait(){
			fait = "1";
			return fait;
		}
		std::string getName(){return nom;};
        
};