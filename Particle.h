#ifndef PARTICLE_H
#define PARTICLE_H

#include "particleType.h"

class Particle
{

	public:
	Particle();
	int Decay2body(Particle &dau1, Particle &dau2) const;
	Particle (const char *name, double fPx, double fPy, double fPz);

	static void AddParticleType (const char*name, double mass, int charge, double width=0);
	int GetIndex();
	static void Print ();
	void Print1 ();
	int SetIndex(int index);
	void SetIndex(char *name);
	double GetPx ();
	double GetPy();
	double GetPz();
	double E ();
	double InvMass(Particle &p);
	void SetP (double px, double py, double pz);
	const double GetMass() const;
	const int GetCharge() const;
	const char* GetName () const;
	static const int fMaxNumParticleType=10;

	private:
	void Boost (double bx, double by, double bz);
	static int FindParticle (const char*name);
	static ParticleType *fParticleType [fMaxNumParticleType];

	static int fNparticleType;
	double fPx;
	double fPy;
	double fPz;
	int fIndex;
};




#endif

