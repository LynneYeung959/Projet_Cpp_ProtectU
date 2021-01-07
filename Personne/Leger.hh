#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Leger:public Positive
{
    public:
        Leger();
};

Leger::Leger()
{
    immunite = 50;
}