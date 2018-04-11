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


def read_file(file):
    tempList=[]
    tempCounter = 0
    for line in file:
        line = line.strip()
        splitList = line.split()
        splitLlist = [int(i) for i in splitList]
        tempList.extend(splitList)
        tempCounter = tempCounter +1 
    #print("Number of integers = ", tempCounter )
    return tempList, tempCounter





# ------------------------------------------------Main code ----------------------------------------------------#


#Initialize by opening required directories 

path = 'dataFiles'

os.mkdir('sorted')
logFile = open("logfile.txt", "a")
logFormat = ("INPUT FILE \t\t No of Integers \t\t TIME MEASUREMENTS \n")

#with open("logfile.txt", "a") as log:
logFile.write(logFormat + '\n')


#test cases
for i in range(0,2):

	size = input("What size do you want your test array? pick between 0 - 10k if not random ")
	case = input("Pick: (same integers, ordered<worst> integers:: :(same/ordered/random))?? ")
	number_generator(int(size), case)




#To read all files in directory

for fileName in glob.glob(os.path.join(path, '*.dat')):

	workingList=[] 
	sortedList = []
	

	inputFile = open(fileName,'r')
	workingList,counter = read_file(inputFile) 


	

	start = time.time()
	sortedList = quick_sort.sort(workingList)
	runTime = (time.time()-start)

	print(fileName,";;;;;;",runTime, "\n")

	#logFile.write('\t\t\t\t'+ str( '%.5f' % averageTime) + '\n')


	write_list(sortedList,fileName[10:])
	

	print("Time taken:::  \t\t\t", runTime, "seconds")
	#record = (fileName[10:] + "No of Integers:: \t" + str(counter)+ "\t Time taken::: \t" + str(averageTime) + "seconds\n" )
	record = (fileName[10:] + "\t\t" + str(counter)+ "\t\t" + str("%.5f" % runTime) + "sec" )
	#print("\nSPEED WAS::: ", runTime/float(counter), "\n")
 
	logFile.write(record + '\n')	
	inputFile.close()
logFile.close()