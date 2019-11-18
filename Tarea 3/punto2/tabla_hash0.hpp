#ifndef __HASH_HPP
#define __HASH_HPP
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <limits>
#include <fstream>
using namespace std;

const int TABLE_SIZE = 1013;

template<typename VT>
class HashMap{
private:
    struct KeyValueNode {
        string key;
        VT value;
        KeyValueNode *next;
    };
    KeyValueNode **table;
    int tableSize;
    int count;

    VT notfound;

    KeyValueNode * search_bucket(int index, string key);

    //Hash function
    unsigned int hash(string key, int tableSize){
        unsigned int hashVal = 0;
        for (char ch : key)
            hashVal += ch;
        return hashVal % tableSize;
    }
public:
    HashMap(VT def);
    ~HashMap();

    int size();;
    bool empty();
    void clear();
    void display();

    void  ac_time(vector <string > keys , int  repetitions , int size , minstd_rand0 &rng , double &av_time , double &sq_time);
    VT get(string key);
    bool search(string key);
    void insert(string key, VT value);
    void remove(string key);

    void distribution(const string &filename);
};

template<typename VT>
HashMap<VT>:: HashMap(VT def){
    notfound = def;
    count = 0;
    tableSize = TABLE_SIZE;
    table = new KeyValueNode*[TABLE_SIZE];
    for( int i = 0; i < tableSize; i++){
        table[i] = nullptr;
    }
}
template<typename VT>
HashMap<VT>:: ~HashMap(){

}

template<typename VT>
int HashMap<VT>:: size(){
    return count;
}

template <typename VT>
bool HashMap<VT>:: empty(){
    if (count == 0) return true;
    else return false;
}

template<typename VT>
void HashMap<VT>:: clear(){
  count = 0;
}

template<typename VT>
void HashMap<VT>:: display(){
    for ( int i = 0; i < 80; i++){
        cout << i  << " ";
        KeyValueNode *indice = table[i];
        while (indice != nullptr){
            cout  <<"( " << indice->key << ", " << indice->value << ")";
            indice = indice->next;
        }
        cout << endl;
    }
}

template<typename VT>
VT HashMap<VT>:: get(string key){
  KeyValueNode *caja = search_bucket(hash(key), key);
  if(caja != nullptr){
    return caja->value;
  }
  else{
    return notfound;
  }
}

template<typename VT>
void HashMap<VT>:: insert(string key, VT value){
  int ind = hash(key);
    KeyValueNode *indice = table[hash(key)];
    if (indice == nullptr){
        KeyValueNode *caja = new KeyValueNode;
        caja->key = key;
        caja->value = value;
        caja->next = nullptr;
        indice = caja;
        table[hash(key)] = caja;

    }
    else{
      if(search_bucket(ind,key) != nullptr){
        KeyValueNode *cajita = search_bucket(ind,key);
        cajita->value = value;
      }
      else{
        KeyValueNode *caja = new KeyValueNode;
        KeyValueNode *temporal = indice;
        caja->key = key;
        caja->value = value;
        caja->next = temporal;
        indice = caja;
        table[hash(key)] = caja;
      }
    }
    count++;
}

template<typename VT>
typename HashMap<VT>:: KeyValueNode * HashMap<VT>:: search_bucket(int index, string key){
  KeyValueNode *temp = table[index];
  while(temp != nullptr){
    if (temp->key == key){
      return temp;
    }void distribution(const string &filename);
    temp = temp->next;
  }
  return nullptr;
}

template<typename VT>
bool HashMap<VT>:: search(string key){
  for(int i = 0; i < tableSize; i++){
    if (search_bucket(i,key) != nullptr){
      return true;
    }
  }
  return false;
}

template<typename VT>
void HashMap<VT>:: distribution(const string &filename){
  if stream myfile;
  myfile.open(filename);
  if (myfile.is_open()){
    while (!myfile.eof()){
      string palabra = "";
      getline(myfile, palabra);
      mymap.insert(palabra, count);
      count++;
    }
    myfile.close();
  }
}

template<typename VT>
void HashMap<VT>:: ac_time(vector <string> keys , int  repetitions , int size , minstd_rand0 &rng , double &av_time , double &sq_time){
  HashMap<int> first(numeric_limits<int32_t>::max());
  first.insert()
  
}

#endif
