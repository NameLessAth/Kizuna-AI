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
                    temp.value = curvalue;
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
            this->magiccube.value = this->magiccube.countValue();

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
            system("pause");
        }

        void sideWays(int maximumSidewaysMove){
            // Generate random cube 
            random_shuffle(this->magiccube.state.begin(), this->magiccube.state.end());
            this->magiccube.value = this->magiccube.countValue();

            // Print state awal
            cout << "State Awal :\n";
            this->magiccube.printCube();

            // Start timer
            auto start = high_resolution_clock::now();

            // Fungsi Steepest Ascent
            int iterasi = 0, counterSideways;
            vector<int> plot;
            bool peak = false;
            plot.push_back(this->magiccube.value);
            while(!peak){
                magicCube neighbor = highestValueNeighbor(this->magiccube);
                if(neighbor.value < this->magiccube.value){
                    peak = true;
                } else {
                    if(neighbor.value == this->magiccube.value){
                        counterSideways++;
                    } else {
                        counterSideways = 0;
                    }
                    if(counterSideways == maximumSidewaysMove){
                        peak = true;
                    } else {
                        this->magiccube = neighbor;
                    }
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
            system("pause");
        }

        void randomRestart(int maximumRestart){
            int maxvalue = 0,restart;
            vector<int> iterasi;
            vector<vector<int>> plot;

            // Print state awal
            cout << "State Awal :\n";
            this->magiccube.printCube();

            // Start timer
            auto start = high_resolution_clock::now();

            for(restart=0;restart<maximumRestart;restart++){
                // Generate random cube
                random_shuffle(this->magiccube.state.begin(), this->magiccube.state.end());
                // Fungsi Steepest Ascent
                int iterasii = 0;
                vector<int> plottemp;
                plottemp.clear();
                bool peak = false;
                plottemp.push_back(this->magiccube.value);
                while(!peak){
                    magicCube neighbor = highestValueNeighbor(this->magiccube);
                    if(neighbor.value <= this->magiccube.value){
                        peak = true;
                    } else {
                        this->magiccube = neighbor;
                    }
                    iterasii++;
                    plottemp.push_back(this->magiccube.value);
                }
                plot.push_back(plottemp);
                iterasi.push_back(iterasii);

                if(maxvalue < this->magiccube.value){
                    maxvalue = this->magiccube.value;
                }
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
            cout << "Iterasi per restart :\n";
            for(int i=0;i<restart;i++){
                cout << "restart-" << i+1 << " : " << iterasi[i] << endl;
            }

            for(int i=0;i<restart;i++){
                cout << "restart-" << i+1 << endl;
                int j=0;
                for(int plotting : plot[i]){
                    cout << "iterasi-" << j << " : " << plotting << endl;
                    j++;
                }
            }

            cout << "Maximum value : " << maxvalue << endl;

            // Delay
            system("pause");
        }

        void stochastic(){
            
        }
};