#include "storage.hpp"

Storage loadFromFile (const string& s)
{
  Storage lista;
  string podaci;
  ifstream fajl;
  fajl.open(s);
  if (fajl.is_open())
  {
    while (getline(fajl,podaci))
    {
      lista.lista_kontakata.push_back(fromString(podaci));
    }
    fajl.close();
  }
  else
    cout << "Fajl nije otvoren!" << endl;
  return lista;
}

void writeToFile (const Storage& kolekcija, const string& s)
{
  ofstream fajl;
  fajl.open(s);
  if (fajl.is_open())
  {  
    for (auto it=kolekcija.lista_kontakata.begin();
        it!=kolekcija.lista_kontakata.end();it++)
    {
      fajl << toString(*it) << endl;
    }
    fajl.close();
  }
  else
    cout << "Fajl nije pokrenut";
}

void addContact (Storage& kolekcija, const Contact& podaci)
{
  kolekcija.lista_kontakata.push_back(podaci);
  auto lambda_1=[](iterator_t it) { return it-> grad_osobe; };
  auto lambda_2=[](iterator_t it) { return it-> starost_osobe; };
  kolekcija.mapa_grada=createMap<string>(kolekcija.lista_kontakata,lambda_1);
  kolekcija.mapa_starosti=createMap<int>(kolekcija.lista_kontakata,lambda_2);
}

void editContact (Storage& kolekcija, const string& tel_broj)
{
  Contact kontakt;
  for (auto it=kolekcija.lista_kontakata.begin();
      it!=kolekcija.lista_kontakata.end();it++)
  {

    if ((*it).tel_broj_osobe==tel_broj)
    {
      string izmjena;
      cout << "Unesi izmjene za postojeceg kontakta u formatu:" << endl;
      cout << "PREZIME,IME,STAROST,TELEFON,FIRMA,EMIAL,GRAD" << endl;
      getline(cin,izmjena);
      kontakt=fromString(izmjena);
      *it=kontakt;
    }
  }
}

void searchContact (Storage& kolekcija)
{
  cout << "Odaberite kriterij po kojem zelite izvrsiti pretragu imenika:" << endl;
  cout << "1. po prezimenu i imenu osobe " << endl;
  cout << "2. po telefonskom broju "  << endl;
  int broj;
  cin >> broj;
  Contact kontakt;
  switch (broj)
  {
    case 1:
      cout << "Unesite ime osobe:" << kontakt.ime_osobe << endl;
      cout << "Unesite prezime osobe:" << kontakt.prezime_osobe << endl;
      for (auto it=kolekcija.lista_kontakata.begin();
          it!=kolekcija.lista_kontakata.end();it++)
      {
        if ((*it).prezime_osobe==kontakt.prezime_osobe && 
            (*it).ime_osobe==kontakt.ime_osobe)
          cout << toString(*it) << endl;
      }
      break;
    case 2:
      cout << "Unesi telefon osobe:" << kontakt.tel_broj_osobe << endl;
      for (auto it=kolekcija.lista_kontakata.begin();
          it!=kolekcija.lista_kontakata.end();it++)
      {
        if (it->tel_broj_osobe==kontakt.tel_broj_osobe)
          cout << toString(*it) << endl;
      }
      break;
  }
}

void removeContact (Storage& kolekcija, const string& tel_broj)
{
  for (auto it=kolekcija.lista_kontakata.begin();
          it!=kolekcija.lista_kontakata.end();it++)
  {
    if (it->tel_broj_osobe==tel_broj) 
    {
      kolekcija.lista_kontakata.erase(it);
    }
  } 
}


