#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Personnage
{
    public:
        Personnage(string name,char etat,int immunite);
        
        
    protected:
        std::string name;
        char etat;
        int immunite;
};

Personnage::Personnage(string name,char etat,int immunite)
{
    name = name;
    etat = etat;
    immunite = immunite;
}