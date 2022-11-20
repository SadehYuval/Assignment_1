#pragma once
#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "SelectionPolicy.h"

Party &EdgeWeightSelectionPolicy::select(Graph &graph, Agent &selector) {
    vector <Party> neighbors = getNeighbors(graph, selector.getPartyId());
    vector <Party> validNeighbors = screenNeighbors(neighbors, selector.getCoalition());
    int maxWeight = 0;
    Party toChoose = validNeighbors[0];
    int tempWeight;
    int validNeighborsSize = validNeighbors.size();
    for(int i=0; i<validNeighborsSize; i++){
        tempWeight = graph.getEdgeWeight(selector.getPartyId(), i);
        if(tempWeight > maxWeight){
            maxWeight = tempWeight;
            toChoose = neighbors[i];
        }
    }
    return toChoose;
}