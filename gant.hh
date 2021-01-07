/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|       Objet: Gant in C++       |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: gant.hh
	Functions' prototypes for the carte "Gant"

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
#include "objet.hh"

class Gant: public Objet{
	public:
		std::size_t ptProtect=20;
	protected:
		Gant():Objet("Gant"){};
		std::string estUtilise(){
			porte = "1";
			return porte;
		}
		std::string getName(){return nom;};
        
		
};