#include "header.h"

data::~data() //destructor
{
    std::fill_n(paz, 20, 0);
}

data::data(const data& d) // copy konstruktorius
{
    vard = d.vard;
    pav = d.pav;
    egz = d.egz;
    vidrezult = d.vidrezult;
    medrezult = d.medrezult;
}

data& data::operator=(const data& d) //copy assignment
{ 
    if (&d == this) return *this;
    vard = d.vard;
    pav = d.pav;
    egz = d.egz;
    vidrezult = d.vidrezult;
    medrezult = d.medrezult;
    return *this;
}

void data::setmed(double sk) { medrezult = sk; }
double data::getmed() const { return medrezult; }

void data::setvid(double sk) { vidrezult = sk; }
double data::getvid() const { return vidrezult; }

void data::setegz(double sk) { egz = sk; }
int data::getegz() const { return egz; }

void data::setpaz(int i, double sk) { paz[i] = sk; }
int data::getpaz(int i) const { return paz[i]; }

void data::setvard(string vardas) { vard = vardas; }
void data::setpav(string pavarde) { pav = pavarde; }
