#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <iostream>
#include <vector>
#include <set>
#include "../state/state.h"

class Automaton {
private:
    std::vector<State> states; // Set of states in the automaton
    State* initial;            // Initial state of the automaton

public:
    // Constructor
    Automaton(int num_states);

    // Add a transition to the automaton
    void insert_transition(unsigned int from, char symbol, unsigned int to);

    // Set the initial state of the automaton
    void initial_state(unsigned int initial_state);

    // Set the accepting states of the automaton
    void accepting_states(const std::set<unsigned int>& accepting_states);

    // Check if the automaton accepts the input
    bool accepts(const std::string& input);
};

#endif // AUTOMATON_H
