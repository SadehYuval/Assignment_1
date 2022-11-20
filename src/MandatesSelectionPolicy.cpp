#pragma once
#include "Graph.h"
#include "Party.h"
#include "Agent.h"
#include "SelectionPolicy.h"

Party &MandatesSelectionPolicy::select(Graph &graph, Agent &selector) {
    vector <Party> neighbors = getNeighbors(graph, selector.getPartyId());
    vector <Party> validNeighbors = screenNeighbors(neighbors, selector.getCoalition());
    int mostMandates = 0;
    Party toChoose = validNeighbors[0];
    int tempMandates;
    int validNeighborsSize = validNeighbors.size();
    for(int i=0; i<validNeighborsSize; i++){
        tempMandates = neighbors[i].getMandates();
        if(tempMandates > mostMandates){
            mostMandates = tempMandates;
            toChoose = neighbors[i];
        }
    }
    return toChoose;
}