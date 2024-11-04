#include "hillclimb.hpp"

int main(){
    bool exit = false;
    int input;
    hillClimb hillclimb;
    
    while(!exit){
        system("cls");
        cout << "Algoritma Hill Climb\n1. Steepest Ascent\n2. With Sideways\n3. Random Restart\n4. Stochastic\n5. Exit\nSilahkan pilih algoritma yang diinginkan: ";
        cin >> input;

        switch(input) {
        case 1:
            hillclimb.steepestAscent();
            break;
        case 2:
            hillclimb.sideWays();
            break;
        case 3:
            hillclimb.randomRestart();
            break;
        case 4:
            hillclimb.stochastic();
            break;
        case 5:
            exit = true;
            break;
        }
    }
    
}