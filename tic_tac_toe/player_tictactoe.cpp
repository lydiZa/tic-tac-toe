#include <iostream>
#include <string>
using namespace std;

char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

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
    while(grid[row][col] == 'O' || grid[row][col] == 'X'){
        std::cout << "Not empty! Re-enter grid #:" << endl;
        cin >> grid_num;
        check_place(row,col,grid_num);
    }
}

void display(){
     std::cout << grid[0][0] << " |" << ' ' << grid[0][1] << ' ' << "| " << grid[0][2] << endl;
     std::cout << "---------"<< endl;
     std::cout << grid[1][0] << " |" << ' ' << grid[1][1] << ' ' << "| " << grid[1][2] << endl;
     std::cout << "---------"<< endl;
     std::cout << grid[2][0] << " |" << ' ' << grid[2][1] << ' ' << "| " << grid[2][2] << endl;

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

int main(){
    sample();
    int player = 0;
    int count = 0;
    int row = -1;
    int col = -1;
    int grid_num;

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

        if(player == 1)
            cout << "Player 1 (X)" << ", enter a grid #: " << endl;
        
        if(player == 0)
            cout << "Player 0 (O)" << ", enter a grid #: " << endl;
     
            cin >> grid_num;
            check_place(row,col,grid_num);
       
        if(player == 0)
            grid[row][col] = 'O'; //player 0 is O

        if(player == 1)
            grid[row][col] = 'X'; //player 1 is X

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