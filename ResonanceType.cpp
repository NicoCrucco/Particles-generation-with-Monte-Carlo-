
#include "resonanceType.h"
#include <iostream>

using namespace std;

ResonanceType :: ResonanceType(const char *name1, double mass1, int charge1, double width): ParticleType (name1, mass1, charge1), fWidth(width) {}

const double ResonanceType:: GetWidth() const {return fWidth;}

void ResonanceType:: Print() const 
{ ParticleType::Print(); cout<<"Larghezza:  "<<fWidth<<endl;}

