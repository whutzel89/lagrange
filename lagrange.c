#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fnc_lagrange.h"

int main(){
  int npoints = 9,i=0;
  double density[npoints],error[npoints], points =0.0,p_interp = 0,ener[npoints]; 
  FILE *fp,*fp1;
  fp = fopen("/Users/whutzel/local_code/development/c_code/lagrange_interp/lagrange/cross_scattering.dat","r");
  
  while(fscanf(fp,"%lf\t%lf\t%lf\n",&ener[i],&density[i],&error[i]) != EOF){
    i+=1;
    }
  fclose(fp);
  fp1 = fopen("/Users/whutzel/local_code/development/c_code/lagrange_interp/lagrange/lagrange_interp.dat","w");
  while(points<=ener[npoints-1]){
    p_interp = lagrange_interp(8,9,0,ener,density,points);
    //printf("%f\n",density[2]);
    fprintf(fp1,"%f\t%f\n",points,p_interp);
    points +=1;
  }
  fclose(fp1);
  return 0;
}
