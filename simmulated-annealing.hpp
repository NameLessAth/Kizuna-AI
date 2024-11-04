#include "magic-cube.hpp"  
#include <chrono>
#include <math.h>
using namespace std::chrono;

class SimulatedAnnealing {
private:
    magicCube cube;   
    double temperature;     
	double iterasi; 
	vector<int> plot;

    double schedule(int t) {
        return pow(0.85,t-1);
    }

public:
    SimulatedAnnealing() : temperature(1.0), iterasi(0) {}

    void run(int maxIterations) {
		iterasi = 0;
		plot.clear();
		plot.push_back(cube.value);
        for (int t = 1; t <= maxIterations; ++t) {
            temperature = schedule(t);  

            int i = rand() % cube.state.size();
            int j = rand() % cube.state.size();
            while (i == j) {
                j = rand() % cube.state.size(); 
            }

            magicCube successor;
            successor.switchStates(cube.makeRandomNeighborState());
            int deltaE = successor.value - cube.value; 

            if (deltaE > 0) {
                cube = successor; 
            } else {
                double acceptanceProb = exp(deltaE / temperature);
                if (((double)rand() / (double)RAND_MAX) < acceptanceProb) {
                    cube = successor;
                }
            }
			iterasi++;
			plot.push_back(cube.value);
        }
    }

        void start(){
            // Generate random cube 
            random_shuffle(cube.state.begin(), cube.state.end());

            // Clear terminal
            system("cls");

            // Print state awal
            cout << "State Awal :\n";
            cube.printCube();

            // Start timer
            auto start = high_resolution_clock::now();

            // Fungsi Simulated-Annealing
			this->run(10000);

            // Stop timer
            auto end = high_resolution_clock::now();

            // Hitung waktu
            auto duration = duration_cast<milliseconds>(end - start);

            // Print state akhir
            cout << "State Akhir :\n";
            this->cube.printCube();

            // Print info
            cout << "Nilai Akhir Objective Function : " << this->cube.value << endl;
            cout << "Durasi : " << duration.count() / 1000.0 << " seconds" << endl;
            cout << "Banyak Iterasi : " << iterasi << endl;

            // Delay
            string wait;
            cin >> wait;
        }

    void printCurrentState() {
        cube.printCube();
    }
};
