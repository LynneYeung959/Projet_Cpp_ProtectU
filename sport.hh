/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|         Sport in C++           |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: sport.hh
	Functions' prototypes for sport

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
#include "actRenforce.hh"

class Sport: public ActRenforce{
	public:
		Sport():ActRenforce(15){
            nom = "Sport";
        };
		std::string estFait(){
			fait = "1";
			return fait;
		}
		std::string getName(){return nom;};
        
};