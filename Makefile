all: mtmaintest Stone_Soup

mtmaintest: mtmaintest.cpp
	g++ -g -lncurses mtmaintest.cpp -o mtmaintest

Stone_Soup: Stone_Soup2.cpp UI.cpp Classes.cpp Combat2.cpp
	g++ -g -lncurses Stone_Soup2.cpp UI.cpp Classes.cpp Combat2.cpp -o Stone_Soup

clean:
	rm -f mtmaintest Stone_Soup
