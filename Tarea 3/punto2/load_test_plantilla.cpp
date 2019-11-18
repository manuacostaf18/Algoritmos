#include <fstream>
#include <random>
#include <vector>
#include <cmath>
#include <sys/time.h>
#include "tablas_hash0.hpp"

const int REPETITIONS = 1000; 

double gettime() {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

void ac_time(vector<string> & words, int repetitions, int sz, minstd_rand0 &rng,
	     double &av_time, double &sq_time) {
  av_time = 0;
  sq_time = 0;
  for(int n = 0; n < repetitions; ++n){
    vector<string> keys;
    HashMap<int> testmap(numeric_limits<int32_t>::max());
    int ncol = words.size();
    //Insert sz elements into the empty table-----
    for(int i = 0; i < sz; ++i){
    	int random = int(ncol * (int(rng()) / rng.max()));
    	string palabra = words[random];
    	testmap.insert(palabra, 0);
    	keys.push_back(palabra);
    }
    
    //time to find every element on the table
    double tstart = gettime();
    for(int i = 0; i < sz; ++i){
      //find every element on the table
    	testmap.get(keys[i]);
    }
    double tstop = gettime();
    double t = (tstop-tstart) / sz;
    av_time += t;
    sq_time += t*t;
  }
  av_time /= repetitions;
  sq_time /= repetitions;
}


int main() {
  //Read the words to a vector
  vector<string> words;
  //load the palabras.txt fole to the vector words
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

  //random number generator
  unsigned seed = 432;
  minstd_rand0 rng(seed);

  double av_time[31] = {0.};
  double sq_time[31] = {0.};

  //For different values of N/TABLE_SIZE...
  int cnt = 0;
  for(int sz = TABLE_SIZE-800; sz <= TABLE_SIZE+11200; sz+=400){
    //Average over a number of realizations....
    double at, st;
    ac_time(words, REPETITIONS, sz, rng, at, st);
    av_time[cnt] = at;
    sq_time[cnt] = st;
    cnt++;
  }

  double fl_time[31];
  for(int i = 0; i < 31;++i){
    double a = sq_time[i] - av_time[i]*av_time[i];
    if(a >= 0)
      fl_time[i] = sqrt(a);
  }
    
  ofstream outfile0("time_vs_load.dat");
  cnt = 0;
  for(int sz = TABLE_SIZE-800; sz <= TABLE_SIZE+11200; sz+=400){
    outfile0 << double(sz) / TABLE_SIZE << " " << av_time[cnt]
	    << " " << fl_time[cnt] << endl;
    cnt++;
  }
  outfile0.close();
  
  return 0;
}
