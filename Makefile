SOURCE	= src/life.cpp src/ConwayLifeArray.cpp src/ImageView.cpp
HEADER	= 
OUT	= bin/life.exe
CC	 = g++
FLAGS	 = -g -Wall -Wextra
LFLAGS	 = 

all: $(SOURCE)
	$(CC) $(FLAGS) -std=c++17 $(SOURCE) -o $(OUT)

clean:
	rm -f $(OUT)
