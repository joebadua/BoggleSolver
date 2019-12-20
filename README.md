# Boggle Solver - C++
Boggle is a game that involves a 4x4 alphabet-lettered-dice grid. The grid is randomized, and the player searches for English words in adjacencies. Program shows all possible combinations of words, and demonstrates a step-by-step process on how to find the word.

```C++
Node* currNode = root; 
		for(int i = 0; i < (int)word.size(); i++){
			int index = (int)word[i] - (int)'a';	
			if(currNode->arr[index] == NULL){
				currNode->arr[index] = new Node;
			}				
			currNode = currNode->arr[index];
		}
 ```
Dictionary.txt is a library that the program refers to when checking the board for English words.

Output.txt is an example of a written output by the program, showing the step-by-step process of finding each possible word.
