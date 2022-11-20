#pragma once
#include <vector>
class Party;
class Graph;
class Agent;
using std::vector;

class SelectionPolicy {
    public:

        SelectionPolicy();
        vector <Party> &availableNeighbors;
        virtual ~SelectionPolicy() = default;
        virtual Party& select(Graph &graph,Agent &selector) = 0;
        vector<Party> &getNeighbors(Graph &graph, int partyId);
        vector<Party> &screenNeighbors(vector <Party> &neighbors, int coalition);
 };


class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        ~MandatesSelectionPolicy();
        Party& select(Graph &graph, Agent &selector) override;
};


class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        ~EdgeWeightSelectionPolicy();
        Party& select(Graph &graph, Agent &selector) override;
 };
