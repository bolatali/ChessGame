#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "ChessElement.h"
using namespace std;


float calculateScore(vector <ChessElement>& chessElements, string colour)
{
    float score_black = 0;

    for (int i = 0; i < chessElements.size(); ++i) 
    {
        if (chessElements[i].getColour() == colour) 
        {
            score_black += chessElements[i].getPoint();
        }
    }

    return score_black;
}


void setPiecesProperty(vector <Kale>& kaleElements, vector <Piyon>& piyonElements, vector <Horse>& horseElements, vector <ChessElement>& chessElements, map<char, int>piecesVal)
{
    ifstream readFile;
    readFile.open("board4.txt");
    string frame;

    int count = 0;
    string colour;

    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            readFile >> frame;
            if (frame != "--") 
            {

                if (frame[1] == 's') 
                {
                    colour = "black";
                }else 
                {
                    colour = "white";
                }


                if (frame[0] == 'a') 
                {
                    horseElements.push_back(Horse(colour, "at", piecesVal[frame[0]], j + 1, i + 1));

                }else if (frame[0] == 'p') 
                {
                    piyonElements.push_back(Piyon(colour, "piyon", piecesVal[frame[0]], j + 1, i + 1));
                }
                else if (frame[0] == 'k') 
                {
                    kaleElements.push_back(Kale(colour, "kale", piecesVal[frame[0]], j + 1, i + 1));
                }

                

                chessElements.push_back(ChessElement(colour, frame, piecesVal[frame[0]], j + 1, i + 1));


            }
        }

    }
}




int main()
{
    vector <ChessElement> chessElements; // dinamik bir sekilde nesne olusturmak icin vector kullandim.
    vector <Horse> horseElements;
    vector <Piyon> piyonElements;
    vector <Kale> kaleElements;

    string str[8][8];
    map<char, int> piecesVal;
    piecesVal = { {'p',1},{'a',3},{'f',3},{'k',5},{'v',9},{'s',100} };


    string black = "black";
    string white = "white";
    int score_black = 0;
    int score_white = 0;


    setPiecesProperty(kaleElements, piyonElements , horseElements, chessElements, piecesVal); 


    score_black = calculateScore(chessElements, black);
    score_white = calculateScore(chessElements, white);

    cout << "score of black: " << score_black << endl;
    cout << "score of white: " << score_white << endl;

    kaleElements[0].move(chessElements);
    chessElements[3].displayProperty();
    
    return 0;
}
