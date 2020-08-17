# lagrange
[![Generic badge](https://img.shields.io/badge/<GCC>-<11.0.3>-<COLOR>.svg)](https://shields.io/) 
[![No Maintenance Intended](http://unmaintained.tech/badge.svg)](http://unmaintained.tech/)
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)




C code which does a lagrange fit for some tabulated scattering cross sections as a function of energy. The table from which the polynomial coeficients are bring tabulated from are given in cross_scattering.dat.

## Table of contents
* [Installation](#installations)
* [Technical Overview](#technical-overview)
* [Setup](#setup)
* [Authors](#authors)
* [Contributing](#contributing)
* [License](#license)

## Installation

This code was developed using [EMACs](https://www.gnu.org/software/emacs/) on a MAC OS Catalina 10.15.2 with the Apple clang version 11.0.3 (clang-1103.0.32.62) compiler. 

## Technical Overview

Lagrange fits a polynomial of order n-1, where n is the number of points being samples from a set of given (or experiamental data) points. The polynomial is given by:

<a href="https://www.codecogs.com/eqnedit.php?latex=P(x)&space;=&space;\sum_{j=1}^n&space;P_j(x)" target="_blank"><img 

where,

<a href="https://www.codecogs.com/eqnedit.php?latex=P_j(x)&space;=&space;y_j&space;\prod_{k&space;\neq&space;j}^n&space;\frac{x-x_k}{x_j-x_k}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?P_j(x)&space;=&space;y_j&space;\prod_{k&space;\neq&space;j}^n&space;\frac{x-x_k}{x_j-x_k}" title="P_j(x) = y_j \prod_{k \neq j}^n \frac{x-x_k}{x_j-x_k}" /></a>

The code samples npoints from the ener and density arrays. Note: the sampling method is not perfect but runs resonably well for this small code snippet. Choosing different orders of fucntion results in varying fits as shown in the below figures:
  ![Order 3 poly](https://github.com/whutzel89/lagrange/blob/master/order3.png)
  ![Order 4 poly](https://github.com/whutzel89/lagrange/blob/master/order4.png)
  ![Order 7 poly](https://github.com/whutzel89/lagrange/blob/master/order7.png)
  ![Order 8 poly](https://github.com/whutzel89/lagrange/blob/master/order8.png)
  
  If we push the code pas sampling the less than order 2 or order 8 polynomials

## Setup

To runt the file you will need to pull fnc_lagrange.c, fnc_lagrange.h, cross_scattering.dat, and lagrange.c Make sure the dependencies in installation are installed on your computer. Use the make command to compile the code. Proper compilationf of the code will results in the follwoing terminal message:


    gcc  -I/your_directory/lagrange/ -c  lagrange.c
    gcc  -I/your_directory/lagrange/ -c  fnc_lagrange.c
    gcc -g -Wall -o lagrange lagrange.o fnc_lagrange.o -L/usr/local/lib -lclapack -lcblas 


## Authors

**William Hutzel** -- initial commit

## Contributing
Pull requests are welcome and colloboration is appreciated.

## License
[GPLV3](https://choosealicense.com/licenses/gpl-3.0/)
