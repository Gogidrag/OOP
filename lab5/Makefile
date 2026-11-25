CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic

all:
	mkdir -p output
	$(CXX) $(CXXFLAGS) main.cpp -o output/main

run: all
	./output/main

docs:
	doxygen Doxyfile

uml:
	plantuml polygon.puml

clean:
	rm -f output/main

.PHONY: all run docs uml clean
