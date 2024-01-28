OBJS = main.o robot.o humanic.o world.o optimusprime.o robocop.o roomba.o bulldozer.o
SOURCE = main.cpp robot.cpp humanic.cpp world.cpp optimusprime.cpp robocop.cpp roomba.cpp bulldozer.cpp
HEADER = robot.h humanic.h world.h optimusprime.h robocop.h roomba.h bulldozer.h
OUT = robot_fight
CC = g++
FLAGS = -g -c
LFLAGS =
all: run
$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS)
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

robot.o: robot.cpp
	$(CC) $(FLAGS) robot.cpp -std=c++11

humanic.o: humanic.cpp
	$(CC) $(FLAGS) humanic.cpp -std=c++11

world.o: world.cpp
	$(CC) $(FLAGS) world.cpp -std=c++11

optimusprime.o: optimusprime.cpp
	$(CC) $(FLAGS) optimusprime.cpp -std=c++11

robocop.o: robocop.cpp
	$(CC) $(FLAGS) robocop.cpp -std=c++11

roomba.o: roomba.cpp
	$(CC) $(FLAGS) roomba.cpp -std=c++11

bulldozer.o: bulldozer.cpp
	$(CC) $(FLAGS) bulldozer.cpp -std=c++11

run:	$(OUT)
	./$(OUT)

clean:
	rm -f $(OBJS) $(OUT)



