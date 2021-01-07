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

File: actInfection.hh
	Functions' prototypes for the acticity infection

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
#include "activity.hh"

class ActInfection: public Activity{
	private:
		std::size_t ptInfection;
	public:
		ActInfection(std::size_t pt):Activity(),ptInfection(pt){};
		virtual ~ActInfection()=default;   
};