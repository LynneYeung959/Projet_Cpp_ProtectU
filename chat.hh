/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|     Activity: Chat in C++      |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: chat.hh
	Functions' prototypes for the carte "Chat"

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
//#include "soiree.hpp"
#include "actInfection.hh"

class Chat: public ActInfection{
	public:
		Chat():ActInfection(15){
            nom = "Chat";
        };
		std::string estFait(){
			fait = "1";
			return fait;
		}
		std::string getName(){return nom;};
        
};