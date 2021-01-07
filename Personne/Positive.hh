#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Patient:public Personnage
{
    public:
        Patient();
};

Patient::Patient()
{
    name = "Patient";
    etat = 'P';
}