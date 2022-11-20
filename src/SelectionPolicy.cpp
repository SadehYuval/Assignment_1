#pragma once
#include "SelectionPolicy.h"
#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "Simulation.h"


vector <int> &SelectionPolicy::getNeighborsId(Simulation &sim, int partyId){
    Graph &graph = sim.getGraph();
    vector<int> neighbors;
    int size = graph.getNumVertices();
    for(int i = 0; i<size; i++){
        if(i!=partyId){ //Depending on the correctness of the input this 'if' can be removed
            if(graph.getEdgeWeight(partyId,i)!=0){
                neighbors.push_back(graph.getParty(i).getId());
            }
        }
    }
    return neighbors;
}
//vector<int> &screenNeighborsId(vector <int> &neighborsId, int coalition,Graph &graph);

vector<int> &SelectionPolicy::screenNeighborsId(vector <int> &neighborsId, int coalition,Simulation &sim){
    vector <int> validNeighborsId;
    bool add = true;
    int neighborsSize = neighborsId.size();
    for(int i =0; i<neighborsSize; i++){
            Party &currentParty = sim.getGraph().getParty(neighborsId[i]);
            int offersSize = currentParty.getOffers().size();
            for(int j= 0;j<offersSize && add; j++){
                int offeredAgentyId = currentParty.getOffers()[j];
                if(sim.getAgent(j).getCoalition() == coalition){//If there is an offer from the same coalition as our agent in the offers list of a neighbor
                 add = false;
                }
        
            }
            if(add){
                validNeighborsId.push_back(currentParty.getId());
            }
            add = true;
    }
    return validNeighborsId;
}
