#include "hillclimb.hpp"

int main(){
    system("cls");
    bool exit = false;
    int input, param;
    hillClimb hillclimb;
    
    while(!exit){
        cout << "Algoritma Hill Climb\n1. Steepest Ascent\n2. With Sideways\n3. Random Restart\n4. Stochastic\n5. Exit\nSilahkan pilih algoritma yang diinginkan: ";
        cin >> input;

        switch(input) {
        case 1:
            hillclimb.steepestAscent();
            break;
        case 2:
            cout << "Masukkan maksimum sideways move : ";
            cin >> param;
            hillclimb.sideWays(param);
            break;
        case 3:
            cout << "Masukkan banyak maksimum restart : ";
            cin >> param;
            hillclimb.randomRestart(param);
            break;
        case 4:
            cout << "Masukkan banyak langkah maksimum : ";
            cin >> param;
            hillclimb.stochastic(param);
            break;
        case 5:
            exit = true;
            break;
        }
    }
    
}