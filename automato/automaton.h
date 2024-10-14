#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <vector>
#include <map>
#include <string>

struct STATE {
    int id;
    bool is_accepting;
    bool is_initial;
    std::map<char, std::vector<STATE*>> transitions;
};

class Automaton {
private:
    std::vector<STATE> states;
    std::vector<char> symbols;
    std::vector<STATE*> initial_states;
    int num_states;
    int num_symbols;

    // Helper function to process lambda transitions
    void processLambdaTransitions(std::vector<STATE*>& current_states);

public:
    Automaton(int n, int m);

    void setSymbols(const std::vector<char>& s);
    void setInitialStates(const std::vector<int>& init_states);
    void setAcceptingStates(const std::vector<int>& accepting_states);

    void addTransition(int from, char symbol, int to);
    
    // Simulate the automaton for a given input string
    // Returns true if the input is accepted, false otherwise
    bool simulate(const std::string& input);
};

#endif
