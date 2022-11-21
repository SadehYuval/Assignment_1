#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

int MandatesSelectionPolicy::select(Simulation &sim, Agent &selector) {
    vector <int> validNeighborsId;
    getNeighborsId(sim,selector.getPartyId(),validNeighborsId);
    screenNeighborsId(validNeighborsId, selector.getCoalition(),sim);
    int mostMandates = 0;
    int partyIdtoChoose = validNeighborsId[0];
    int tempMandates;
    int validNeighborsIdSize = validNeighborsId.size();
    for(int i=0; i<validNeighborsIdSize; i++){
        Party &currentParty = sim.getGraph().getParty(validNeighborsId[i]);
        tempMandates = currentParty.getMandates();
        if(tempMandates > mostMandates){
            mostMandates = tempMandates;
            partyIdtoChoose = currentParty.getId();
        }
    }
    return partyIdtoChoose;
}