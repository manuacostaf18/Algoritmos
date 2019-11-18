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
  //int tSize = TABLE_SIZE;

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
  /*
   *Su
   *código
   *aquí
   */
  

  //...using hash64
  //unsigned int count_hash64[tSize] = {0};
  /*
   *Su
   *código
   *aquí
   */
  

  //Print the output as to a file thet can be loaded and
  // plotted with python
  /*
   *Su
   *código
   *aquí
   */
  
  return 0;
}
