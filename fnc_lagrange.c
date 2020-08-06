#include <stdlib.h>
#include "fnc_lagrange.h"

double lagrange_interp(int order, int tot_points,int interp_points,double x[],double y[],double point){
  int i,j;
  double y_interp = 0.0, p;
  for(i = 0;i <= order;i++){
    p=1;
    for(j = 0;j < order;j++){
      if(j!=i){
	p*=(point-x[j])/(x[i]-x[j]);
	}
    }
    y_interp += y[i]*p;
  } 
  return y_interp;
}
