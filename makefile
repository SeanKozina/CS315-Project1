OBJS	= Main.o Tokenizer.o SocialNetwork.o User.o
SOURCE	= Main.cpp Tokenizer.cpp SocialNetwork.cpp User.cpp
HEADER	= SocialNetwork.h Tokenizer.h User.h
OUT	= Executable
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp 

Tokenizer.o: Tokenizer.cpp
	$(CC) $(FLAGS) Tokenizer.cpp 

SocialNetwork.o: SocialNetwork.cpp
	$(CC) $(FLAGS) SocialNetwork.cpp 

User.o: User.cpp
	$(CC) $(FLAGS) User.cpp 


clean:
	rm -f $(OBJS) $(OUT)
