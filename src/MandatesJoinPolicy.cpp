#pragma once
#include "JoinPolicy.h"
#include "Agent.h"

Agent MandatesJoinPolicy::join(vector<Agent> &offers,vector<int> &mandatesOfCoalition) {
    Agent temptAgent = offers[0];
    int mandates = mandatesOfCoalition.at(0);
    int index = 1;
    for(Agent agent1: offers){
       if(mandatesOfCoalition.at(index)> mandates){
           temptAgent = agent1;
           mandates = mandatesOfCoalition.at(index);
       }
       index++;
    }
    return  temptAgent;
}