#include "Party.h"
#include "Agent.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),timer(0), offers()

{
    // You can change the implementation of the constructor, but not the signature!
}
//rule of 5:
//destructor
Party::~Party()
{
    if(mJoinPolicy){
        delete(mJoinPolicy);
        mJoinPolicy = nullptr;
    }
    
}
//assignment operator
Party& Party:: operator=(const Party& other)
{
    if(this != &other){
        this->mId = other.mId;
        this->mName = other.mName;
        this->mMandates = other.mMandates;
        this->mJoinPolicy = other.mJoinPolicy->clone();
        this->mState = other.mState;
        this->timer = other.timer;
        this->offers = other.offers;
    }
    return *this;
}
//copy constructor
Party::Party(const Party &other)
    : mId{other.mId}, mName{other.mName}, mMandates{other.mMandates}, mJoinPolicy{other.mJoinPolicy->clone()}, mState{other.mState}
    ,timer{other.timer}, offers{other.offers}
{
    
}
//move assignment operator
Party& Party:: operator=(Party &&other) noexcept
{
    if(this != &other){
        delete(this);
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        timer = other.timer;
        offers = other.offers;
        other.mJoinPolicy = nullptr;
    }
    return *this;
}
//move copy constructor
Party::Party(Party &&other)noexcept
    : mId{other.mId}, mName{other.mName}, mMandates{other.mMandates}, mJoinPolicy{other.mJoinPolicy}, mState{other.mState}
    ,timer{other.timer}, offers{other.offers}
{
    other.mJoinPolicy = nullptr;
}


//getters
State Party::getState() const
{
    return mState;
}

int Party::getId()const
{
    return mId;
}


int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

vector <int> &Party::getOffers()
{
    return offers;
}

void Party::setState(State state)
{
    mState = state;
}


void Party::step(Simulation &s)
{
    if(mState != Joined){
        if(mState == CollectingOffers){
            timer ++;
            if(timer ==3){
                chooseParty(s);
                setState(Joined);
            }
        }
        /*if(timer == 0 && !offers.empty()){
            setState(CollectingOffers);
        }*/
    }
}

void  Party::addOffer(int agentId)
{
    offers.push_back(agentId);
}

void  Party::chooseParty(Simulation &s)
{
    int selectedAgentId =  mJoinPolicy->join(offers,s.getMandatesCoalition());
    int cloneAgentCoalition = s.getAgents()[selectedAgentId].getCoalition();
    Agent cloneAgent = s.getAgents()[selectedAgentId];
    //clone Agent + add to vector<Agent>
    cloneAgent.setPartyId(mId);
    cloneAgent.setId(s.getAgents().size());
    cloneAgent.setCoalition(cloneAgentCoalition);
    s.addAgent(cloneAgent);
    s.addToCoalition(mId,cloneAgent.getCoalition());
}






