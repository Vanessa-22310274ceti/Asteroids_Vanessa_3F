br : compilar ejecutar

compilar : src/main.cpp
	g++ src/main.cpp -o bin/mascotas -I include

ejecutar : bin/mascotas
	./bin/mascotas

clean : bin/mascotas
	rm bin/mascotas

brA : compilarA ejecutarA

compilarA : src/Asteroids_main.cpp
	g++ src/Asteroids_main.cpp -o bin/Asteroids -I include

ejecutarA : bin/Asteroids
	./bin/Asteroids

cleanA : bin/Asteroids
	rm bin/Asteroids