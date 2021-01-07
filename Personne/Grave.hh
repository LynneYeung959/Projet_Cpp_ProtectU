#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Grave:public Positive
{
    public:
        Grave();
};

Grave::Grave()
{
    immunite = 25;
}