#include "automaton.h"

// Constructor
Automaton::Automaton(int num_states) {
    for (int i = 0; i < num_states; i++) {
        State state(i);
        states.emplace_back(state);
    }
}

// Add a transition to the automaton
void Automaton::insert_transition(unsigned int from, char symbol, unsigned int to) {
    states[from].add_transition(symbol, &states[to]);
}

// Set the initial state of the automaton
void Automaton::initial_state(unsigned int initial_state) {
    initial = &states[initial_state];
}

// Set the accepting states of the automaton
void Automaton::accepting_states(const std::set<unsigned int>& accepting_states) {
    for (auto state : accepting_states) {
        states[state].set_accepting();
    }
}

// Check if the automaton accepts the input
bool Automaton::accepts(const std::string& input) {
    std::set<State*> current_states = {initial};

    for (char symbol : input) {
        std::set<State*> next_states;
        for (auto state : current_states) {
            auto neighbours = state->neighbours(symbol);
            next_states.insert(neighbours.begin(), neighbours.end());
        }

        if (next_states.empty()) {
            return false;
        }

        current_states = next_states;
    }

    for (auto state : current_states) {
        if (state->accepts()) {
            return true;
        }
    }

    return false;
}
