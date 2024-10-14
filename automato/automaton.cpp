#include "automaton.h"
#include <iostream>
#include <set>

// Constructor
Automaton::Automaton(int n, int m) : num_states(n), num_symbols(m) {
    for (int i = 0; i < num_states; ++i) {
        states.push_back({i, false, false, {}});
    }
}

// Set the alphabet symbols
void Automaton::setSymbols(const std::vector<char>& s) {
    symbols = s;
}

// Set the initial states
void Automaton::setInitialStates(const std::vector<int>& init_states) {
    for (int state_id : init_states) {
        states[state_id].is_initial = true;
        initial_states.push_back(&states[state_id]);
    }
}

// Set the accepting states
void Automaton::setAcceptingStates(const std::vector<int>& accepting_states) {
    for (int state_id : accepting_states) {
        states[state_id].is_accepting = true;
    }
}

// Add a transition between two states
void Automaton::addTransition(int from, char symbol, int to) {
    states[from].transitions[symbol].push_back(&states[to]);
}

// Helper function to process lambda transitions
void Automaton::processLambdaTransitions(std::vector<STATE*>& current_states) {
    std::set<STATE*> visited;

    std::vector<STATE*> to_process = current_states;

    while (!to_process.empty()) {
        STATE* state = to_process.back();
        to_process.pop_back();

        if (visited.count(state) > 0) {
            continue;
        }
        visited.insert(state);

        // Process lambda transitions
        if (state->transitions.count('-')) {
            for (STATE* next_state : state->transitions['-']) {
                if (visited.count(next_state) == 0) {
                    current_states.push_back(next_state);
                    to_process.push_back(next_state);
                }
            }
        }
    }
}

// Simulate the automaton with a given input string
// Returns true if the input is accepted, false otherwise
bool Automaton::simulate(const std::string& input) {
    std::vector<STATE*> current_states = initial_states;

    // Process lambda transitions
    processLambdaTransitions(current_states);

    for (char symbol : input) {
        // Skip lambda inputs
        if(symbol == '-'){
            continue;
        }

        std::vector<STATE*> next_states;

        for (STATE* state : current_states) {
            if (state->transitions.count(symbol)) {
                for (STATE* next_state : state->transitions[symbol]) {
                    next_states.push_back(next_state);
                }
            }
        }

        if (next_states.empty()) {
            return false;
        }

        current_states = next_states;

        // After each transition, process lambda transitions again
        processLambdaTransitions(current_states);
    }

    for (STATE* state : current_states) {
        if (state->is_accepting) {
            return true;
        }
    }

    return false;
}