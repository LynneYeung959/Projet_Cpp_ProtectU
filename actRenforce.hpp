/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|    Activity renforcée in C++   |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: actRenforce.hpp
	Functions' prototypes for the acticity renforcée

2020-2021 Projet C++
*/


#pragma once
#include <iostream>
//#include "soiree.hpp"
#include "activity.hpp"

class ActRenforce: public Activity{
	private:
		std::size_t ptRenforce;
	public:
		ActRenforce(std::size_t pt):Activity(),ptRenforce(pt){};
		virtual ~ActRenforce()=default;   
};