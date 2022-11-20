#pragma once
#include <vector>

using std::vector;

class Agent;

class JoinPolicy{
     public:
          virtual ~JoinPolicy() = default;
          virtual int join(vector<int> &offers, vector<int> &mandatesOfCoalition) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
     public:
          ~MandatesJoinPolicy();
          int join(vector<int> &offers, vector<int> &mandatesOfCoalition) override;
};

class LastOfferJoinPolicy : public JoinPolicy {
     public:
          ~LastOfferJoinPolicy();
          int join(vector<int> &offers, vector<int> &mandatesOfCoalition) override;
};