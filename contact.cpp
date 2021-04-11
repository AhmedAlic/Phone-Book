#include "contact.hpp"

string toString (Contact struk)
{
  string kontakt;
  kontakt+=struk.prezime_osobe+",";
  kontakt+=struk.ime_osobe+",";
  kontakt+=to_string(struk.starost_osobe)+",";
  kontakt+=struk.tel_broj_osobe+",";
  kontakt+=struk.firma_osobe+",";
  kontakt+=struk.email_osobe+",";
  kontakt+=struk.grad_osobe;
  return kontakt;
}

Contact fromString (string s)
{
 // try 
 //{   
  Contact kontakt;
  int pozicija=s.find(",",0);
  int nova;
  string dio=s.substr(0,pozicija);
  kontakt.prezime_osobe=dio;

  nova=pozicija+1;
  pozicija=s.find(",",nova);
  dio=s.substr(nova,pozicija-nova);
  kontakt.ime_osobe=dio;
  
  try {  
    nova=pozicija+1;
    pozicija=s.find(",",nova);
    dio=s.substr(nova,pozicija-nova);
    kontakt.starost_osobe=stoi(dio);
  }
  catch (invalid_argument a)
  {
    cout << a.what() << "Greska stoi" << endl;
  }

  nova=pozicija+1;
  pozicija=s.find(",",nova);
  dio=s.substr(nova,pozicija-nova);
  kontakt.tel_broj_osobe=dio;

  nova=pozicija+1;
  pozicija=s.find(",",nova);
  dio=s.substr(nova,pozicija-nova);
  kontakt.firma_osobe=dio;

  nova=pozicija+1;
  pozicija=s.find(",",nova);
  dio=s.substr(nova,pozicija-nova);
  kontakt.email_osobe=dio;

  nova=pozicija+1;
  pozicija=s.find(",",nova);
  dio=s.substr(nova,pozicija-nova);
  kontakt.grad_osobe=dio;

  return kontakt; 
}
