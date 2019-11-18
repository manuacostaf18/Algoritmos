#include <fstream>
#include <random>
#include <vector>
#include <cmath>
#include <sys/time.h>
/*
 *Incluir la librería que contiene la tabla hash
*/

const int REPETITIONS = 1000; 

double gettime() {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

void ac_time(vector<string> words, int repetitions, int sz, minstd_rand0 &rng,
	     double &av_time, double &sq_time) {
  av_time = 0;
  sq_time = 0;
  for(int n = 0; n < repetitions; ++n){
    vector<string> keys;
    HashMap<int> testmap(numeric_limits<int32_t>::max());
    int ncol = 0;
    //Insert sz elements into the empty table-----
    /*
     *Su código aquí
     */
    
    //time to find every element on the table
    double tstart = gettime();
    for(int i = 0; i < sz; ++i){
      //find every element on the table
      /*
       *Su código aquí
       */
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
  //
  ifstream infile("palabras.txt");
  //load the palabras.txt fole to the vector words
  /*
   *Su código aquí
   */
  //

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
  for(int i = 0; i < 31; ++i){
    double a = sq_time[i] - av_time[i]*av_time[i];
    if(a >= 0)
      fl_time[i] = sqrt(a);
  }
    
  ofstream outfile("time_vs_load.dat");
  cnt = 0;
  for(int sz = TABLE_SIZE-800; sz <= TABLE_SIZE+11200; sz+=400){
    outfile << double(sz) / TABLE_SIZE << " " << av_time[cnt]
	    << " " << fl_time[cnt] << endl;
    cnt++;
  }
  outfile.close();
  
  return 0;
}
