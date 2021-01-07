/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|     Activity: Soiree in C++    |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: soiree.hpp
	Functions' prototypes for the carte "Soirée"

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
//#include "soiree.hpp"
#include "actInfection.hpp"


class Soiree: public ActInfection{
	public:
		Soiree():ActInfection(30){
            nom = "Soiree";
        };
		std::string estFait(){
			fait = "1";
			return fait;
		}
		std::string getName(){return nom;};
        
};