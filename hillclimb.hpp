#include "magic-cube.hpp"
#include <chrono>
using namespace std::chrono;

class hillClimb {
    public:
        magicCube magiccube;

        hillClimb(){
            this->magiccube = magicCube();
        }

        magicCube highestValueNeighbor(magicCube current) {
            int maxvalue = 0, curvalue;
            magicCube neighbor = current,temp;

            for (int i = 0; i < 125; i++) {
                for (int j = i + 1; j < 125; j++) {
                    vector<int> successor = current.state;
                    swap(successor[i], successor[j]);
                    temp.state = successor;
                    curvalue = temp.countValue();
                    if(temp.countValue() > maxvalue){
                        maxvalue = curvalue;
                        neighbor = temp;
                    }
                }
            }

            return neighbor;
        }

        

        void steepestAscent(){
            // Generate random cube 
            random_shuffle(this->magiccube.state.begin(), this->magiccube.state.end());

            // Clear terminal
            system("cls");

            // Print state awal
            cout << "State Awal :\n";
            this->magiccube.printCube();

            // Start timer
            auto start = high_resolution_clock::now();

            // Fungsi Steepest Ascent
            int iterasi = 0;
            vector<int> plot;
            bool peak = false;
            plot.push_back(this->magiccube.value);
            while(!peak){
                magicCube neighbor = highestValueNeighbor(this->magiccube);
                if(neighbor.value <= this->magiccube.value){
                    peak = true;
                } else {
                    this->magiccube = neighbor;
                }
                iterasi++;
                plot.push_back(this->magiccube.value);
            }

            // Stop timer
            auto end = high_resolution_clock::now();

            // Hitung waktu
            auto duration = duration_cast<milliseconds>(end - start);

            // Print state akhir
            cout << "State Akhir :\n";
            this->magiccube.printCube();

            // Print info
            cout << "Nilai Akhir Objective Function : " << this->magiccube.value << endl;
            cout << "Durasi : " << duration.count() / 1000.0 << " seconds" << endl;
            cout << "Banyak Iterasi : " << iterasi << endl;

            for(int i=0;i<=iterasi;i++){
                cout << "iterasi-" << i << " : " << plot[i] << endl;
            }

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