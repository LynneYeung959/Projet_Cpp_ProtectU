#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Jeune:public Negative{
    public:
        Jeune();
};

Jeune::Jeune()
{
    name = "Jeune";
    immunite = 100;
}