#pragma once
#include <string>
#include<vector>

using std::string;
using std::vector;

class JoinPolicy;
class Simulation;
class Agent;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    //rule of 5
    ~Party();
    Party& operator=(const Party& other);
    Party(const Party &other);
    Party& operator=(Party &&other) noexcept;
    Party(Party &&other) noexcept;


   

    State getState() const;
    void setState(State state);
    int getMandates() const;
    vector <Agent> &getOffers();
    void step(Simulation &s);
    const string &getName() const;
    void  addOffer(Agent &agent);
    void  changeState();
    void  chooseParty(Simulation &s);
    const vector <Agent> getOffers() const;


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    vector<Agent> offers;

};