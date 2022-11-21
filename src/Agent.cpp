#include "Agent.h"
#include "Party.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalition(0)
{
    // You can change the implementation of the constructor, but not the signature!
}

//rule of 5

//destructor
Agent::~Agent()
{
    if(mSelectionPolicy){
        delete(mSelectionPolicy);
        mSelectionPolicy = nullptr;
    }
    
}
//assignment operator
Agent& Agent:: operator=(const Agent& other)
{
    if(this != &other){
        this->mAgentId = other.mAgentId;
        this->mPartyId = other.mPartyId;
        this->mSelectionPolicy = other.mSelectionPolicy;//TODO check if valid
        this->coalition = other.coalition;
    }
    return *this;
}
//copy constructor
Agent::Agent(const Agent &other)
    : mAgentId{other.mAgentId}, mPartyId{other.mPartyId}, mSelectionPolicy{other.mSelectionPolicy}, coalition{other.coalition} {}

//move assignment operator
Agent& Agent:: operator=(Agent &&other) noexcept
{
    if(this != &other){
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        coalition = other.coalition;
        other.mSelectionPolicy = nullptr;
    }
    return *this;
}
//move copy constructor
Agent::Agent(Agent &&other)noexcept
        : mAgentId{other.mAgentId}, mPartyId{other.mPartyId}, mSelectionPolicy{other.mSelectionPolicy}, coalition{other.coalition}
{
    other.mSelectionPolicy = nullptr;
    //need to check if we need to  other.offers = nullptr;

}




int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getCoalition() const
{
    return  coalition;
}

void Agent::step(Simulation &sim)
{
    int selectedPartyId = mSelectionPolicy -> select(sim, *this);
    Party &selectedParty = sim.getGraph().getParty(selectedPartyId);
    selectedParty.addOffer(mAgentId);
    
}

void  Agent::setCoalition(int c) {
    coalition = c;
}

void Agent::setPartyId(int partyId)
{
    mPartyId = partyId;
}

void  Agent::setId(int id)
{
    mAgentId = id;
}
