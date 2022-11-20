#pragma once
#include <vector>
class Party;
class Graph;
class Agent;
class Simulation;
using std::vector;

class SelectionPolicy {
    public:
        virtual ~SelectionPolicy() = default;
        virtual int select(Simulation &sim,Agent &selector) = 0;
        vector<int> &getNeighborsId(Simulation &sim, int partyId);
        vector<int> &screenNeighborsId(vector <int> &neighborsId, int coalition,Simulation &sim);
 };


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        ~MandatesSelectionPolicy();
        int select(Simulation &sim, Agent &selector) override;
};


class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        ~EdgeWeightSelectionPolicy();
        int select(Simulation &sim, Agent &selector) override;
 };
