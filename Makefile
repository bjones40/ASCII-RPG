all: Boulder_Stew

Boulder_Stew: Boulder_Stew2.cpp UI.cpp Classes.cpp Combat2.cpp
	g++ -g -lncurses Boulder_Stew2.cpp UI.cpp Classes.cpp Combat2.cpp -o Boulder_Stew

clean:
	rm -f Boulder_Stew
