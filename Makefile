all:
	g++ -Wall -I libs/include -L libs/lib -o renderer src/*.c -lmingw32 -lSDL2main -lSDL2 

run:
	./renderer

clean:
	del renderer.exe