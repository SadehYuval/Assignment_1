#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

int EdgeWeightSelectionPolicy::select(Simulation &sim, Agent &selector) {
    vector <int> validNeighborsId;
    getNeighborsId(sim,selector.getPartyId(),validNeighborsId);
    screenNeighborsId(validNeighborsId, selector.getCoalition(),sim);
    int maxWeight = 0;
    int partyIdtoChoose = validNeighborsId[0];
    int tempWeight;
    int validNeighborsIdSize = validNeighborsId.size();
    for(int i=0; i<validNeighborsIdSize; i++){
        tempWeight = sim.getGraph().getEdgeWeight(selector.getPartyId(), i);
        if(tempWeight > maxWeight){
            maxWeight = tempWeight;
            partyIdtoChoose = validNeighborsId[i];
        }
    }
    return partyIdtoChoose;
}