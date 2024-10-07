#include "state.h"

// Constructors
State::State(int id) : id(id), is_accepting(false) {}
State::State(int id, bool is_accepting) : id(id), is_accepting(is_accepting) {}

// Add a transition to the state
void State::add_transition(char symbol, State* next_state) {
    transitions[symbol].insert(next_state);
}

// Set the state as accepting
void State::set_accepting(bool is_accepting) {
    is_accepting = is_accepting;
}

// Check if the state is accepting
bool State::accepts() {
    return is_accepting;
}

// Get neighbours of the state
std::set<State*> State::neighbours(char symbol) {
    return transitions[symbol];
}