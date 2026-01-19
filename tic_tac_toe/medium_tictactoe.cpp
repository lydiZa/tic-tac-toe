#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};


//print sample grid
void sample(){
    int count =1;
    std::cout << count++ << " |" << ' ' << count++ << ' ' << "| " << count++ << endl;
    for(int i =0;i<2;i++){
        std::cout << "---------"<< endl;
        for(int j=0;j<1;j++){
            std::cout << count++ << " |" << ' ' << count++ << ' ' << "| " << count++ << endl;
        }
    }
    std::cout << endl;
}

void check_place(int &row, int &col, int &grid_num){
    if(grid_num == 1 || grid_num == 2 || grid_num ==3){
        row = 0;
    }else if(grid_num == 4 || grid_num == 5 || grid_num == 6){
        row = 1;
    }else if(grid_num == 7 || grid_num == 8 || grid_num == 9){
        row = 2;
    }
 
    if(grid_num == 1 || grid_num == 4 || grid_num == 7){
        col = 0;
    }
    else if(grid_num == 2 || grid_num == 5 || grid_num ==8){
        col = 1;
    }
    else if(grid_num == 3 || grid_num == 6 || grid_num ==9){
        col = 2;
    }
}

void display(){
     std::cout << board[0][0] << " |" << ' ' << board[0][1] << ' ' << "| " << board[0][2] << endl;
     std::cout << "---------"<< endl;
     std::cout << board[1][0] << " |" << ' ' << board[1][1] << ' ' << "| " << board[1][2] << endl;
     std::cout << "---------"<< endl;
     std::cout << board[2][0] << " |" << ' ' << board[2][1] << ' ' << "| " << board[2][2] << endl;

     std::cout << endl;
}

void who_won(int &win){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){win = 1;}
            if(grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]){win = 1;}
            if(i==j && grid[i][j]==grid[i+1][j+1] && grid[i+1][j+1]== grid[i+2][j+2]){win =1;}
            if(i==j && grid[i][j]==grid[i+1][j+1] && grid[i+1][j+1]== grid[i+2][j+2]){win =1;}
            if(grid[0][2] == grid[2][0] && grid[0][2]== grid[1][1] && grid[2][0]== grid[1][1]){win=1;} 
        }
    } 
}

void close_to_win(int &row, int &col){
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //2 in same row 
            if(grid[i][0] == grid[i][1] && board[i][2] == ' '){row = i; col =2; return;}
            if(grid[i][0] == grid[i][2] && board[i][1] == ' '){row = i; col =1; return;}
            if(grid[i][1] == grid[i][2] && board[i][0] == ' '){row = i; col =0; return;}
            //2 in same col
            if(grid[0][j] == grid[1][j] && board[2][j] == ' '){col = j; row=2; return;}
            if(grid[0][j] == grid[2][j] && board[1][j] == ' '){col = j; row=1; return;}
            if(grid[1][j] == grid[2][j] && board[0][j] == ' '){col = j; row=0; return;}
            //2 in same diagonal (\)
            if(i==j && grid[i][j]==grid[i+1][j+1] && board[i+2][j+2]==' '){row = i+2; col =j+2; return;}
            if(i==j && grid[i][j]==grid[i+2][j+2] && board[i+1][j+1] == ' '){row = i+1; col =j+1; return;}
            if(i==j && grid[i+1][j+1]==grid[i+2][j+2] && board[i][j] == ' '){row = i; col =j; return;}

            //2 in same other diagonal (/)
            if(grid[0][2] == grid[2][0] && board[1][1]==' '){row=1; col=1; return;}
            if(grid[0][2] == grid[1][1] && board[2][0]==' '){row=2; col=0; return;} 
            if(grid[1][1] == grid[2][0] && board[0][2]==' '){row=0; col=2; return;} 
        }
    } 
    
    srand(time(0));
    int grid_num = rand()%10;
    check_place(row,col,grid_num);
}

int main(){
    sample();
    int player = 0;
    int count = 0;
    int row = -1;
    int col = -1;
    int grid_num;
    int typed_num[10];

    int win = -1;
    while(count < 9 && win == -1){
        if(player == 1){
            player = 0;
        }else{
            player = 1;
        }
        cout << "Recent plays: ";
        for(int i =0;i<3;i++){
            for(int j=0;j<3;j++){
                std::cout << grid[i][j] << " ";
            }
        }
        
        std::cout << endl;
        std::cout << endl;

        if(player == 1){
            cout << "Player 1 (X)" << ", enter a grid #: " << endl;
            cin >> grid_num;
            check_place(row,col,grid_num);
            while(grid[row][col] == 'O' || grid[row][col] == 'X'){
                std::cout << "Not empty! Re-enter grid #:" << endl;
                std::cin >> grid_num;
                check_place(row,col,grid_num);
            }
        }

        if(player == 0){
            cout << "Player 0 (O) played:" << endl;
            srand(time(0));
            int level = rand()%2;
            if(level==1){
                close_to_win(row,col);
            }else{
                grid_num = rand()%10;
                check_place(row,col,grid_num);
            }

            while(grid[row][col]=='O' ||grid[row][col] == 'X'){
                grid_num = rand()%10;
                check_place(row,col,grid_num);
            }
        }

        if(player == 0){
            grid[row][col] = 'O'; //player 0 is O
            board[row][col] = 'O';
        }
        if(player == 1){
            grid[row][col] = 'X'; //player 1 is X
            board[row][col] = 'X';
        }
        std::cout << endl;
        display();
        who_won(win);
        count++;
    }

    if(win == 1){
        if(player == 1)
            cout << "Player 1 (X) " << "won!";
        if(player == 0)
            cout << "Player 0 (O) " << "won!";
    }else{
        cout << "Tie" << endl;
    }

    return 0;
}