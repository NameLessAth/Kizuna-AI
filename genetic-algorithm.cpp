#include "genetic-algorithm.hpp"
#include <fstream> 
using namespace std;

void printVec(vector<int> vec, int ex) {
    string filename = "max";
    filename.append(to_string(ex));
    ofstream maxFile(filename);

    // Write to the file
    for (int i=0; i<vec.size(); i++) {
        maxFile << vec[i] << ",";
    }
    maxFile << vec[124] << endl;

    // Close the file
    maxFile.close();
}

void printVecD(vector<double> vec, int ex) {
    string filename = "mean";
    filename.append(to_string(ex));
    ofstream meanFile(filename);
    // Write to the file
    for (int i=0; i<vec.size(); i++) {
        meanFile << vec[i] << ",";
    }
    meanFile << vec[124] << endl;

    // Close the file
    meanFile.close();
}

geneticAlgorithm::geneticAlgorithm(int i, int p) {
    magicCube origin = magicCube();
    this->iterations = i;
    this->popcount = p;
    this->initPopulation(origin, p);
    srand(time(NULL)); //setting seed 
    cout << "Nilai Awal Objective Function: " << origin.value << endl;
    origin.printCube();
}

void geneticAlgorithm::initPopulation(magicCube origin, int count) {
    vector<magicCube> popul;
    for (int i=0; i<count; i++) popul.push_back(magicCube(origin.makeRandomNeighborState()));
    this->population = popul;
}

int geneticAlgorithm::selection() {
    double selector = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    double curval = 0;
    double sumvalues = 0;

    for (int i=0; i<popcount; i++) {
        sumvalues += population[i].value;
    }

    for (int i=0; i<popcount; i++) {
        curval += population[i].value/sumvalues;
        if (selector < curval) {
            return i;
        }
    }
    return popcount-1;
}

vector<vector<int>> geneticAlgorithm::crossover(magicCube parent1, magicCube parent2) {
    int point = rand() % 124;

    vector<vector<int>> res;
    vector<int> child1;
    vector<int> child2;

    child1.insert(child1.begin(), parent1.state.begin(), parent1.state.begin()+point);
    child1.insert(child1.end(), parent2.state.begin()+point, parent2.state.end());
    res.push_back(child1);

    child2.insert(child2.begin(), parent2.state.begin(), parent2.state.begin()+point);
    child2.insert(child2.end(), parent1.state.begin()+point, parent1.state.end());
    res.push_back(child2);
    return res;
}

void geneticAlgorithm::mutate(magicCube* child) {
    double chance = static_cast <double> (rand()) / static_cast <double> (RAND_MAX); 
    if (chance > 0.95) child->switchStates(child->makeRandomNeighborState());
}

void geneticAlgorithm::go(int exp) {
    // Start timer
    auto start = chrono::high_resolution_clock::now();

    //vector untuk menyimpan value per iterasi
    vector<int> maxVals;
    vector<double> meanVals;

    for (int i=0; i<this->iterations; i++) {
        int selection1 = this->selection();
        int selection2 = this->selection();
        while (selection2==selection1) selection2 = this->selection();

        magicCube parent1 = this->population[selection1];
        magicCube parent2 = this->population[selection2];

        vector<vector<int>> cross = this->crossover(parent1, parent2);
        magicCube child1 = magicCube(cross[0]);
        magicCube child2 = magicCube(cross[1]);

        this->mutate(&child1);
        this->mutate(&child2);

        this->population.push_back(child1);
        this->population.push_back(child2);
        this->popcount += 2;
        maxVals.push_back(this->population[this->bestIndividual()].value);
        meanVals.push_back(this->meanValues());
    }
    // Stop timer
    auto end = chrono::high_resolution_clock::now();

    // Hitung waktu
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    int best_idx = this->bestIndividual();
    cout << "Nilai Akhir Objective Function : " << this->population[best_idx].value << endl;
    this->population[best_idx].printCube();
    cout << "Durasi : " << duration.count() / 1000.0 << " seconds" << endl;
    cout << "Banyak Iterasi : " << this->iterations << endl;
    printVec(maxVals, exp);
    printVecD(meanVals, exp);

}

int geneticAlgorithm::bestIndividual() {
    int max = 0;
    int idx = 0;
    for (int i=1; i<this->popcount; i++) {
        if (this->population[i].value > max) {
            idx = i;
            max = this->population[i].value;
        }
    }
    return idx;
}

double geneticAlgorithm::meanValues() {
    double sum = 0;
    for (int i=1; i<this->popcount; i++) sum+=this->population[i].value;
    return sum/popcount;
}

int main() {
    int iterations, size, experiment;
    cout << "Masukkan angka eksperimen: ";
    cin >> experiment;
    cout << "Masukkan jumlah iterasi: ";
    cin >> iterations;
    cout << "Masukkan jumlah populasi awal: ";
    cin >> size;
    geneticAlgorithm genalg = geneticAlgorithm(iterations, size);
    genalg.go(experiment);
}

