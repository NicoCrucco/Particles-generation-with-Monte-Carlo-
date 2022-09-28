#ifndef RESONANCETYPE_H
#define RESONANCETYPE_H

#include "particleType.h"

class ResonanceType: public ParticleType
{
    public:
    ResonanceType(const char *name1, double mass1, int charge1, double width);
    virtual const double GetWidth() const;
    virtual void Print() const;

    private:
    const double fWidth;
};
#endif
