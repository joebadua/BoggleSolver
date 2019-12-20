# Boggle Solver - C++
Boggle is a game that involves a 4x4 alphabet-lettered-dice grid. The grid is randomized, and the player searches for English words in adjacencies. Program shows all possible combinations of words, and demonstrates a step-by-step process on how to find the word.

Dictionary.txt is filled with 45k+ words that the program refers to when checking the board for English words.

Output.txt is an example of a written output by the program, showing the step-by-step process of finding each possible word.

## How does it work?
The Dictionary header class creates a tree data structure where each level corresponds to a character of a dictionary word. A single node in a tree holds an array arr[] of pointers that correspond to 23 letters of the alphabet, and a boolean flag determining whether or not it is a prefix/word. Take a look at the addWord function:
```C++
void Dictionary::addWord(string word) // a string from Dictionary.txt
{
    currNode = root; // start at the root
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a'; // index is holding the alphabetical position
                                             // of a single char of word 
                                             // (i.e A is 0, B is 1, C is 2, so forth)   
        if(currNode->arr[index] == NULL) {  
            currNode->arr[index] = new Node; 
            (currNode->arr[index])->flag = false;
        }
        
        currNode = currNode->arr[index];
    }
    
    currNode->flag = true;
    numWords++;
}
```

