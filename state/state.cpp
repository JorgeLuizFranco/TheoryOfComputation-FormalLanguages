#include "state.h"

// Constructors
State::State(int id, bool is_accepting) : id(id), is_accepting(is_accepting) {}

// Add a transition to the state
void State::add_transition(char symbol, State* next_state) {
    transitions[symbol].push_back(next_state);
}

// Set the state as accepting
void State::set_accepting(bool is_accepting) {
    this->is_accepting = is_accepting;
}

// Check if the state is accepting
bool State::accepts() {
    return is_accepting;
}

// Get neighbors of the state
std::vector<State*> State::neighbours(char symbol) {
    return transitions[symbol];
}
