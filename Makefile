CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = automaton

all: $(TARGET)

$(TARGET): main.o automato/automaton.o state/state.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o automato/automaton.o state/state.o

main.o: main.cpp automato/automaton.h
	$(CXX) $(CXXFLAGS) -c main.cpp

automato/automaton.o: automato/automaton.cpp automato/automaton.h state/state.h
	$(CXX) $(CXXFLAGS) -c automato/automaton.cpp -o automato/automaton.o

state/state.o: state/state.cpp state/state.h
	$(CXX) $(CXXFLAGS) -c state/state.cpp -o state/state.o

clean:
	rm -f *.o automato/*.o state/*.o $(TARGET)
