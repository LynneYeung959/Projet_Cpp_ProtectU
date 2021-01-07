#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

namespace Carte{
typedef enum Carte{Personnage, Objet, Activite} Carte;
};

ostream& operator<<(ostream& out, Carte::Carte c);
