nome = tp2ex2

all:
	g++ -o $(nome) src/main.cpp src/TFila.h src/TFila.cpp

clean:
	-rm -f *.o *~

run:
	./$(nome)
