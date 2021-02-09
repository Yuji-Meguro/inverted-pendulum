TARGET = main
SUB = inverted-pendulum simulation graphics equation-state pole-assignment

EXE=$(addsuffix .out,$(TARGET))
OBJ=$(addsuffix .o,$(TARGET))
SUBOBJ=$(addsuffix .o,$(SUB))
EXE +=  $(OBJ) $(SUBOBJ)

LDFLAGS += -lglut -lGLU -lGL -lXmu -lXi -lXext -lX11 -lm -lpthread

all: $(EXE)

%.out: %.o $(SUBOBJ)
	$(CXX) -O -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -O -o $@ -c $<

clean:
	$(RM) *.out *.o