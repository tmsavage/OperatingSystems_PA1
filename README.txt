Assignment: Programming Assignment 1
Name: Toby Maxime Savage
Email: tosa5156@colorado.edu


###### FILES ######
1) ./arch/x86/kernel/cs3753_add.c
This file contains the kernel code. It takes in three parameters: two int variables (num1 and num2), and a int pointer (*result). The program first initializes a variable 'sum'. The first print function prints the two input integer values that will be summed together as a kernel message. The two numbers are then added together. The following line copies the value from sum to result in the size of an int, using the copy_to_user function ignorer to save the sum value into the 'result' pointer. Lastly, we have another printk function that prints the solution as a kernel message.

2) ./arch/x86/kernel/Makefile
Near the very bottom of this file, before the 64 bit specific files, you will find the two 'obj' declarations for the two kernel calls produced in this assignment. You should see 'obj-y+=helloworld.o' & 'obj-y+=cs3753_add.o' simultaneously. 

3) ./arch/x86/entry/syscalls/syscall_64.tbl
This file is the system table of the kernel. At the very bottom of the 64-bit system call numbers section, you will find row numbers 333 and 334. These two entries belong with the system calls we are creating. Number 333 goes with sys_helloworld, and 334 goes with cs3753_add.


4) ./include/linux/syscalls.h
At the very bottom of this system call header file, directly above the #endif, you will find the two rows for the system calls we are creating. The second to last line goes along the sys_helloworld system call, which doesn't take any parameters, so 'void' is appropriate within the (). For the last row, we have the declaration of cs3753_add, which takes in three parameters explained above.


5) ./cs3753_add_User.c
This is the user test program which tests the system call cs3753_add(). In this document, I use the 'malloc' function, which takes in the number of bits for data type 'int'. The goal here is to allocate dynamic memory space for an int value. By default, malloc() returns a 'void' pointer, so (int*) casts it to an int pointer for the 'result' int pointer. On the second line, the syscall() function calls the cs3753_add function, id = 334, with mock parameters 5, 10, and the result pointer. The third line prints the returnCode variable to see if the system call function worked (0 = passed, -1 = failed), and the result of the function, in this case 15. On the fourth line, the free() function is required to deallocate the dynamic memory we initially allocated at the beginning of the main function since the programming language C does not perform this automatically. Note: the dynamically memory is allocated/deallocated in the Heal, not stack. 


1) Locate to directory ./home/kernel/linux-hwe-4.15.0

2) Save the files within this zip file into the associated directories described above in the ###### FILES ###### section.

3) Type command 'gcc -o cs3753_add cs3753_add.c' to compile the user space program

4) Type command './cs3753_add' to run the compiled program
	NOTE: you will see the results of the system call on the next line

5) Type 'dmesg' to see the logs of the system call. You will find "Two Numbers:" with the results, and "Summation of Two Numbers:". If you see these two statements, the cs3753_add system called worked accordingly. NOTE: The results of these two rows will be highlighted in bright red.