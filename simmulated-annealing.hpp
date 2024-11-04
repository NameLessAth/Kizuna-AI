#include "magic-cube.hpp"  
#include <chrono>
#include <math.h>
using namespace std::chrono;

class SimulatedAnnealing {
private:
    magicCube cube;   
    double temperature;      
	vector<int> plot;
    vector<double> plotexp;
    int freqStuck;

    double schedule(int t) {
        return pow(0.6,t-1);
    }

public:
    SimulatedAnnealing() : temperature(1.0), freqStuck(0) {}

    void run(int maxIterations) {
		plot.push_back(cube.value);
        for (int t = 1; t <= maxIterations; ++t) {
            temperature = schedule(t);  
            if (temperature <= 0) break;

            magicCube successor;
            successor.switchStates(cube.makeRandomNeighborState());
            int deltaE = successor.value - cube.value; 

            if (deltaE > 0) {
                cube.switchStates(successor.state); 
            } else {
                freqStuck++;
                double acceptanceProb;
                if (temperature <= 0) acceptanceProb = 0;
                else{
                    acceptanceProb = exp(deltaE / temperature);
                    if (acceptanceProb > 1) acceptanceProb = 1;
                }
                
                plotexp.push_back(acceptanceProb);
                if (((double)rand() / (double)RAND_MAX) < acceptanceProb) {
                    cube.switchStates(successor.state);
                }
            }
			plot.push_back(cube.value);
        }
    }

        void start(){
            // Clear terminal
            system("cls");

            // Print state awal
            cout << "State Awal :\n";
            cube.printCube();

            // Start timer
            auto start = high_resolution_clock::now();

            // Fungsi Simulated-Annealing
			this->run(1000);

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
            cout << "Frekuensi Stuck : " << freqStuck << endl;
            cout << "Plot Objective Function : " << endl; printVectorInt(plot);
            cout << "Plot exp(deltaE/T) : " << endl; printVectorDouble(plotexp);
        }

    void printCurrentState() {
        cube.printCube();
    }

    void printVectorInt(const vector<int>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i != vec.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }

    void printVectorDouble(const vector<double>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i];
            if (i != vec.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
    
    
};
