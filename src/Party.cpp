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
    delete(mJoinPolicy);
    mJoinPolicy = nullptr;
}
//assignment operator
Party& Party:: operator=(const Party& other)
{
    if(this != &other){
        this->mId = other.mId;
        this->mName = other.mName;
        this->mMandates = other.mMandates;
        this->mJoinPolicy = other.mJoinPolicy;//TODO check if valid
        this->mState = other.mState;
        this->timer = other.timer;
        this->offers.clear();
        int offersSize = other.offers.size(); 
        for(int i =0; i<offersSize; i++){
            offers.push_back(other.offers[i]);
        }
    }
    return *this;
}
//copy constructor
Party::Party(const Party &other)
    : mId{other.mId}, mName{other.mName}, mMandates{other.mMandates}, mJoinPolicy{other.mJoinPolicy}, mState{other.mState}
    ,timer{other.timer}, offers{other.offers}
{
    
}
//move assignment operator
Party& Party:: operator=(Party &&other) noexcept
{
    if(this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        timer = other.timer;
        offers = other.offers;//TODO
        //other.offers = nullptr; Realize what to do with a vector that needs to be deleted
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
    //need to check if we need to  other.offers = nullptr;

}


//getters
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

const vector <Agent> Party::getOffers() const
{
    return offers;
}

vector <Agent> &Party::getOffers(){
    return offers;
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
        if(timer == 0 && !offers.empty()){
            setState(CollectingOffers);
        }
    }
}

void  Party::addOffer(Agent &agent)
{
    offers.push_back(agent);
}

void  Party::chooseParty(Simulation &s)
{
    Agent chosenAgent = mJoinPolicy->join(offers,s.getMandatesCoalition());
    s.addToCoalition(chosenAgent.getPartyId(),chosenAgent.getCoalition());
    //clone Agent + add to vector<Agent>
    Agent cloneAgent = chosenAgent;
    cloneAgent.setPartyId(mId);
    cloneAgent.setId(s.getAgents().size());
    s.addAgent(cloneAgent);
}






