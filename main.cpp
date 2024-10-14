#include <iostream>
#include <vector>
#include <set>
#include "automato/automaton.h"

int main() {
    int num_states;
    std::cin >> num_states;

    int num_symbols;
    std::cin >> num_symbols;

    std::vector<char> symbols(num_symbols);
    for (int i = 0; i < num_symbols; ++i) {
        std::cin >> symbols[i];
    }

    int num_initial_states;
    std::cin >> num_initial_states;

    std::vector<int> initial_states(num_initial_states);
    for (int i = 0; i < num_initial_states; ++i) {
        initial_states[i] = i;
    }

    int num_accepting_states;
    std::cin >> num_accepting_states;

    std::vector<int> accepting_states(num_accepting_states);
    for (int i = 0; i < num_accepting_states; ++i) {
        std::cin >> accepting_states[i];
    }

    int num_transitions;
    std::cin >> num_transitions;

    Automaton automaton(num_states, num_symbols);
    automaton.setSymbols(symbols);
    automaton.setInitialStates(initial_states);
    automaton.setAcceptingStates(accepting_states);

    for (int i = 0; i < num_transitions; ++i) {
        int from, to;
        char symbol;
        std::cin >> from >> symbol >> to;
        automaton.addTransition(from, symbol, to);
    }

    int num_input_strings;
    std::cin >> num_input_strings;

    for (int i = 0; i < num_input_strings; ++i) {
        std::string input;
        std::cin >> input;

        if (automaton.simulate(input)) {
            std::cout << "aceita" << std::endl;
        } else {
            std::cout << "rejeita" << std::endl;
        }
    }

    return 0;
}