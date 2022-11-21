#include "JoinPolicy.h"
#include "Agent.h"
int LastOfferJoinPolicy::join(vector<int> &offers,vector<int> &mandatesOfCoalition) {
    return  offers.back();
}

JoinPolicy *LastOfferJoinPolicy::clone(){
    return new LastOfferJoinPolicy; 
}
