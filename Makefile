all: Stone_Soup

Stone_Soup: Stone_Soup2.cpp UI.cpp Classes.cpp Combat2.cpp
	g++ -g -lncurses Stone_Soup2.cpp UI.cpp Classes.cpp Combat2.cpp -o Stone_Soup

clean:
	rm -f Stone_Soup
