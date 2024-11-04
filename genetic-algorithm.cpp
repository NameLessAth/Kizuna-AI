#include "genetic-algorithm.hpp"
using namespace std;

geneticAlgorithm::geneticAlgorithm(int i, int p) {
    magicCube origin = magicCube();
    this->iterations = i;
    this->popcount = p;
    this->initPopulation(origin, p);
    srand(time(NULL)); //setting seed 
    cout << "Starting value: " << origin.value << endl;

}

void geneticAlgorithm::initPopulation(magicCube origin, int count) {
    vector<magicCube> popul;
    for (int i=0; i<count; i++) popul.push_back(magicCube(origin.makeRandomNeighborState()));
    this->population = popul;
}

int geneticAlgorithm::selection() {
    float selector = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float curval = 0;
    float sumvalues = 0;

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
    float chance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); 
    if (chance > 0.95) child->switchStates(child->makeRandomNeighborState());
}

void geneticAlgorithm::go() {
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
        cout << "Iteration: " << i << " child1 value: " << child1.value << ", child2 value: " << child2.value << endl;
    }
}

int geneticAlgorithm::bestIndividual() {
    int max = 0;
    for (int i=1; i<this->popcount; i++) {
        if (this->population[i].value > max) max = this->population[i].value;
    }
    return max;
}

int main() {
    geneticAlgorithm genalg = geneticAlgorithm(1000, 125);
    genalg.go();
    cout << "Final highest value: " << genalg.bestIndividual() << endl;
}

