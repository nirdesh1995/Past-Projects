


from algorithms.sorting import quick_sort_in_place
from algorithms.sorting import quick_sort
import time, random, sys, glob, os, copy
import datetime as dt
import time

sys.setrecursionlimit(15000)


# ------------------------------------------------Optimized number generator for different cases ----------------------------------------------------#
def number_generator(size, case):

    file = open("dataFiles/"+str(size)+case+".dat", "w")

    if case == "same": 
        for i in range(size):
        	no = 100
        	file.write(str(no) +" \n")  


    elif case == "random":
    	for i in range(size):
        	no = random.randrange(1,1000,1)
        	file.write(str(no) +" \n")     


    elif case == "ordered":
        #name ="_SelectionSort.txt"
        for i in range(size):
        	no = i
        	file.write(str(no) +" \n") 

    file.close()


# ------------------------------------------------To Create sorted Output file ----------------------------------------------------#

def write_list(list,name):

    finalName = "sorted_" + name
    file = open("sorted/"+finalName, "w")

    for i in list:
        file.write(str(i) +" \n")                    
    file.close()


# ------------------------------------------------ Extract Data  ----------------------------------------------------#



def read_filenum(file):
    alist=[]
    for line in file:
        line = line.strip()
        blist = line.split()
        blist = [int(i) for i in blist]
        alist.extend(blist)
    return alist





# ------------------------------------------------Main code ----------------------------------------------------#


#Initialize by opening required directories 

path = 'dataFiles'
os.mkdir('sorted')
logFile = open("logfile.txt", "a")

logFormat = ("INPUT FILE \t\t No of Integers \t\t TIME MEASUREMENTS \t\t Intergers/sec")
logFile.write(logFormat + '\n')

#test cases
#for i in range(0,2):

	#size = input("What size do you want your test array? pick between 0 - 10k if not random ")
	#case = input("Pick: (same integers, ordered<worst> integers:: :(same/ordered/random))?? ")
number_generator(10000, "ordered")




#To read all files in directory

for fileName in glob.glob(os.path.join(path, '*.dat')):

	sortedList = []

	file1 = open(fileName,'r')
	file2 = read_filenum(file1)
	emptyList = file2
	counter = len(emptyList)
		


	start = time.time()
	sortedList = quick_sort.sort(emptyList)
	runTime = (time.time()-start)

	print(fileName)
	write_list(sortedList,fileName[10:])

	print("Time taken:::  \t\t\t", runTime, "seconds")
	speed = str(float(counter)/runTime)
	record = (fileName[10:] + "\t\t" + str(counter)+ "\t\t" + str("%.5f" %runTime) + "sec" + speed)
	#record = (fileName[10:] + "No of Integers:: \t" + str(counter)+ "\t Time taken::: \t" + str(runTime) + "\tseco\t" + )
	print("\nSPEED WAS:::  \n", runTime/float(counter))

	#logfile = open("logfile.txt", "w")

	
	logFile.write(record + '\n')	
	
	file1.close()
logFile.close()