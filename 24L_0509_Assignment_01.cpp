#include <iostream>
#include <cstdlib> 
#include <ctime>    
#include <conio.h>   
using namespace std;


const int rows = 20;
const int cols = 20;
const int max_levels = 5;
const int treasures_for_level = 10;
const int LEVELS = 5;     
const int Maximum_Lives = 5; 


void initializeMap(char** &arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            arr[i][j] = '.';
        }
    }
}

void populate(char** &arr, int rows, int cols,  int numExplosives){

    for (int t = 0; t < treasures_for_level ; t++) {
        int i, j;
        do {
            i = rand() % rows;
            j = rand() % cols;
        } while (arr[i][j] != '.');
        arr[i][j] = 'T';
    }

    for (int e = 0; e < numExplosives; e++) {
        int i, j;
        do {
            i = rand() % rows;
            j = rand() % cols;
        } while (arr[i][j] != '.');
        arr[i][j] = 'E';
    }
}


void print_map(char** &map, int rows, int cols, int playerRow, int playerCol) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == playerRow && j == playerCol) {
                cout << "P ";
            }
            else {
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
}


void playerMovement(char input, int& playerRow, int& playerCol) {
    switch (toupper(input)) {
    case 'W': 
        if (playerRow > 0) playerRow--;
        break;
    case 'A': 
        if (playerCol > 0) playerCol--;
        break;
    case 'S': 
        if (playerRow < rows - 1) playerRow++;
        break;
    case 'D': 
        if (playerCol < cols - 1) playerCol++;
        break;
    default:
        cout << "Invalid input! Use W/A/S/D." << endl;
        break;
    }
}


bool checkCollision(char** &map, int playerRow, int playerCol, int& lives, int& levelScore, int& treasuresFound) {
    if (map[playerRow][playerCol] == 'T') {
        cout << "Treasure Found" << endl;
        levelScore= levelScore + 10;
        treasuresFound = treasuresFound + 1; 
        map[playerRow][playerCol] = '.';
        if (treasuresFound == treasures_for_level) {
            cout << "All treasures found in this level!" << endl;
            return true; 
        }
    }
    else if (map[playerRow][playerCol] == 'E') {
        cout << "Explosive has been hit. Your life is reduced by 1" << endl;
        lives--;
        if (lives == 0) {
            cout << ":/ All lives gone!!" << endl;
            return true;
        }
    }
    return false; 
}


bool playLevel(char **& treasuremap,int& level, int& lives, int& totalScore) {
    int levelScore = 0;
    int treasures_found = 0;
    int explosivesInLevel = 50 * level;

    // HAM HAMESHA PLAY LEVEL MEIN NAYA DYNAMIC 2D ARRAY INITIALIZE KARIEN GE TAKAY EXPLOSIVES ENTERTAIN HO SAKIEN! 
    for (int i = 0; i < rows; i++) {
        treasuremap[i] = new char[cols];
    }
    initializeMap(treasuremap, rows, cols);

    
    populate(treasuremap, rows, cols,  explosivesInLevel);

    
    int playerRow = 0;
    int playerCol = 0;
    treasuremap[playerRow][playerCol] = '.'; 

    // Yahan se hamara level update ho kar change hoga. Tou this is going to be the level loop! 
    while (true) {
   
        cout << "\nLevel " << level << ":\n";
        print_map(treasuremap, rows, cols, playerRow, playerCol);

        
        cout << "Lives: " << lives << " | Level Score: " << levelScore << " | Total Score: " << totalScore << endl;

        
        char input;
        cout << "Enter movement (W/A/S/D): ";
        input = _getch(); 

       
        treasuremap[playerRow][playerCol] = '.';

        
        playerMovement(input, playerRow, playerCol);

        
        if (checkCollision(treasuremap, playerRow, playerCol, lives, levelScore, treasures_found)) {
            if (lives == 0) {
                // Agar lives end hojaien ge tou ham yeh karien ge! 
                return false;
            }
            else if (treasures_found == treasures_for_level) {
                break;
            }
        }

        treasuremap[playerRow][playerCol] = 'P';
    }

 
    totalScore += levelScore;

 
    cout << "\nLevel " << level << " Results:\n";
    cout << "Level Score: " << levelScore << endl;
    cout << "Total Score: " << totalScore << endl;
    cout << "Remaining Lives: " << lives << endl;

   


    return true; 
}

// Is function key through we are going to be working towards playing the game!
void playGame() {
   
    int lives = Maximum_Lives; 
    int totalScore = 0;

    
    char** treasuremap = new char* [rows];
    for (int level = 1; level <= LEVELS; level++) {
        if (!playLevel(treasuremap,level, lives, totalScore)) {
         
            return;
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] treasuremap[i];
    }
    delete[] treasuremap;
   
    cout << "\nCongratulations! You completed all 5 levels!" << endl;
    cout << "Final Score: " << totalScore << endl;
}

int main() {
    
    srand(time(0));
   
    playGame();

    return 0;
}