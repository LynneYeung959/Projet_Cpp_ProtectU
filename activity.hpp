/*

* ------------------------------ *
|                                |
|   -= Coding Carte Game =-      |
|                                |
|       Activity in C++         |
|                                |
* ------------------------------ *

Authors: YANG Liyun, JIN Qianhui
Licence: GPL

File: activity.hpp
	Functions' prototypes for the activity

2020-2021 Projet C++
*/

#pragma once
#include <iostream>

class Activity{
    public:
        std::string nom;
        std::string fait;
    protected:
        Activity():fait("0"){};
        virtual ~Activity()=default;
        virtual std::string estFait() = 0;
        virtual std::string getNom() = 0;
};