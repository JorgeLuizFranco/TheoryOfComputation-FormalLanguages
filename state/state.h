#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <map>
#include <vector>
#include <set>

class State {
private:
    int id;
    bool is_accepting;
    std::map<char, std::vector<State*>> transitions;

public:
    // Constructor
    State(int id, bool is_accepting = false);

    // Set the state as accepting
    void set_accepting(bool is_accepting = true);

    // Check if the state is accepting
    bool accepts();

    // Add a transition to the state
    void add_transition(char symbol, State* state);

    // Get neighbors of the state
    std::vector<State*> neighbours(char symbol);
};

#endif // STATE_H
