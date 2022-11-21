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
    int validNeighborsIdSize = validNeighborsId.size();
    if(validNeighborsIdSize == 0) //no valid party to choose
        return -1;
    int partyIdtoChoose = validNeighborsId[0];
    int tempMandates;
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

 SelectionPolicy *MandatesSelectionPolicy::clone(){
    return new MandatesSelectionPolicy;
 }