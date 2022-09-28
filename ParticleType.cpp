#include <iostream>
#include "particleType.h"

using namespace std;

ParticleType :: ParticleType (const char *name, double mass, int charge) : fName(name), fMass(mass), fCharge(charge){}

const char* ParticleType:: GetName () const {return fName;}
const double ParticleType:: GetMass() const {return fMass;}

int ParticleType:: GetCharge() const {return fCharge;}

void ParticleType:: Print() const {cout<<"Nome particella:  "<<fName<<endl<<"Massa particella:  "<<fMass<<endl<<"Carica particella:  "<<fCharge<<endl;}

const double ParticleType::GetWidth () const {return 0;}


