GCC = g++
FLAGS = -Wall -O2

BIN = planowanie
SOURCES = Gra Gracz Plansza Karta GraczBot GraczZywy Talia
OBJECTS = $(addsuffix .o, $(SOURCES))

all: $(BIN)

$(OBJECTS): %.o : %.cpp %.h
	$(GCC) $(FLAGS) -c $<

$(BIN): main.cpp $(OBJECTS)
	$(GCC) $(FLAGS) main.cpp $(OBJECTS) -o $(BIN)

clean:
	rm -f $(BIN) *.o
