#include <iostream>
using namespace std;
#include "Riostream.h"
#include "particleType.h"
#include "resonanceType.h"
#include "particle.h"
#include "TH1F.h"
#include "TMath.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"


int main ()
{
gStyle->SetOptFit(1111);
Particle::AddParticleType("pione+", 0.13957, 1 ,0);

Particle::AddParticleType("pione-", 0.13957, -1,0);

Particle::AddParticleType("Kaone+", 0.49367, 1,0);

Particle::AddParticleType("Kaone-", 0.49367, -1,0);

Particle::AddParticleType("protone+", 0.93827, 1,0);

Particle::AddParticleType("protone-", 0.93827, -1,0);

Particle::AddParticleType("K*", 0.89166, 0, 0.050);


//COSTRUZIONE GRAFICI E CANVAS
TH1F *h1=new TH1F ("h1", "Phi distribution", 1000, 0, 2*TMath::Pi() );
TCanvas *c1=new TCanvas ("c1", "c1" , 65, 75, 1000, 1000);
c1->Divide(2,2);

h1->GetXaxis()->SetTitle("Phi (rad)");
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetYaxis()->SetTitle("Entries");
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetTitleOffset(1.2);

TH1F *h2=new TH1F ("h2", "Theta distribution", 1000, 0, TMath::Pi());


h2->GetXaxis()->SetTitle("Theta (rad)");
h2->GetXaxis()->SetTitleSize(0.05);
h2->GetXaxis()->SetTitleOffset(0.6);
h2->GetYaxis()->SetTitle("Entries");
h2->GetYaxis()->SetTitleSize(0.05);
h2->GetYaxis()->SetTitleOffset(1.1);


TH1F *h3=new TH1F ("h3", "Types distribution ", 7,0 ,7);

h3->GetXaxis()->SetTitle("Particle type(K*,K+,K-,protone+,protone-,pione+,pione-)");
h3->GetXaxis()->SetTitleSize(0.05);
h3->GetXaxis()->SetTitleOffset(0.7);
h3->GetYaxis()->SetTitle("Entries");
h3->GetYaxis()->SetTitleSize(0.06);
h3->GetYaxis()->SetTitleOffset(0.9);





TH1F *h4=new TH1F ("h4", "Pulse distribution", 1000, 0, 10);

h4->GetXaxis()->SetTitle("Pulse (GeV/c)");
h4->GetXaxis()->SetTitleSize(0.05);
h4->GetXaxis()->SetTitleOffset(0.7);
h4->GetYaxis()->SetTitle("Entries");
h4->GetYaxis()->SetTitleSize(0.05);
h4->GetYaxis()->SetTitleOffset(0.8);



TH1F *h5=new TH1F ("h5", "distribuzione impulso trasverso", 1000, 0, 10);
TCanvas *c5=new TCanvas ("c5", "c5", 65, 75, 700, 700);

TH1F *h6=new TH1F ("h6", "distribuzione energia", 1000, 0 ,10);
TCanvas *c6=new TCanvas ("c6", "c6", 65, 75, 700, 700);

TH1F *h7=new TH1F ("h7", "massa invariante particelle totali", 1000, 0, 10);
TCanvas *c7=new TCanvas ("c7", "c7", 65, 75, 700, 700);

TH1F *h8=new TH1F ("h8", "massa invariante particelle carica discorde", 100, 0.5, 1.5);
TCanvas *c8=new TCanvas ("c8", "c8", 65, 75, 700, 700);


TH1F *h9=new TH1F ("h9", "massa invariante particelle carica concorde", 100, 0.5, 1.5);
TCanvas *c9=new TCanvas ("c9", "c9", 65, 75, 700, 700);

TH1F *h10=new TH1F ("h10", "invariant mass P+/K-, P-/K+", 100,0.5,1.5);
TCanvas *c10=new TCanvas ("c10", "c10", 65, 75, 700, 700); 


TH1F *h11=new TH1F ("h11", "invariant mass P+/K+, P-/K-", 100, 0.5, 1.5);
TCanvas *c11=new TCanvas ("c11", "c11", 65, 75, 700,700);



TH1F *h12=new TH1F ("h12", "Invariant mass decays K*", 100, 0.5, 1.5);
TCanvas *c12=new TCanvas ("c12", "c12", 65, 75, 900, 900);

h12->GetXaxis()->SetTitle("Invariant Mass (GeV/c2)");
h12->GetXaxis()->SetTitleSize(0.05);
h12->GetXaxis()->SetTitleOffset(0.6);
h12->GetYaxis()->SetTitle("Counts/(1 MeV/c2)");
h12->GetYaxis()->SetTitleSize(0.05);
h12->GetYaxis()->SetTitleOffset(0.4);

c12->Divide(1,3);

TH1F *h13 = new TH1F ("h13", "Subtraction invariant mass P,K opposite sign and P,K same sign", 100, 0.5, 1.5);
h13->GetXaxis()->SetTitle("Invariant Mass (GeV/c2)");
h13->GetXaxis()->SetTitleSize(0.05);
h13->GetXaxis()->SetTitleOffset(0.6);
h13->GetYaxis()->SetTitle("Counts/(1 MeV/c2)");
h13->GetYaxis()->SetTitleSize(0.05);
h13->GetYaxis()->SetTitleOffset(0.4);


TH1F *h14 = new TH1F ("h14", "Subtraction invariant mass charges opposite sign and same sign", 100, 0.5, 1.5);
h14->GetXaxis()->SetTitle("Invariant Mass (GeV/c2)");
h14->GetXaxis()->SetTitleSize(0.05);
h14->GetXaxis()->SetTitleOffset(0.5);
h14->GetYaxis()->SetTitle("Counts/(1 MeV/c2");
h14->GetYaxis()->SetTitleSize(0.05);
h14->GetYaxis()->SetTitleOffset(0.4);


TF1 *g0 = new TF1("g0","gaus", 0.7,1.1);

TF1 *g1 = new TF1("g1","gaus", 0.6,1.1);

Particle particelle [120];
double theta;
double phi;
double p;
double px;
double py;
double pz;
double pt;
double E;
int w;
double mik;
int a;
for (int n=0; n<100000; n++)               

{
int j=0;




for (int i=0; i<100; i++)
{
p=gRandom->Exp(1);
h4->Fill(p);
theta = gRandom->Rndm()*TMath::Pi();
phi= gRandom->Rndm()*2*TMath::Pi();
h1->Fill(phi);
h2->Fill(theta);
double x= gRandom->Rndm();
px= p* sin(phi) * cos(theta);
py= p* sin(phi) * sin(theta);
pz= p* cos(phi);
pt= sqrt((px*px)+(py*py));
h5->Fill(pt);

if (x<0.01)
{
particelle[i].SetIndex("K*");



double t=gRandom->Rndm();
if(t<0.5)
{

particelle[100+j].SetIndex("Kaone+"); 
particelle[101+j].SetIndex("pione-");



particelle[i].Decay2body(particelle[100+j], particelle[101+j]);


mik = particelle[100+j]. InvMass(particelle[101+j]);
h12->Fill(mik);

} 

else
{
particelle[100+j].SetIndex("Kaone-");
particelle[101+j].SetIndex("pione+");


particelle[i].Decay2body(particelle[100+j], particelle[101+j]);

//MASSA INVARIANTE DECADIMENTI K*
mik = particelle[100+j]. InvMass(particelle[101+j]);

h12->Fill(mik);
}


h3->Fill(0);
j+=2;}


else if (x<0.11) {
double t=gRandom->Rndm();


if(t<0.5)
{particelle[i].SetIndex("Kaone+"); 
h3->Fill(1);

} 
else if(t>0.5)
{particelle[i].SetIndex("Kaone-");
h3->Fill(2);

}
}

else if (x<0.20)
{double t=gRandom->Rndm();
if(t<0.5)
{particelle[i].SetIndex("protone+");
h3->Fill(3);

}    
else if(t>0.5)
{particelle[i].SetIndex("protone-");
h3->Fill(4);

}
}

else if (x<1){
double t=gRandom->Rndm();
if(t<0.5)
{particelle[i].SetIndex("pione+");
h3->Fill(5);
particelle[i].SetP(px,py,pz);
E= particelle[i].E();
h6->Fill(E);
}       
else if(t>0.5)
{particelle[i].SetIndex("pione-");
h3->Fill(6);

}
}

particelle[i].SetP(px,py,pz);
E= particelle[i].E();
h6->Fill(E);

}
w=100+j;


//MASSA INVARIANTE TOTALE

for (int i=1; i<w; i++)
{
for (int j=0; j<i; j++) 
{double m= particelle[i]. InvMass (particelle[j]);
h7-> Fill(m);
}}


//MASSA INVARIANTE CARICA DISCORDE


for (int i=1; i<w; i++)
{
int charge= particelle[i].GetCharge();
for (int j=0; j<i ; j++)
{
int charge1=particelle[j].GetCharge();
if (charge != 0 && charge1 != 0 && charge != charge1)
{
double m= particelle[i]. InvMass (particelle[j]);
h8-> Fill(m);
}
}
}


//MASSA INVARIANTE CARICA CONCORDE

for (int i=1; i<w; i++)
{
int charge= particelle[i].GetCharge();
for (int j=0; j<i ; j++)
{
int charge1=particelle[j].GetCharge();
if (charge != 0 && charge1 != 0 && charge == charge1)
{
double m= particelle[i]. InvMass (particelle[j]);
h9-> Fill(m);
}
}
}


//MASSA INVARIANTE PIONE+/KAONE- E PIONE-/KAONE+

for (int i=1; i<w; i++)
{
const char* name="pione+";
const char* name1="Kaone-";
const char* name4="pione-";
const char* name5="Kaone+";
const char* namep= particelle[i].GetName();
if (namep == name){       
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name1)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h10->Fill(m);
}
}
}
else if (namep==name1)
{
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h10->Fill(m);
}
}
}

if (namep == name4){       
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name5)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h10->Fill(m);
}
}
}
else if (namep==name5)
{
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name4)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h10->Fill(m);
}
}
}

}



//MASSA INVARIANTE PIONE+/KAONE+ E PIONE-/KAONE-

for (int i=1; i<w; i++)
{
const char* name="pione+";
const char* name1="Kaone-";
const char* name4="pione-";
const char* name5="Kaone+";
const char* namep= particelle[i].GetName();
if (namep == name){       
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name5)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h11->Fill(m);
}
}
}
else if (namep==name5)
{
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h11->Fill(m);
}
}
}

if (namep == name4){       
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name1)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h11->Fill(m);
}
}
}
else if (namep==name1)
{
for (int j=1; j<=i ; j++)
{
const char* name3=particelle[i-j].GetName();
if (name3==name4)
{  
double m= particelle[i]. InvMass (particelle[i-j]);
h11->Fill(m);
}
}
}

}
}

c1->cd(1);
h1->Fit("pol0");
h1->Draw();


c1->cd(2);
h2->Fit("pol0");
h2->Draw();


c1->cd(3);
h3->SetFillColor(kGreen);
h3->Draw();

c1->cd(4);
h4->Fit("expo");
h4->SetFillColor(kBlue);
h4->Draw();


c5->cd();
h5->SetFillColor(kYellow);
h5->Draw();

c6->cd();
h6->SetFillColor(kBlue);
h6->Draw();

c7->cd();
h7->SetFillColor(kRed);
h7->Draw();

c8->cd();
h8->SetFillColor(kYellow);
h8->Draw();

c9->cd();
h9->SetFillColor(kBlue);
h9->Draw();

c10->cd();
h10->SetFillColor(kGreen);
h10->Draw();

c11->cd();
h11->SetFillColor(kBlue);
h11->Draw();

c12->cd(1);
h12->SetFillColor(kBlue);
h12->Fit("gaus");
h12->Draw();

c12->cd(2);
h13->Sumw2();
h13->Add(h10,h11,1,-1);
h13->SetFillColor(kYellow);
h13->Fit(g0,"R");
h13->Draw();

c12->cd(3);
h14->Sumw2();
h14->Add(h8,h9,1,-1);
h14->SetFillColor(kBlue);
h14->Fit(g1,"R");
h14->Draw();


cout<<"Contenuto bin distribuzione tipi:"<<endl;
for (int i=1; i<8; i++){
cout<<"bin numero "<<i<<" con contenuto di: "<<h3->GetBinContent(i)<<" e errore "<<h3->GetBinError(i)<<endl;}


}
