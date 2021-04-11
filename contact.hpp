#ifndef _CONTACT_H
#define _CONTACT_H
#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

struct Contact 
{
  string prezime_osobe;
  string ime_osobe;
  int starost_osobe;
  string tel_broj_osobe;
  string email_osobe;
  string firma_osobe;
  string grad_osobe;
};

string toString (Contact);
Contact fromString (string);

#endif
