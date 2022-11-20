#pragma once
#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

int MandatesSelectionPolicy::select(Simulation &sim, Agent &selector) {
    vector <int> neighborsId = getNeighborsId(sim, selector.getPartyId());
    vector <int> validNeighborsId = screenNeighborsId(neighborsId, selector.getCoalition(),sim);
    int mostMandates = 0;
    int partyIdtoChoose = validNeighborsId[0];
    int tempMandates;
    int validNeighborsIdSize = validNeighborsId.size();
    for(int i=0; i<validNeighborsIdSize; i++){
        Party &currentParty = sim.getGraph().getParty(neighborsId[i]);
        tempMandates = currentParty.getMandates();
        if(tempMandates > mostMandates){
            mostMandates = tempMandates;
            partyIdtoChoose = currentParty.getId();
        }
    }
    return partyIdtoChoose;
}