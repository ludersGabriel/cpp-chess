parametrosCompilacao=-Wall -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -g
gg=gg

OBJ = main.o glad.o stb_image.o Engine.o Shader.o Renderable.o ChessBoard.o Renderer.o

all: $(gg)

$(gg): $(OBJ)
	g++ -o $(gg) $(OBJ) $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp -Iinclude $(parametrosCompilacao)

glad.o: glad.c
	g++ -c glad.c -Iinclude $(parametrosCompilacao)

stb_image.o: stb_image.h stb_image.cpp
	g++ -c stb_image.cpp -Iinclude $(parametrosCompilacao)

Engine.o: Engine.cpp Engine.hpp
	g++ -c Engine.cpp -Iinclude $(parametrosCompilacao)

Renderable.o: Renderable.cpp Renderable.hpp
	g++ -c Renderable.cpp -Iinclude $(parametrosCompilacao)

Shader.o: Shader.cpp Shader.hpp
	g++ -c Shader.cpp -Iinclude $(parametrosCompilacao)

ChessBoard.o: ChessBoard.cpp ChessBoard.hpp
	g++ -c ChessBoard.cpp -Iinclude $(parametrosCompilacao)

Renderer.o: Renderer.cpp Renderer.hpp
	g++ -c Renderer.cpp -Iinclude $(parametrosCompilacao)

run:
	./$(gg)

clean:
	rm -f *.o *.gch $(gg)
