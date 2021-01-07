/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|        Objet: Gel in C++       |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: gel.hpp
	Functions' prototypes for the carte "Gel"

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
#include "gel.hpp"
#include "objet.hpp"

class Gel: public Objet{
	public:
		std::size_t ptProtect=2;
	protected:
		Gel():Objet("Gel"){};
		std::string estUtilise(){
			porte = "1";
			return porte;
		}
		std::string getName(){return nom;};
        
		
};