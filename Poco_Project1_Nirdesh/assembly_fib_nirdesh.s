.data
input: .asciiz "Enter Non Negative integer number ::\n "      #store string to "input"
print1: .asciiz "F"                                           #store "F" to print1
print2: .asciiz " = "                                          #store "=" to print2
newLine: .asciiz "\n"
endPrint: .asciiz "Thank you for running this program\n"         #store end message to endPrint

.text
main:
	addi $t0,0      # x=0 stored in t0 
	addi $t1,1       #y=1 stored in t1 
	addi $t2,0        #counter =0 stored in t2 

    la $a0,input      # Load  prompt to memory
    li $v0,4          #Prepare to print something 4 = string
    syscall           #Print the prompt to Ask user to input non negative number

    li $v0,5    #Read input number n.    
    syscall

    move $t3,$v0    # store n in t3 .

    	loop: 

    		bgt $t2,$t3,exit      #if (counter > n) then branch to "exit", else run code

    				#Print "F 		
    		la $a0,print1          #load print1 saved in data to memory 
   		    li $v0,4			   #Prepare to print
    		syscall					#Execute system call to print

    			    #Print  counter
    		move $a0,$t2           #Copy from $t2 register to $a0 register
     		li $v0,1               # 1 = integer
    		syscall					#operating system routine call

    				#Print "="
    		la $a0,print2            #load data into $a0
    		li $v0,4                # 4 = string to be printerd 
    		syscall                  #operating system routine call

    				#Print x (Fib sum so far)
    		move $a0,$t0            #move x in $t0 to register $a0
     		li $v0,1                #prepare to print 1 = string
    		syscall                   #execute system call to print

    				#Print "/n" for new line
    		la $a0,newLine         #move data to register
    		li $v0,4				#prepare to print string 
    		syscall					#execute system call to print



    		add $t4,$t0,$t1    #z = x +y 
    		move $t0,$t1       #x = y 
    		move $t1,$t4     #y = z 



    		add $t2,$t2,1       #counter++ 

    		j loop  			#if loop didn't end go to top (loop:)


    	exit: 
    						#Print "Thank you for running this program\n"
    	    la $a0,endPrint  
   		    li $v0,4           #print loaded message 4 = string 
    		syscall              #execute system call 

    		li $v0,10          #10 = exit, prepare to quit
    		syscall             #exit program 
