parametrosCompilacao=-Wall -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
gg=gg

OBJ = main.o glad.o stb_image.o Interface.o Shader.o GameObject.o ChessBoard.o

all: $(gg)

$(gg): $(OBJ)
	g++ -o $(gg) $(OBJ) $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp -Iinclude

glad.o: glad.c
	g++ -c glad.c -Iinclude

stb_image.o: stb_image.h stb_image.cpp
	g++ -c stb_image.cpp -Iinclude

Interface.o: Interface.cpp Interface.hpp
	g++ -c Interface.cpp -Iinclude

GameObject.o: GameObject.cpp GameObject.hpp
	g++ -c GameObject.cpp -Iinclude

Shader.o: Shader.cpp Shader.hpp
	g++ -c Shader.cpp -Iinclude

ChessBoard.o: ChessBoard.cpp ChessBoard.hpp
	g++ -c ChessBoard.cpp -Iinclude

run:
	./$(gg)

clean:
	rm -f *.o *.gch $(gg)
