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
        virtual SelectionPolicy *clone() = 0;
        virtual int select(Simulation &sim,Agent &selector) = 0;
        void getNeighborsId(Simulation &sim, int partyId, vector <int> &neighborsId);
        void screenNeighborsId(vector <int> &neighborsId, int coalition,Simulation &sim);
 };


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        ~MandatesSelectionPolicy() = default;
        SelectionPolicy *clone() override;
        int select(Simulation &sim, Agent &selector) override;
};


class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        ~EdgeWeightSelectionPolicy() = default;
         SelectionPolicy *clone() override;
         int select(Simulation &sim, Agent &selector) override;
 };
