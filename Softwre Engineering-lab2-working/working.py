
from algorithms.sorting import quick_sort_in_place
from algorithms.sorting import quick_sort
import time, random, sys, glob, os, copy
import datetime as dt
import time

sys.setrecursionlimit(15000)


# ------------------------------------------------Optimized number generator for different cases ----------------------------------------------------#
def number_generator(size, case):

    # Open a file

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

def number_generator_2(size):
    # Open a file
    file = open("dataFiles/"+str(size)+".dat", "w")

    # Generating random numbers
    for i in range(1,size+2):
        no = i
        # Writing random numbers in the file
        file.write(str(no) +" \n") 
        

    # Close opend file
    file.close()


# ------------------------------------------------To Create sorted Output file ----------------------------------------------------#


def writeList(list,name):

    finalName = "sorted_" + name
    file = open("sorted/"+finalName, "w")

    for i in list:
        file.write(str(i) +" \n")                    

    file.close()


# ------------------------------------------------ Extract Data  ----------------------------------------------------#



def read_filenum(file):
    tempList=[]
    tempCounter = 0
    for line in file:
        line = line.strip()
        blist = line.split()
        blist = [int(i) for i in blist]
        tempList.extend(blist)
        tempCounter = tempCounter +1 
    print("Number of integers = ", tempCounter )
    return tempList, tempCounter


# ------------------------------------------------Main code ----------------------------------------------------#



#inputFile = i

#number_generator(1000)
#number_generator(10000)
#number_generator(100000)

path = 'dataFiles'
os.mkdir('sorted')
logfile = open("logfile.txt", "a")

for i in range(0,2):

	size = input("What size do you want your test array? pick between 0 - 10k ")
	case = input("Pick: (same integers, ordered<worst> integers:: :(same/ordered/random))?? ")
	number_generator(int(size), case)







for fileName in glob.glob(os.path.join(path, '*.dat')):
#for fileName in glob.glob('*.dat'):

	file2 =[] 
	final = []
	file1 = open(fileName,'r')
	file2,counter = read_filenum(file1) 


	start = time.time()
	final = quick_sort.sort(file2)
	runTime = (time.time()-start)
	print(fileName)
	writeList(final,fileName[10:])

	print("Time taken:::  \t\t\t", runTime, "seconds")
	record = (fileName[10:] + "No of Integers:: \t" + str(counter)+ "\t Time taken::: \t" + str(runTime) + "\tseconds\t" )
	print("\nSPEED WAS:::  \n", runTime/float(counter))

	#logfile = open("logfile.txt", "w")
	with open("logfile.txt", "a") as f: 
		f.write(record + '\n')	
	

	file1.close()
f.close()