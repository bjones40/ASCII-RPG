all: mtmaintest

mtmaintest: mtmaintest.cpp
	g++ -g -lncurses mtmaintest.cpp -o mtmaintest

clean:
	rm -f mtmaintest
