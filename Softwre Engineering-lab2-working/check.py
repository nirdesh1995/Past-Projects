
from algorithms.sorting import quick_sort
import time, random, sys, glob, os, copy
import datetime as dt
import time



def read_filenum(file):
    alist=[]
    for line in file:
        line = line.strip()
        blist = line.split()
        blist = [int(i) for i in blist]
        alist.extend(blist)
    return alist



path = 'dataFiles_2'


for fileName in glob.glob(os.path.join(path, '*.dat')):

	
	sortedList = []

	file1 = open(fileName,'r')
	list1 = read_filenum(file1) 

	print(list1)

	start = time.time()
	sortedList = quick_sort.sort(list1)
	print(sortedList)