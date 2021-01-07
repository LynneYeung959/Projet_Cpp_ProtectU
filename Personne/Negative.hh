#pragma once

#include<iostream>
#include<cstdlib>
#include <string>

class Normal:public Personnage
{
    public:
        Normal();
};

Normal::Normal()
{
    etat = 'N';
}