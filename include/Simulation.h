#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;


    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void  addToCoalition(int partyId,int coalition);
    vector<int> &getMandatesCoalition();
    void  addAgent(Agent agent);


private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> allCoalition;
    vector<int> sizeOfCoalitions;

};
