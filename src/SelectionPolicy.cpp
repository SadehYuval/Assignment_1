#pragma once
#include "SelectionPolicy.h"
#include "Graph.h"
#include "Party.h"
#include "Agent.h"

SelectionPolicy::SelectionPolicy():availableNeighbors(){}

vector <Party> &SelectionPolicy::getNeighbors(Graph &graph, int partyId){
    vector<Party> neighbors;
    int size = graph.getNumVertices();
    for(int i = 0; i<size; i++){
        if(i!=partyId){ //Depending on the correctness of the input this 'if' can be removed
            if(graph.getEdgeWeight(partyId,i)!=0){
                neighbors.push_back(graph.getParty(i));
            }
        }
    }
    return neighbors;
}

vector<Party> &SelectionPolicy::screenNeighbors(vector <Party> &neighbors, int coalition){
    vector <Party> validNeighbors;
    bool add = true;
    int neighborsSize = neighbors.size();
    for(int i =0; i<neighborsSize; i++){
            int offersSize = neighbors[i].getOffers().size();
            for(int j= 0;j<offersSize && add; j++){
                if(neighbors[i].getOffers()[j].getCoalition() == coalition){//If there is an offer from the same coalition as our agent in the offers list of a neighbor
                 add = false;
                }
            }
            if(add){
                validNeighbors.push_back(neighbors[i]);
            }
            add = true;
    }
    return validNeighbors;
}
