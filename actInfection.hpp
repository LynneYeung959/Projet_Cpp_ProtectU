/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|    Activity infection in C++   |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: actInfection.hpp
	Functions' prototypes for the acticity infection

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
//#include "soiree.hpp"
#include "activity.hpp"

class ActInfection: public Activity{
	private:
		std::size_t ptInfection;
	public:
		ActInfection(std::size_t pt):Activity(),ptInfection(pt){};
		virtual ~ActInfection()=default;   
};