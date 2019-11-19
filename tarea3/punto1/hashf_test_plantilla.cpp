//Manuela Acosta, María Paula Gaviria y Sebastian Martínez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <wchar.h>
using namespace std;

const int TABLE_SIZE = 101;

//suma los códigos ascci de sus caracteres
unsigned int hash0(string key, int tableSize) {
  unsigned int hashVal = 0;
  for(char c : key)
    hashVal += c;
  return hashVal % tableSize;
}

//Dado que hay 64 caracteres, calcula el código del
// string en base 64
unsigned int hash64(string key, int tableSize) {
  unsigned int hashVal = 0;
  for(char c : key)
    hashVal += 64 * hashVal + c;
  return hashVal % tableSize;
}

int main() {
  //size of the table
  int tSize = TABLE_SIZE;

  //Read the words to a vector
  vector<string> words;
  
  ifstream myfile;
  myfile.open("palabras.txt");
	string palabra = "";
	if(myfile.is_open()){
		while(!myfile.eof()){
			myfile >> palabra;
			cout << palabra << endl;
			words.push_back(palabra);
		}
	}
  myfile.close();

  //Check the file was loaded to the vector
  for(unsigned int i = 0; i < words.size(); ++i){
    cout << words[i] << endl;
  }

  //Count how many words where mapped to each of the
  // 100 elements of the table...

  //...using hash0
  unsigned int count_hash0[tSize] = {0};
	for(unsigned int i = 0; i < words.size(); i++){
		int position = hash0(words[i], tSize);
		count_hash0[position]++;
	} 	
  

  //...using hash64
  unsigned int count_hash64[tSize] = {0};
	for(unsigned int i = 0; i < words.size(); i++){
		int position = hash64(words[i], tSize);
		count_hash64[position]++;
	} 
  

  //Print the output as to a file thet can be loaded and
  // plotted with python
  filebuf file1;
  file1.open("hash0.txt", ios::out);
  ostream os1(&file1);
  
  for(int i = 0; i < tSize; i++){
  	os1 << count_hash0[i] << ',';
  }
  file1.close();
  
  filebuf file2;
  file2.open("hash64.txt", ios::out);
  ostream os2(&file2);
  
  for(int i = 0; i < tSize; i++){
  	os2 << count_hash64[i] << ',';
  }
  file2.close();
 
  return 0;
}
