#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 26;
const int MAX_ROW = 4;
const int MAX_COL = 4;

struct Node {
	Node *arr[MAX];
	bool flag;

	Node() {
		for(int i = 0; i < MAX; i++) 
			arr[i] = NULL;	 
	}
};

class Dictionary { 
public:
	Dictionary();
	Dictionary(string file);
	void addWord(string word);
	bool isWord(string word);
	bool isPrefix(string word);
	void PrintWords(string prefix);
	void PrintHelper(Node *startNode, string prefix);
	int wordCount();

private:
	Node *root;
	Node *currNode;

	int numWords;
};
























