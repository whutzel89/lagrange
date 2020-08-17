#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug  9 21:15:09 2020

@author: whutzel
"""
import matplotlib.pyplot as plt
import csv
import numpy as np

path = "lagrange_interp.dat"
with open(path) as f:
    reader = csv.reader(f, delimiter="\t")
    d = list(reader)
inter_x = np.zeros([len(d)])
inter_y = np.zeros([len(d)])
for x in range(len(d)):
    inter_x[x]=d[x][0]
    inter_y[x]=d[x][1]
    
path = "cross_scattering.dat"
with open(path) as f:
    reader = csv.reader(f, delimiter="\t")
    d = list(reader)
act_x = np.zeros([len(d)])
act_y = np.zeros([len(d)])
for x in range(len(d)):
    act_x[x]=d[x][0]
    act_y[x]=d[x][1]
#file1 = open("lagrange_interp.dat",'r')
#lines = file1.read().split('    ')
plt.plot(inter_x,inter_y)
plt.scatter(act_x,act_y,c='red')