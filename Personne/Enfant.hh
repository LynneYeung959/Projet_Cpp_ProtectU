#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Enfant:public Negative{
    public:
        Enfant();
};

Enfant::Enfant()
{
    name = "Enfant";
    immunite = 75;
}