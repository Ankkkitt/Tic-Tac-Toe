#include <bits/stdc++.h>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4','5', '6', '7', '8', '9'}; // global char array
int choice, player;   // global variable

int checkForWin(){
    //function to return status of game
    // 1 --> game is over with result
    // -1 -> game is in progress
    // 0 --> game is over with no result ( no one wins )
    int returnvalue = 0;
    if( square[1] == square[2] && square[2] == square[3] ){ // condition for horizontal wins
        returnvalue = 2;
    }else if(square[4]==square[5] && square[5]==square[6]){ // condition for horizontal wins
        returnvalue = 1;
    }else if(square[7]==square[8] && square[8]==square[9]){ // condition for horizontal wins
        returnvalue = 1;
    }else if(square[1]==square[4] && square[4]==square[7]){ // condition for vertical wins
        returnvalue = 1;
    }else if(square[2]==square[5] && square[5]==square[8]){ // condition for vertical wins
        returnvalue = 1;
    }else if(square[3]==square[6] && square[6]==square[9]){ // condition for vertical wins
        returnvalue = 1;
    }else if(square[1]==square[5] && square[5]==square[9]){ // condition for diagonal wins
        returnvalue = 1;
    }else if(square[3]==square[5] && square[5]==square[7]){ // condition for diagonal wins
        returnvalue = 1;
    }else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9'){  // condition to check that all th turns has been played and no one has win
        returnvalue = 0;
    }else{
        returnvalue = -1;
    }

    return returnvalue;
}

void displayBoard(){

    system("cls");
    // function to draw board to play tic - tac - toe
    cout<<"\n\n\tTic Tac Toe\n\n";
    cout<<"Player 1(X) - Player 2(O)\n\n\n";

    cout<<"     |     |     \n";
    cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<"  \n";
    cout<<"_____|_____|_____\n";

    cout<<"     |     |     \n";
    cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<"  \n";
    cout<<"_____|_____|_____\n";

    cout<<"     |     |     \n";
    cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<"  \n";
    cout<<"_____|_____|_____\n\n\n";
    
}

void markBoard(char mark){
    // Set the boar values with 'X' and 'O' according to participant 1 or 2
    if(choice==1 && square[1]=='1'){
        square[1] = mark;
    }else if(choice==2 && square[2]=='2'){
        square[2] = mark;
    }else if(choice==3 && square[3]=='3'){
        square[3] = mark;
    }else if(choice==4 && square[4]=='4'){
        square[4] = mark;
    }else if(choice==5 && square[5]=='5'){
        square[5] = mark;
    }else if(choice==6 && square[6]=='6'){
        square[6] = mark;
    }else if(choice==7 && square[7]=='7'){
        square[7] = mark;
    }else if(choice==8 && square[8]=='8'){
        square[8] = mark;
    }else if(choice==9 && square[9]=='9'){
        square[9] = mark;
    }else{
        cout<<"Invalid Move";
        player--;
    }
}

int main()
{
    int gamestatus;
    char mark;
    player = 1;
    do{
        displayBoard();    // display the game board 
        player = (player % 2)?1:2;  // changing turns i.e player 1 and 2
        
        cout<<"player "<<player<<", enter a number : ";    
        cin>>choice;                         // //get input
        mark = (player==1)?'X':'O';          // Set character according to players
        markBoard(mark);                     // Set board based on users choice - valid or invalid
        gamestatus = checkForWin(); 
        player++;
        
    } while( gamestatus == -1);

    if(gamestatus == 1){
        cout<<"\n  ==> player "<<player<<" wins \n\n";
    }else{
        cout<<" ==> Game Draw";
    }
    

    return 0;
}