CC = g++
CFLAGS = -Wall -Wextra -Werror
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.cpp=obj/%.o)
HEADERS = $(wildcard headers/*.h)

all : check $(OBJ)
	$(CC) $(CFLAGS) -o Challenge48h $(OBJ) $(LIBS)

obj/%.o : src/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

packages :
	sudo apt-get install libsfml-dev -y

check :
ifneq ($(wildcard obj/.*),)
	@echo "Found obj."
else
	@echo "Did not find obj."
	mkdir obj
endif

clean : 
	rm -f obj/*.o Challenge48h
