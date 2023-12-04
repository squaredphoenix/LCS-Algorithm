all: sim lcs

sim: sim.cpp
	g++ -std=c++14 -Wall -Wextra -o sim sim.cpp

lcs: lcs.cpp
	g++ -std=c++14 -Wall -Wextra -o lcs lcs.cpp

clean:
	rm -f *.o sim lcs