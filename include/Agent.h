#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    //rule of 5
    ~Agent();
    Agent& operator=(const Agent& other);
    Agent(const Agent &other);
    Agent& operator=(Agent &&other) noexcept;
    Agent (Agent &&other) noexcept;


    int getPartyId() const;
    int getId() const;
    int getCoalition() const;
    void step(Simulation &);
    void setCoalition(int c);
    void setPartyId(int partyId);
    void setId(int id);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalition;
};
