CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = automaton

all: $(TARGET)

$(TARGET): main.o automato/automaton.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o automato/automaton.o

main.o: main.cpp automato/automaton.h
	$(CXX) $(CXXFLAGS) -c main.cpp

automato/automaton.o: automato/automaton.cpp automato/automaton.h
	$(CXX) $(CXXFLAGS) -c automato/automaton.cpp -o automato/automaton.o

clean:
	rm -f *.o automato/*.o $(TARGET)
