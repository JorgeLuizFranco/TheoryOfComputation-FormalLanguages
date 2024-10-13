#include <iostream>
#include <vector>
#include <set>
#include "automato/automaton.h"

int main() {
    // Read number of states
    int numStates;
    std::cin >> numStates;

    Automaton automaton(numStates);

    // Read alphabet
    int alphabetSize;
    std::cin >> alphabetSize;
    std::vector<char> alphabet(alphabetSize);
    for (int i = 0; i < alphabetSize; i++) {
        std::cin >> alphabet[i];
    }

    // Read initial states
    int numInitialStates;
    std::cin >> numInitialStates;
    for (int i = 0; i < numInitialStates; i++) {
        int state;
        std::cin >> state;
        automaton.initial_state(state);
    }

    // Read accepting states
    int numAcceptingStates;
    std::cin >> numAcceptingStates;
    std::set<unsigned int> acceptingStates;
    for (int i = 0; i < numAcceptingStates; i++) {
        int state;
        std::cin >> state;
        acceptingStates.insert(state);
    }
    automaton.accepting_states(acceptingStates);

    // Read transitions
    int numTransitions;
    std::cin >> numTransitions;
    for (int i = 0; i < numTransitions; i++) {
        int fromState, toState;
        char symbol;
        std::cin >> fromState >> symbol >> toState;
        automaton.insert_transition(fromState, symbol, toState);
    }

    // Read test strings
    int numTestStrings;
    std::cin >> numTestStrings;
    for (int i = 0; i < numTestStrings; i++) {
        std::string inputString;
        std::cin >> inputString;

        if (automaton.accepts(inputString)) {
            std::cout << "aceita" << std::endl;
        } else {
            std::cout << "rejeita" << std::endl;
        }
    }

    return 0;
}
