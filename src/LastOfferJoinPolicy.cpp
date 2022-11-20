#pragma once
#include "JoinPolicy.h"
#include "Agent.h"
Agent LastOfferJoinPolicy::join(vector<Agent> &offers,vector<int> &mandatesOfCoalition) {
    return  offers.back();
}