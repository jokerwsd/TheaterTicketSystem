CC = g++
EXE = Theater
OBJ = main.o Ticket.o Locat.o TheaterBase.o

$(EXE) : $(OBJ)
	$(CC) -std=c++11 -o $(EXE) $(OBJ)

main.o : main.cpp TheaterBase.h Ticket.h Locat.h
	$(CC) -std=c++11 -c main.cpp
	
Locat.o : Locat.cpp Locat.h
	$(CC) -std=c++11 -c Locat.cpp

TheaterBase.o : TheaterBase.cpp TheaterBase.h Ticket.h Locat.h
	$(CC) -std=c++11 -c TheaterBase.cpp

Ticket.o : Ticket.cpp Ticket.h Locat.h
	$(CC) -std=c++11 -c Ticket.cpp

.PHONY : clean
clean :
	rm $(OBJ)
	rm *.txt




