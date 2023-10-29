bin/Asteroids : src/asteroids_main.cpp include/*
	c++ src/asteroids_main.cpp -o bin/Asteroids -lcurses -I include

run: bin/Asteroids
	./bin/Asteroids 