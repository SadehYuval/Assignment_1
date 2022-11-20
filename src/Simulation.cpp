#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), allCoalition(), sizeOfCoalitions()
{
    for(Agent &agent:mAgents) {
        int index = 0;
        allCoalition.push_back(std::vector<int>{agent.getPartyId()});
        sizeOfCoalitions.push_back(getParty(agent.getPartyId()).getMandates());
        agent.setCoalition(index);
        mGraph.getParty(agent.getPartyId()).setState(Joined);//initialising relevant parties to Joined state
        index++;
    }
}


void Simulation::step()
{
    for(int i = 0; i< mGraph.getNumVertices();i++){
        mGraph.getParty(i).step(*this);
    }
    for(Agent &agent:mAgents)
        agent.step(*this);
}

bool Simulation::shouldTerminate() const
{
    int mAgentsSize = mAgents.size();
    bool ans = mAgentsSize == mGraph.getNumVertices();//all parties are joined
    if(!ans){
        for(int i = 0; i< allCoalition.size() & !ans; i++){
            if(sizeOfCoalitions[i]>= 61)
                ans = true;
        }
    }
    return  ans;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

 vector <int> &Simulation::getMandatesCoalition()
{
    return sizeOfCoalitions;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return allCoalition;
}

void  Simulation::addToCoalition(int partyId,int coalition)
{
    //adding to coalition and update
    allCoalition[coalition].push_back(partyId);
    sizeOfCoalitions[coalition] += getParty(partyId).getMandates();
}

void  Simulation::addAgent(Agent agent){
    mAgents.push_back(agent);
}
