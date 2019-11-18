#ifndef __HASH_hpp
#define __HASH_hpp

#include <iostream>
#include <cstdint>
#include <limits>
using namespace std;

const int TABLE_SIZE = 50;

template <typename VT>
class HashMap{
	private:
		struct KeyValueNode{
			string key;
			VT value;
			KeyValueNode *next;
		};

		KeyValueNode **table;
		
		int tableSize;
		int count;
		
		VT notfound;
		
		KeyValueNode *search_bucket(int index, string key); //ok
		
		unsigned int hash(string key){
			unsigned int hashVal = 0;
			for(char ch : key)
				hashVal += ch;
			return hashVal % tableSize;
		}
		
	public:
		HashMap(VT def); //ok
		~HashMap();
		
		int size(); //ok
		bool empty(); //ok
		void clear();
		
		VT get(string key);
		bool search(string key); //ok
		void insert(string key, VT value); //ok
		void remove(string key);
		void distribution(const string &filename);
		void display(); //ok
};

template <typename VT>
HashMap<VT>::HashMap(VT def){
	notfound = def;
	count = 0;
	tableSize = TABLE_SIZE;
	table = new KeyValueNode* [tableSize];
	for(int i = 0; i < tableSize; i++){
		table[i] = nullptr;
	}
}

template <typename VT>
HashMap<VT>::~HashMap(){
	//hacer
}

template <typename VT>
int HashMap<VT>::size(){
	return count;
}

template <typename VT>
bool HashMap<VT>::empty(){
	if(count == 0) return true;
	return false;
}

template <typename VT>
void HashMap<VT>::clear(){
	//hacer
}

template <typename VT>
VT HashMap<VT>::get(string key){
	KeyValueNode *caja = search_bucket(hash(key), key); 
	if(caja != nullptr){
		return caja->value;
	}else{
		return notfound;
	}
}

template <typename VT>
void HashMap<VT>::insert(string key, VT value){
	int ind = hash(key);
	KeyValueNode *indice = table[ind];
	if(indice == nullptr){
		KeyValueNode *caja = new KeyValueNode;
		caja->key = key;
		caja->value = value;
		caja->next = nullptr;
		indice = caja;
		table[ind] = caja;
	}else{
		if(search_bucket(ind, key) != nullptr){
			KeyValueNode *cajita = search_bucket(ind, key);
			cajita->value = value;
		}else{	
			KeyValueNode *caja = new KeyValueNode;
			KeyValueNode *temp = indice;
			caja->key = key;
			caja->value = value;
			caja->next = temp;
			indice = caja;
			table[ind] = caja;
		}
	}
	count ++;
	
	
}

template <typename VT>
void HashMap<VT>::display(){
	cout << "Displaying" << endl;
	cout << count << endl;
	for(int i = 0; i < 50; i++){
		cout << i << " ";
		KeyValueNode *indice = table[i];
		while(indice != nullptr){
			cout << "(" << indice->key << ", " << indice->value << ")";
			indice = indice->next;
		}
		cout << endl;
	}
}

template <typename VT>
typename HashMap<VT>::KeyValueNode * HashMap<VT>::search_bucket(int index, string key){
	KeyValueNode *temp = table[index];
	while(temp != nullptr){
		if(temp->key == key){
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

template <typename VT>
bool HashMap<VT>::search(string key){
	for(int i = 0; i < tableSize; i++){
		if(search_bucket(i, key) != nullptr){
			return true;
		}
	}
	return false;
}

#endif
