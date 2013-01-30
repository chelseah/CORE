#!/usr/bin/env python
import os
import datetime as dt
import numpy as np
import scipy as sp
def gen_observable(infile,newpara):
    fin = open(infile,mode='r')
    key = []
    value = []
    for line in fin.readlines():
        if (not line.startswith('#')):
            tempkey,tempvalue=line.rstrip().split('=')
            key.append(tempkey.strip())
            value.append(tempvalue.strip())    
    fin.close()
    para_dic=dict(zip(key,value))
    for key,value in newpara.items():
        print key,value
        if(key in para_dic):
            print key,value
            para_dic[key]=value
    outfile = 'observable.h'
    fout = open(outfile,mode='w')
    fout.write('#ifndef OBSERBABLE_H\n')
    fout.write('#define OBSERBABLE_H\n')
    for name,value in para_dic.items():
        line='#define %s %s\n' % (name,value)
        fout.write(line)
    fout.write('#endif\n')
    fout.close()
    return 

def main():
    now = str(dt.datetime.utcnow())
    infile = 'observable_example.txt'
    vcarray = np.linesapce(0.5,2,10)
    perturb = ['vc']
    #vcarray = np.array([1.5e3])
    for vc in vcarray: 
      timestamp = now.split()[0]+'-'+'-'.join(now.split()[1].split(":")[0:2])
      newpara = dict(zip(perturb,[vc]))
      gen_observable(infile,newpara)
    #print './core %s' % timestamp
      os.system('Make clean')
      os.system('Make')
      os.system('./core %s' % timestamp)
if __name__=='__main__':
    main()
