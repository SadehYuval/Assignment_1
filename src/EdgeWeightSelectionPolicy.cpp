#pragma once
#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

int EdgeWeightSelectionPolicy::select(Simulation &sim, Agent &selector) {
    vector <int> neighborsId = getNeighborsId(sim, selector.getPartyId());
    vector <int> validNeighborsId = screenNeighborsId(neighborsId, selector.getCoalition(),sim);
    int maxWeight = 0;
    int partyIdtoChoose = validNeighborsId[0];
    int tempWeight;
    int validNeighborsIdSize = validNeighborsId.size();
    for(int i=0; i<validNeighborsIdSize; i++){
        tempWeight = sim.getGraph().getEdgeWeight(selector.getPartyId(), i);
        if(tempWeight > maxWeight){
            maxWeight = tempWeight;
            partyIdtoChoose = neighborsId[i];
        }
    }
    return partyIdtoChoose;
}