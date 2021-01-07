/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|     Objet: Masque in C++       |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: masque.hpp
	Functions' prototypes for the carte "Masque"

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
#include "masque.hpp"
#include "objet.hpp"

class Masque: public Objet{
	public:
		std::size_t ptProtect=10;
	protected:
		Masque():Objet("Masque"){};
		std::string estUtilise(){
			porte = "1";
			return porte;
		}
		std::string getName(){return nom;};
};