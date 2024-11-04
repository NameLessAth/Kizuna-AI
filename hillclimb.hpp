#include "magic-cube.hpp"
#include <chrono>
using namespace std::chrono;

class hillClimb : public magicCube {
    public:
        hillClimb(){
            magicCube();
        }

        magicCube highestValueTetangga(magicCube current) {
            int maxvalue = 0, curvalue;
            magicCube successor = current,temp;

            for (int i = 0; i < 125; i++) {
                for (int j = i + 1; j < 125; j++) {
                    vector<int> neighbor = current.state;
                    swap(neighbor[i], neighbor[j]);
                    temp.state = neighbor;
                    curvalue = temp.countValue();
                    if(temp.countValue() > maxvalue){
                        maxvalue = curvalue;
                        successor = temp;
                    }
                }
            }

            return successor;
        }

        

        void steepestAscent(){
            // Generate random cube 
            random_shuffle(this->state.begin(), this->state.end());

            // Clear terminal
            system("cls");

            // Print state awal
            cout << "State Awal :\n";
            this->printCube();

            // Start timer
            auto start = high_resolution_clock::now();


            // Stop timer
            auto end = high_resolution_clock::now();

            // Hitung waktu
            auto duration = duration_cast<seconds>(end - start);

            // Print state akhir
            cout << "State Akhir :\n";
            this->printCube();

            // Print info
            cout << "Nilai Akhir Objective Function : " << this->value << endl;
            cout << "Durasi : " << endl;
            cout << "Banyak Iterasi : " << endl;

            // Delay
            string wait;
            cin >> wait;
        }

        void sideWays(){
            
        }

        void randomRestart(){

        }

        void stochastic(){
            
        }
};