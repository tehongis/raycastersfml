run 	: runme
		./runme

main.o	:	main.cpp
	g++ -c main.cpp

runme	: main.o
	g++ main.o -o runme -lGL -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

clean	:
		rm -rf runme main.o
