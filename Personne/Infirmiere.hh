#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Infirmiere:public Negative{
    public:
        Infirmiere();
};

Infirmiere::Infirmiere()
{
    name = "Infirmiere";
    immunite = 75;
}