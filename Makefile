gcc_options = -std=c++2a -Wall --pedantic-errors

main: main.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

all.h.gch: all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

run: main
	./main

clean:
	rm -f ./main
	rm -f ./all.h.gch

.PHONY: run clean