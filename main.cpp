#include "contact.hpp"
#include "storage.hpp"

int main()
{
  Storage kolekcije;
  Contact kontakti;
  fstream fajl;
  cout << "Unesite ime fajla:";
  string ime;
  getline(cin,ime);
  if (ime=="")
    ime="imenik.csv";
  fajl.open(ime);
  kontakti=fromString(ime);
  kolekcije=loadFromFile(ime);
  auto extractCity= [] (iterator_t it) { return it->grad_osobe; };
  auto extractAge= [] (iterator_t it) { return it->starost_osobe; };
  kolekcije.mapa_grada=createMap<string>(kolekcije.lista_kontakata,extractCity);
  kolekcije.mapa_starosti=createMap<int>(kolekcije.lista_kontakata,extractAge);
  cout << "Odaberite akciju:" << endl;
  cout << '\t' << "1 - prikazi sve kontakte" << endl;
  cout << '\t' << "2 - prikazi sve kontakte iz nekog grada" << endl;
  cout << '\t' << "3 - prikazi sve kontakte iste starosti" << endl;
  cout << '\t' << "4 - dodaj kontakt" << endl;
  cout << '\t' << "5 - obrisi kontakt" << endl;
  cout << '\t' << "6 - pronadji kontakt" << endl;
  cout << '\t' << "7 - snimi stanje u file" << endl;
  cout << '\t' << "0 - kraj" << endl;
  cout << "= ";
  int izbor;
  string novi_kontakt,broj_za_brisanje;
  string grad_,starost_;
  while (cin >> izbor)
  {
  switch (izbor)
    {  
    case 1:
      for (auto it=kolekcije.lista_kontakata.begin();it!=kolekcije.lista_kontakata.end();it++)
        cout << toString (*it) << endl;
      break;
    case 2:
      cout << "Upisite grad za kojeg zelite listu svih kontakata:";
      cin >> grad_;
      for (auto it=kolekcije.mapa_grada.begin();it!=kolekcije.mapa_grada.end();it++)
      {
          if (it->first == grad_)
            cout << it->first << endl;
      }
      break;
    case 3:
      cout << "Upisite starost za koju zelite listu svih kontakata:";
      break;
    case 4:
      cout << "Upisite informacije novog kontakta u formatu: PREZIME,IME,STAROST,TELEFON,FIRMA,EMAIL,GRAD!";
      cin >> novi_kontakt;
      addContact(kolekcije,fromString(novi_kontakt));
      break;
    case 5:
      cout << "Unesite broj preko kojeg zelite izbrisati odredjeni kontakt:";
      cin >>  broj_za_brisanje;
      removeContact(kolekcije,broj_za_brisanje);
      break;
    case 6:
      writeToFile(kolekcije,ime);
      break;
    case 7:
      break;
    }
  cout << "Odaberite akciju:" << endl;
  cout << '\t' << "1 - prikazi sve kontakte" << endl;
  cout << '\t' << "2 - prikazi sve kontakte iz nekog grada" << endl;
  cout << '\t' << "3 - prikazi sve kontakte iste starosti" << endl;
  cout << '\t' << "4 - dodaj kontakt" << endl;
  cout << '\t' << "5 - obrisi kontakt" << endl;
  cout << '\t' << "6 - pronadji kontakt" << endl;
  cout << '\t' << "7 - snimi stanje u file" << endl;
  cout << '\t' << "0 - kraj" << endl;
  cout << "= ";
  }
  return 0;
}
