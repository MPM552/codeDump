Name: Matthew Mitchell
Date: Created 2-2020 Last Edit: 2-2020
Assignment: CS315 Programming Assignment: Trees
Purpose: Trees is a program that makes and utilizes two binary trees. The user 
first inputs the number of points, n, for each tree. The points are then given
an x, y, and z value from randGen.pl. The first tree T1 is sorted by the X 
value and is printed in symmetric order in the format: (x, y, z). T1 is then 
traversed in preorder and each node visited is placed in the second tree(T2) 
sorted on the y value. All ties in both T1 and T2 are resolved by going to the 
left. T2 is then traversed and each point is printed. Lastly, a random y value 
is chosen by randGen.pl. T2 is then searched for the point. If the y value is 
found, the point is printed. If it isn't found, the last node visited is 
printed. If the tree has zero elements, the program prints: "Tree is empty." 
 
Program Notes: The one command line argument for this program is the number of
elements in the tree, which must be an integer zero or greater. Typing 
"make run" will run the program and give n lines of points for each of the two 
trees, first in symmetric order and second in post order, plus one line for the
 search function. To run the program with custom element and seed:
./randGen.pl seed | ./trees elements 
Be sure that the number of elements is 0 or greater, otherwise the program
will not run.

altMain Notes: The altMain is essentially the same program as the main except 
it allows the user to input all data for each element of the tree, no negatives
allowed, and the probe value. In order to run it the user should type 
"run altTrees."

 
