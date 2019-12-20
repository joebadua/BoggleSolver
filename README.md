# Boggle Solver - C++
Boggle is a game that involves a 4x4 alphabet-lettered-dice grid. The grid is randomized, and the player searches for English words in adjacencies. Program shows all possible combinations of words, and demonstrates a step-by-step process on how to find the word.

Dictionary.txt is filled with 45k+ words that the program refers to when checking the board for English words.

Output.txt is an example of a written output by the program, showing the step-by-step process of finding each possible word.

## How does it work?

### Storing Each Word
The Dictionary.h file creates a tree data structure where each level corresponds to a character of a dictionary word. A single node in a tree holds an array arr[] of pointers that correspond to 23 letters of the alphabet, and a boolean flag determining whether or not it is a prefix/word. Take a look at the addWord function:
```C++
void Dictionary::addWord(string word) // a string from Dictionary.txt
{
    currNode = root; // start at the root
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a'; // index is holding the alphabetical position
                                             // of a single character of word 
                                             // (i.e A is 0, B is 1, C is 2...)  
        if(currNode->arr[index] == NULL) {   
            currNode->arr[index] = new Node; // make a new node pointing to the corresponding letter in array
            (currNode->arr[index])->flag = false; // set false since we're not done itereting through word
        }
        
        currNode = currNode->arr[index]; // next node
    }
    
    currNode->flag = true; // we have iterated through each character of the word
    numWords++;            // therefore, set the boolean to true to define as a word
}
```
It is a lot more efficient to store character-by-character rather than an entire string. With this, the program will a fast lookup time of O(n). For instance, the largest possible amount of characters a string could have as a word is 23 (corresponding to 23 characters in an alphabet). This means we will only have 23 comparisons. 

### Searching through the tree
In main.cpp, SolveBoard is what starts the searching. The Boggle board is a 4x4 char array. 
```C++
void SolveBoard(char board[][4],int steps[][4], Dictionary& dict, Dictionary& wordsFound, bool printBoard)
{
...
for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
       SearchForWord(r, c, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    }
...
}
```
Here, it goes through each row/column as a starting index for the function SearchForWord.

Search for word does a lot of recursion.
```C++
void SearchForWord(int row, int col, Dictionary dict, Dictionary wordsFound, char board[][4], int steps[][4], int numofsteps, string currPrefix, bool printBoard, ofstream& output)
{
...
    SearchForWord(row , col - 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row , col + 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row - 1 , col, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row + 1 , col, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row + 1 , col + 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row + 1 , col - 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row - 1 , col + 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row - 1 , col - 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
...
}
```
After passing its test cases that determine whether or not its a word/prefix, from the starting index, it goes through ALL possible rows/columns from the starting index.

### How it looks

Here's a small example of how the above is working on a higher level:

Let's say we have the Boggle board:
```
a b c d 
a s d f 
q w e r 
y h f t 
```
Running this through the program would give us:
```
0: abase
a b c d 
a s d f 
q w e r 
y h f t 

1 2 0 0 
3 4 0 0 
0 0 5 0 
0 0 0 0 
--------
1: abaser
a b c d 
a s d f 
q w e r 
y h f t 

1 2 0 0 
3 4 0 0 
0 0 5 6 
0 0 0 0 
--------
3: abased
a b c d 
a s d f 
q w e r 
y h f t 

1 2 0 0 
3 4 6 0 
0 0 5 0 
0 0 0 0 
```
It returns the word found, the board, and an indexed version of the board displaying how to find the word.



