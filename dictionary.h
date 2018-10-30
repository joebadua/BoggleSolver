#include "header.h"

Dictionary::Dictionary()
{
    root = new Node;
    root->flag = false;
    numWords = 0;
}

Dictionary::Dictionary(string file)
{
    root = new Node;
    root->flag = false;
    numWords = 0;
    
    ifstream input(file);
    string word;
    
    if(!input) {
        cout << "Error readiing file" << endl;
        return;
    }
    
    while(input >> word)
        addWord(word);
    
    input.close();
}

void Dictionary::addWord(string word)
{
    currNode = root;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
        
        if(currNode->arr[index] == NULL) {
            currNode->arr[index] = new Node;
            (currNode->arr[index])->flag = false;
        }
        
        currNode = currNode->arr[index];
    }
    
    currNode->flag = true;
    numWords++;
}


bool Dictionary::isWord(string word)
{
    currNode = root;
    bool isWord = false;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
  
        if(currNode->arr[index] == NULL)
            return false;
        
        isWord = currNode->arr[index]->flag;
        currNode = currNode->arr[index];
        
    }
    
    return isWord;
}



bool Dictionary::isPrefix(string word)
{
    currNode = root;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
        
        if(currNode->arr[index] == NULL)
            return false;
        
        currNode = currNode->arr[index];
    }
    
    return true;
}

void Dictionary::PrintWords(string prefix)
{
    currNode = root;
    
    for(int i = 0; i < prefix.length(); i++) {
        
        int index = (int)prefix[i] - (int)'a';
        
        currNode = currNode->arr[index];
    }
    
    for(int i = 0; i < 26; i++) {
        
        char letter = (int)'a' + i;
        
        PrintHelper(currNode->arr[i], prefix+letter);
    }
}


void Dictionary::PrintHelper(Node* startNode, string prefix)
{
    if(startNode == NULL)
        return;
    
    if(startNode->flag)
        cout << prefix << endl;
    
    for(int i = 0; i < 26; i++) {
        
        char letter = (int)'a' + i;
        
        PrintHelper(startNode->arr[i], prefix+letter);
    }
    
}

int Dictionary::wordCount()
{
    return numWords;
}













