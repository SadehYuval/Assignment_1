#include "SelectionPolicy.h"
#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "Simulation.h"


void SelectionPolicy::getNeighborsId(Simulation &sim, int partyId,vector <int> &neighborsId){
    Graph &graph = sim.getGraph();
    int size = graph.getNumVertices();
    for(int i = 0; i<size; i++){
        if(i!=partyId){ //Depending on the correctness of the input this 'if' can be removed
            if(graph.getEdgeWeight(partyId,i)!=0){
                neighborsId.push_back(graph.getParty(i).getId());
            }
        }
    }
}

//vector<int> &screenNeighborsId(vector <int> &neighborsId, int coalition,Graph &graph);

void SelectionPolicy::screenNeighborsId(vector <int> &neighborsId, int coalition,Simulation &sim){
    vector <int> validNeighborsId;
    bool add = true;
    int neighborsSize = neighborsId.size();
    for(int i =0; i<neighborsSize; i++){
            Party &currentParty = sim.getGraph().getParty(neighborsId[i]);
            int offersSize = currentParty.getOffers().size();
            bool joined = (currentParty.getState() == Joined);
            for(int j= 0;j<offersSize && add && !joined; j++){
                int offeredAgentyId = currentParty.getOffers()[j];
                if(sim.getAgent(offeredAgentyId).getCoalition() == coalition){//If there is an offer from the same coalition as our agent in the offers list of a neighbor
                    add = false;
                }
        
            }
            if(add && !joined){
                validNeighborsId.push_back(currentParty.getId());
            }
            add = true;
    }
    neighborsId = validNeighborsId;
}
