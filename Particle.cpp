#include <iostream>
#include "particleType.h"
#include "resonanceType.h"
#include "particle.h"
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

//INIZIALIZZAZIONE VARIABILI STATICHE

int Particle::fNparticleType=0;

ParticleType *Particle:: fParticleType [Particle::fMaxNumParticleType];


//METODO FIND_PARTICLE

int Particle::FindParticle (const char*name)
{

for (int i=0; i< fNparticleType; i++)
{
if (name==(fParticleType[i]->GetName()))return i;    //se c'Ã¨ corrispondenza
}

return -1; //se non c'Ã¨ corrispondenza
}

//COSTRUTTORE DEFAULT
Particle::Particle(){
fIndex=-1;
fPx=0;
fPy=0;
fPz=0;}


//COSTRUTTORE
Particle::Particle (const char *name, double Px, double Py, double Pz) : fPx(Px), fPy(Py), fPz(Pz)
{
int ip = FindParticle (name);

if (ip != -1)
{
fIndex=ip;}

else {
cout<<name<<" non Ã¨ ancora presente nella tabella"<<endl;
fIndex=-1;}
}



int Particle::GetIndex ()
{return fIndex;}


//METODO ADD_PARTICLE_TYPE


void Particle::AddParticleType (const char*name, double mass, int charge, double width)
{

if ( fNparticleType <10 )

{
if( FindParticle(name)== -1 )
{
if (width==0)
{cout<<"\nnon c'Ã¨ ancora una particella di tipo "<<name<<"; si procede ad aggiungerla"<<endl;
fParticleType[fNparticleType]=new ParticleType (name, mass, charge);
fNparticleType++;}
else  {cout<<"\nnon c'Ã¨ ancora una particella di tipo "<<name<<"; si procede ad aggiungerla"<<endl;  /////
fParticleType[fNparticleType]=new ResonanceType (name,mass,charge,width);
fNparticleType++;} 
}

else 
{cout<<"Ã¨ giÃ  presente particella con quel nome "<<endl;}
}


}

const double Particle:: GetMass() const
{
return fParticleType[fIndex]->GetMass();}


const int Particle:: GetCharge() const
{
return fParticleType[fIndex]->GetCharge();}


const char* Particle:: GetName() const
{
return fParticleType[fIndex]->GetName();}



int Particle::SetIndex(int index)
{
fIndex= index;
return fIndex;} 



void Particle::SetIndex(char *name)
{
fIndex=FindParticle(name);
}



void Particle::Print()
{
for (int i=0; i<fNparticleType; i++)
{
fParticleType[i]->Print();
cout<<"\n";
}
}

void Particle::Print1()
{

cout<<fParticleType[fIndex]->GetName()<<"----> L'indice della particella Ã¨: "<< fIndex<<endl<<"Le componenti dell'impulso sono: "<<"Px = "<<fPx<<", Py= "   <<fPy<<", Pz: "<<fPz<<"\nIl numero dei tipi aggiunti Ã¨ ora: "<<fNparticleType<<endl;}

double Particle::GetPx ()
{return fPx;}

double Particle::GetPy()
{return fPy;}

double Particle::GetPz()
{return fPz;}


double Particle:: E()
{
double P_q =(fPx*fPx)+(fPy*fPy)+ (fPz*fPz);

const double m= fParticleType[fIndex]->GetMass();

double E= sqrt((m*m)+ P_q); 
return E;                    
}


double Particle::InvMass(Particle &p)
{
double E1= p.E();

double P1x=p.GetPx();

double P1y=p.GetPy();

double P1z=p.GetPz();

double E2=E();

double Pt=sqrt((fPx+P1x)*(fPx+P1x)+(fPy+P1y)*(fPy+P1y) + (fPz+P1z)*(fPz+P1z));

double M=sqrt((E1+E2)*(E1+E2)-(Pt)*(Pt)) ;                     

return M;
}

void Particle:: SetP(double px, double py, double pz)

{ fPx=px;

fPy=py;

fPz=pz;}




int Particle::Decay2body(Particle &dau1,Particle &dau2) const 
{if(GetMass() == 0.0){
printf("Decayment cannot be preformed if mass is zero\n");
return 1;
}

double massMot = GetMass();
double massDau1 = dau1.GetMass();
double massDau2 = dau2.GetMass();

if(fIndex> -1){ // add width effect

// gaussian random numbers

float x1, x2, w, y1, y2;

double invnum = 1./RAND_MAX;
do {
x1 = 2.0 * rand()*invnum - 1.0;
x2 = 2.0 * rand()*invnum - 1.0;
w = x1 * x1 + x2 * x2;
} while ( w >= 1.0 );

w = sqrt( (-2.0 * log( w ) ) / w );
y1 = x1 * w;
y2 = x2 * w;

massMot += fParticleType[fIndex]->GetWidth() * y1;

}

if(massMot < massDau1 + massDau2){
printf("Decayment cannot be preformed because mass is too low in this channel\n");
return 2;
}

double pout = sqrt((massMot*massMot - (massDau1+massDau2)*(massDau1+massDau2))*(massMot*massMot - (massDau1-massDau2)*(massDau1-massDau2)))/massMot*0.5;

double norm = 2*M_PI/RAND_MAX;

double phi = rand()*norm;
double theta = rand()*norm*0.5 - M_PI/2.;
dau1.SetP(pout*sin(theta)*cos(phi),pout*sin(theta)*sin(phi),pout*cos(theta));
dau2.SetP(-pout*sin(theta)*cos(phi),-pout*sin(theta)*sin(phi),-pout*cos(theta));

double energy = sqrt(fPx*fPx + fPy*fPy + fPz*fPz + massMot*massMot);

double bx = fPx/energy;
double by = fPy/energy;
double bz = fPz/energy;

dau1.Boost(bx,by,bz);
dau2.Boost(bx,by,bz);

return 0;
}
void Particle::Boost(double bx, double by, double bz)
{

double energy = E();              
//Boost this Lorentz vector
double b2 = bx*bx + by*by + bz*bz;
double gamma = 1.0 / sqrt(1.0 - b2);
double bp = bx*fPx + by*fPy + bz*fPz;
double gamma2 = b2 > 0 ? (gamma - 1.0)/b2 : 0.0;

fPx += gamma2*bp*bx + gamma*bx*energy;
fPy += gamma2*bp*by + gamma*by*energy;
fPz += gamma2*bp*bz + gamma*bz*energy;
}



