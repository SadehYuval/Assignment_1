#include "JoinPolicy.h"
#include "Agent.h"

int MandatesJoinPolicy::join(vector<int> &offers,vector<int> &mandatesOfCoalition) {
    int temptAgentId = offers[0];
    int mandates = mandatesOfCoalition.at(temptAgentId);
    int index = 1;
    for(int agentId: offers){
       if(mandatesOfCoalition.at(agentId)> mandates){
           temptAgentId = agentId;
           mandates = mandatesOfCoalition.at(agentId);
       }
       index++;
    }
    return  temptAgentId;
}

JoinPolicy *MandatesJoinPolicy::clone(){
    return new MandatesJoinPolicy;
}