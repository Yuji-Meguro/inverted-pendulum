TARGET = inverted-pendulum

EXE=$(addsuffix .out,$(TARGET))
OBJ=$(addsuffix .o,$(TARGET))

LDFLAGS += -lglut -lGLU -lGL -lXmu -lXi -lXext -lX11 -lm -lpthread

all: $(EXE)

%.out: %.o
	g++ -O -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	g++ -O -o $@ -c $<

clean:
	rm -rf *.out
	rm -rf *.o