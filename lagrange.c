#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fnc_lagrange.h"

int main(){
  int npoints = 9,ener[9],i=0;
  float density[npoints],error[npoints], points =0.0; 
  FILE *fp;
  fp = fopen("/Users/whutzel/local_code/development/c_code/lagrange_interp/lagrange/cross_scattering.dat","r");
  
  while(fscanf(fp,"%d\t%f\t%f\n",&ener[i],&density[i],&error[i]) != EOF){
    i+=1;
    }
  while(points<=ener[npoints]){
    points +=.5;
  }
  return 0;
}
