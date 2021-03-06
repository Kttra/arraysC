# 1-D/2-D/3-D Arrays
Making arrays of different dimensions in C++ and C. This is a program that shows how to create 1-D, 2-D, and 3-D arrays in C++. It's really important to make sure you understand how to free memory after the use of your array is over (especially in long running programs). Memory is a finite resource within your running program and eventually you may run out of that memory causing the program to crash.

This program also shows how to pass the arrays through functions, how to print out the arrays, and how to delete them after you are done.
Note that this program will not show how to print 3-D arrays or how to pass them to a function as looking at the 1-D and 2-D examples should give a good idea of how to do so.

Additionally, you may want to consider using a vector instead of an array (if you are coding in C++) as they function very similarly. Vectors are implemented as dynamic arrays with a list interface while arrays can be implemented both statically or dynamically. Vectors are much simpler to use.

```
The starting array: 1 2 3 7 
The array after passing it through a function: 7 2 3 7 

The 2D Board:
# # # # #
# # # # #
# # # # #
# # # # #

The 2D Board after passing through a function:
# # # # #
# # h # #
# # # # #
# # # # #
```
