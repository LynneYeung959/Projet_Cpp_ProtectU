#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Vieillard:public Negative{
    public:
        Vieillard();
};

Vieillard::Vieillard()
{
    name = "Vieillard";
    immunite = 60;
}