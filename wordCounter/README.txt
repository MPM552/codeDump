Name: Matthew Mitchell
Date: 4-2020 Last Edit: 4-2020

Programming Assignment 4: Word Counter

Purpose: Add every word, any contiguous set of non-space characters, from a 
text file and create two outputs with them. Each output contains the number
of times a certain string appears in the text file and the string itself. 
The first sort is done alphabetically, and the second sort is done numerically,
based on the number of times the string is seen.

Program Notes: As stated before, each word will contain non-space characters. 
This will include punctuation and integers. In order to run the program, the 
user should type "make run" into console. This will print both sorts into 
standard output. If you want to sort your own text file, paste it into
text.txt then run the same as before.

altMain Notes: To run type "make runAlt" into console. The first stat printed 
is the number of comparisons made to insert a node into the hash table. The
second list of stats is the number of nodes in each external chain for every
element of the table. After printing each node in alphabetical order, the 
number of comparisons made for the alpha Quicksort algorithm is printed. The
same is done after the numerical print. The last stat is both numbers added
together for total Quicksort comparisons made.

References: I used GeeksForGeeks for my quick sort algorithm and partition. 
Everything else is original content.
