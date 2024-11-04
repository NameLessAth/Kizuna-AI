#ifndef GENETICALGORITHM_HPP
#define GENETICALGORITHM_HPP

#include <bits/stdc++.h>
#include "magic-cube.hpp"
using namespace std;

class geneticAlgorithm {
    private:
        vector<magicCube> population;
        int iterations;
        int popcount;

    public:
        geneticAlgorithm(int i, int p);
        void initPopulation(magicCube origin, int count);
        int selection();
        vector<vector<int>> crossover(magicCube parent1, magicCube parent2);
        void mutate(magicCube* child);
        void go();
        int bestIndividual();
};

#endif