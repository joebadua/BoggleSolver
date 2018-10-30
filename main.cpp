#include "dictionary.h"

int numofwords = 0;

void SolveBoard(char board[][4],int steps[][4], Dictionary& dict, Dictionary& wordsFound, bool printBoard);
void SearchForWord(int row, int col, Dictionary dict, Dictionary wordsFound, char board[][4], int steps[][4], int numofsteps, string currPrefix, bool printBoard, ofstream& output);
void printSteps(char board[][4], int steps[][4], ofstream& output);

int main()
{
    string input;

    char board[4][4];
    int steps[4][4];
    
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            steps[r][c] = 0;
        }
    }
    
    Dictionary dict("Dictionary.txt");
    cout << dict.wordCount() << " words loaded." << endl;
    
    cout << "Enter board (no spaces)" << endl;
    cout << "-----------------------" << endl;
    
    for(int r = 0 ; r < 4; r++){
        cout << "Row " << r << ": " << endl;
        cin >> input;
        for(int c = 0; c  < input.length(); c++)
            board[r][c] = input[c];
    }
    cout << "-----------------------" << endl;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
  
    Dictionary wordsFound;
    SolveBoard(board, steps, dict, wordsFound, true);
    
    return 0;
}

void SolveBoard(char board[][4],int steps[][4], Dictionary& dict, Dictionary& wordsFound, bool printBoard)
{
    string currPrefix;
    int numofsteps = 0;
    string output_file = "output.txt";
   
    ofstream output(output_file);
    if(!output)
        cout << "Error opening output file." << endl;
    
    char input;
    cout << "Show the board? (y/n): " << endl;
    cin >> input;
    
    if(input == 'y')
        printBoard = true;
    
    else if(input == 'n')
        printBoard = false;
    
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            SearchForWord(r, c, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
        }
    }
    
    cout << "Output has been written on " << output_file << endl;
}

void SearchForWord(int row, int col, Dictionary dict, Dictionary wordsFound, char board[][4], int steps[][4], int numofsteps, string currPrefix, bool printBoard, ofstream& output)
{
    if(row >= MAX_ROW || col >= MAX_COL)
        return;
    
    if(row < 0 || col < 0)
        return;
    
    if(steps[row][col] != 0)
        return;
    
    if(!dict.isPrefix(currPrefix))
        return;
    
    if(dict.isWord(currPrefix)) {
        if(!wordsFound.isWord(currPrefix)) {
            if(!printBoard) {
                wordsFound.addWord(currPrefix);
                cout << ++numofwords << ": " << currPrefix << endl;
                output << numofwords << ": " << currPrefix << endl;
            }
            else {
                wordsFound.addWord(currPrefix);
                cout << ++numofwords << ": " << currPrefix << endl;
                output << numofwords << ": " << currPrefix << endl;
                printSteps(board, steps, output);
            }
        }
    }
    
    currPrefix = currPrefix + board[row][col];
    steps[row][col] = ++numofsteps;
    
    SearchForWord(row , col - 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row , col + 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row - 1 , col, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row + 1 , col, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row + 1 , col + 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row + 1 , col - 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row - 1 , col + 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    SearchForWord(row - 1 , col - 1, dict, wordsFound, board, steps, numofsteps, currPrefix, printBoard, output);
    
    steps[row][col] = 0;
}

void printSteps(char board[][4], int steps[][4], ofstream& output)
{
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cout << board[r][c] << " ";
            output << board[r][c] << " ";
        }
        cout << endl;
        output << endl;
    }
    cout << endl;
    output << endl;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cout << steps[r][c] << " ";
            output << steps[r][c] << " ";
        }
        cout << endl;
        output << endl;
    }
    cout << "---------" << endl;
    output << "--------" << endl;
}




