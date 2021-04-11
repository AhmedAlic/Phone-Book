#ifndef _STORAGE_HPP
#define _STORAGE_HPP

#include "contact.hpp"
#include<list>
#include<map>
#include<functional>
#include<fstream>

using iterator_t=list<Contact>::const_iterator;

struct Storage
{
  list<Contact> lista_kontakata;
  map<string,list<iterator_t>> mapa_grada;
  map<int,list<iterator_t>> mapa_starosti;
};

Storage loadFromFile (const string&);
void writeToFile (const Storage&, const string&);
void addContact (Storage&, const Contact&);
void editContact (Storage&, const string&);
void searchContact (Storage&);
void removeContact (Storage&, const string&);

template<typename T>
map<T,list<iterator_t>> createMap(const list<Contact>& lista,
    function<T(iterator_t)> kriterij)
{
  map<T,list<iterator_t>> mapa;
  for (auto it=lista.begin();it!=lista.end();it++)
  {
    mapa[kriterij(it)].push_back(it);
  }
  return mapa;
} 

#endif
