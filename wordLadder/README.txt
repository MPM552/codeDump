Program Notes:
This program takes one text file of words as a command line arguement and
then asks a user to input two words. If both of the words are in the given
text file, the program finds the shortest path between the two words by 
looking for words that are different by a single letter than the given words.
This is done by creating a graph of related words and using BFS to find the 
shortest path between the two given words. If the words that are given do 
not exist in the text file, an invalid vertex error will show up and the user
will be prompted to enter two new words.

Example Run:
Please type the FIRST word (or type Enter to quit):
Tree
Please type the SECOND word (or type Enter to quit):
Fast
The ladder for tree to fast is 6 word(s) long.
A ladder from [tree] to [fast]:
tree ---> free ---> fret ---> feet ---> fest ---> fast

Running: Type make into console and then ./CS216PA3 words.txt
You can run custom text files as long as they are in this format:
Please
Type
Your
Words
Like 
This
 

