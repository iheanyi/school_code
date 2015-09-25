all: otter-swag

otter-swag: main.o timer.o sprite.o background.o otter.o missile.o coin.o fish.o scoreCounter.o menuScreen.o
	g++ main.o timer.o sprite.o background.o otter.o missile.o scoreCounter.o coin.o fish.o menuScreen.o -lSDL -lSDL_mixer -o otter-swag
main.o: main.cpp
	g++ -c main.cpp -lSDL -lSDL_mixer -g
timer.o: timer.cpp
	g++ -c timer.cpp -lSDL -g
sprite.o: sprite.cpp
	g++ -c sprite.cpp -lSDL -g
otter.o: otter.cpp
	g++ -c otter.cpp -lSDL -g
missile.o: missile.cpp
	g++ -c missile.cpp -lSDL -g
coin.o: coin.cpp
	g++ -c coin.cpp -lSDL -g
fish.o: fish.cpp
	g++ -c fish.cpp -lSDL -g
scoreCounter.o: scoreCounter.cpp
	g++ -c scoreCounter.cpp -lSDL -g
menuScreen.o:
	g++ -c menuScreen.cpp -lSDL -g
background.o: background.cpp
	g++ -c background.cpp -lSDL -g
clean:
	rm -f *.o *~ otter-swag
