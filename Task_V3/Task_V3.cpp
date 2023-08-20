#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "ChessElement.h"
using namespace std;


float calculateScore(vector <ChessElement>& chessElements, string colour)
{
    float total_score = 0;

    for (int i = 0; i < chessElements.size(); ++i) 
    {
        if (chessElements[i].getColour() == colour) 
        {
            total_score += chessElements[i].getPoint();
        }
    }

    return total_score;
}


void setPiecesProperty(vector <Rook>& rookElements, vector <Pawn>& pawnElements, vector <Horse>& horseElements, vector <ChessElement>& chessElements, map<char, int>piecesVal, string board[8][8])
{
    ifstream readFile;
    readFile.open("board2.txt");  // okunacak txt dosyasinin adi girilmelidir.
    string frame;

    int count = 0;
    string colour;

    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            readFile >> frame;
            board[i][j] = frame;
            if (frame != "--") 
            {

                if (frame[1] == 's') //ikinci indexi hangi renk oldugunu belirtir.
                {
                    colour = "black";
                }else 
                {
                    colour = "white";
                }


                if (frame[0] == 'a') //ilk indexi hangi tip tas oldugunu belirtir
                {
                    horseElements.push_back(Horse(colour, "horse", piecesVal[frame[0]], j + 1, i + 1));

                }else if (frame[0] == 'p') 
                {
                    pawnElements.push_back(Pawn(colour, "pawn", piecesVal[frame[0]], j + 1, i + 1));
                }
                else if (frame[0] == 'k') 
                {
                    rookElements.push_back(Rook(colour, "rook", piecesVal[frame[0]], j + 1, i + 1));
                }

                

                chessElements.push_back(ChessElement(colour, frame, piecesVal[frame[0]], j + 1, i + 1));


            }

        }
    }
}

void startGame(vector <Rook>& rookElements, vector <Pawn>& pawnElements, vector <Horse>& horseElements, vector <ChessElement>& chessElements, string board[8][8])
{
    string piece;
    int horse_counter = 0;
    int pawn_counter = 0;
    int kale_counter = 0;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            piece = board[i][j];
            if (piece != "--")
            {
                if (piece[0] == 'a')
                {  
                    horseElements[horse_counter].move(chessElements); // boarddaki tas at ise at hamlesini yapar.
                    horse_counter++; // bir sonraki at tasi geldiginde sonraki at nesnesini caigrmak icin indexi counterda tutuldu. 
                }else if(piece[0] == 'p')
                {
                    pawnElements[pawn_counter].move(chessElements); // boarddaki tas piyon ise piyon hamlesini yapar.
                    pawn_counter++; // bir sonraki piyon tasi geldiginde sonraki piyon nesnesini caigrmak icin indexi counterda tutuldu.
                }
                else if (piece[0] == 'k')
                {
                    rookElements[kale_counter].move(chessElements); // boarddaki tas kale ise kale hamlesini yapar.
                    kale_counter++; // bir sonraki kale tasi geldiginde sonraki kale nesnesini caigrmak icin indexi counterda tutuldu.
                }
            }
        }
    }
}


int main()
{
    vector <ChessElement> chessElements; 
    vector <Horse> horseElements;
    vector <Pawn> pawnElements;
    vector <Rook> rookElements;

    
    map<char, int> piecesVal;
    piecesVal = { {'p',1},{'a',3},{'f',3},{'k',5},{'v',9},{'s',100} };

    string board[8][8];
    string black = "black";
    string white = "white";
    float score_black = 0 ;
    float score_white = 0;


    setPiecesProperty(rookElements, pawnElements , horseElements, chessElements, piecesVal, board); 

    
    score_black = calculateScore(chessElements, black);
    score_white = calculateScore(chessElements, white);
    cout << "Baslangic skorlari-> siyah tas: " << score_black << "  beyaz tas: " << score_white<<endl;
    

    
    startGame(rookElements,pawnElements, horseElements, chessElements,board); // boarddaki tum taslari gezip move fonksiyonunu cagirir.
    

    score_black = calculateScore(chessElements, black);
    score_white = calculateScore(chessElements, white);
    cout << "Bitis skorlari-> siyah tas: " << score_black << "  beyaz tas: " << score_white << endl;
    
    
    

    return 0;
}
