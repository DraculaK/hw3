#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ranum(double* p, const int N){
  srand(time(NULL));
  for (int i=0; i<N; i++){
  double r = ((double) rand() / (RAND_MAX));
  p[i] = r;
  //cout << "p[" << i << "]=" << p[i] << endl;
  }
}

void stat(double* p, const int N, double& mean, double& var){
  double summean=0;
  for(int i=0; i<N; i++){
    summean += p[i];
    mean = summean/N;
  }
  
  double sumvar=0;
  for(int i=0; i<N; i++){
    sumvar += pow((p[i]-mean),2.0);
    var = sumvar/N;
  }
}

int main(){
   const int N = 100;
   double p[N];
   double mean, var;

   ranum(p,N);
   stat(p,N,mean,var);
   
   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}
