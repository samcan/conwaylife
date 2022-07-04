SOURCE	= src/life.cpp src/ConwayLifeArray.cpp src/ImageView.cpp
HEADER	= 
OUT	= bin/life
CC	 = g++
FLAGS	 = -g -Wall
LFLAGS	 = 

all: $(SOURCE)
	$(CC) $(FLAGS) -std=c++17 $(SOURCE) -o $(OUT)

clean:
	rm -f $(OUT)
