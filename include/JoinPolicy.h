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
          ~MandatesJoinPolicy() = default;
          int join(vector<int> &offers, vector<int> &mandatesOfCoalition) override;
};

class LastOfferJoinPolicy : public JoinPolicy {
     public:
          ~LastOfferJoinPolicy() = default;
          int join(vector<int> &offers, vector<int> &mandatesOfCoalition) override;
};