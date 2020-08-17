#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fnc_lagrange.h"

double lagrange_interp(int order, int tot_points,int interp_points,double ener[],double density[],double point){
  int i,j,npoints = order+1,numb_points,iter;
  double y_interp = 0.0, p,x[npoints],y[npoints];
  j = 0;
  numb_points = round(tot_points/order);
  printf("numb_point:%d\n\n",numb_points);
  // for(i = 0; i<tot_points;i++){
  //  if(((i+1)%numb_points) == 0){
  //    x[j] = ener[i];
  //    y[j] = density[i];
  //    printf("%f\t%f\n",x[j],y[j]);
  //    j+=1;
  //  }
  // }
  iter = tot_points - npoints;
  if(npoints<tot_points){
    while(j<npoints){
      i = (j*iter)%tot_points;
      x[j] = ener[i];
      y[j] = density[i];
      j+=1;
    }
  }else{
    while(j<tot_points){
      x[j] = ener[j];
      y[j] = density[j];
	j+=1;
    }
  }
  //add a floor function do floor(tot_points/order)
  for(i = 0;i < order;i++){
    p=1;
    for(j = 0;j < order;j++){
      if(j!=i){
	p*=(point-x[j])/(x[i]-x[j]);
	}
    }
    y_interp += y[i]*p;
    printf("y_interp:\t%f\n",y_interp);
  } 
  return y_interp;
}
