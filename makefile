parametrosCompilacao=-Wall
gg=gg

OBJ = main.o 

all: $(gg)

$(gg): $(OBJ)
	g++ -o $(gg) $(OBJ) $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp -Iinclude $(parametrosCompilacao)

run:
	./$(gg)

clean:
	rm -f *.o *.gch $(gg)
