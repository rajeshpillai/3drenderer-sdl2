all:
	g++ -I libs/include -L libs/lib -o main src/main.c -lmingw32 -lSDL2main -lSDL2 

