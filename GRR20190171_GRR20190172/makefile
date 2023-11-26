parametrosCompilacao=-Wall -std=c++20
parametrosBoost = -lboost_system -lboost_filesystem -lboost_thread -pthread
gg=gg

OBJ = main.o Bishop.o Board.o King.o Knight.o Pawn.o Piece.o Queen.o Rook.o Square.o Game.o Cpu.o Interface.o PieceFactory.o

all: $(gg)

$(gg): $(OBJ)
	g++ -o $(gg) $(OBJ) $(parametrosCompilacao) $(parametrosBoost)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Bishop.o: Bishop.cpp Bishop.hpp
	g++ -c Bishop.cpp $(parametrosCompilacao)

Board.o: Board.cpp Board.hpp
	g++ -c Board.cpp $(parametrosCompilacao)

King.o: King.cpp King.hpp
	g++ -c King.cpp $(parametrosCompilacao)

Knight.o: Knight.cpp Knight.hpp
	g++ -c Knight.cpp $(parametrosCompilacao)

Pawn.o: Pawn.cpp Pawn.hpp
	g++ -c Pawn.cpp $(parametrosCompilacao)

Piece.o: Piece.cpp Piece.hpp
	g++ -c Piece.cpp $(parametrosCompilacao)

Queen.o: Queen.cpp Queen.hpp
	g++ -c Queen.cpp $(parametrosCompilacao)

Rook.o: Rook.cpp Rook.hpp
	g++ -c Rook.cpp $(parametrosCompilacao)

Square.o: Square.cpp Square.hpp
	g++ -c Square.cpp $(parametrosCompilacao)

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp $(parametrosCompilacao)


Cpu.o: Cpu.cpp Cpu.hpp
	g++ -c Cpu.cpp $(parametrosCompilacao) 

Interface.o: Interface.cpp Interface.hpp
	g++ -c Interface.cpp $(parametrosCompilacao) 

PieceFactory.o: PieceFactory.cpp PieceFactory.hpp
	g++ -c PieceFactory.cpp $(parametrosCompilacao) 

run:
	./$(gg)

clean:
	rm -f *.o *.gch $(gg)
