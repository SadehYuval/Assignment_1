#pragma once
#include <vector>

using std::vector;

class Agent;

class JoinPolicy{
     public:
          virtual ~JoinPolicy() = default;
          virtual Agent join(vector<Agent> &offers, vector<int> &mandatesOfCoalition) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
     public:
          ~MandatesJoinPolicy();
          Agent join(vector<Agent> &offers, vector<int> &mandatesOfCoalition) override;
};

class LastOfferJoinPolicy : public JoinPolicy {
     public:
          ~LastOfferJoinPolicy();
          Agent join(vector<Agent> &offers, vector<int> &mandatesOfCoalition) override;
};