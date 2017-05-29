CC=g++
IDIR = ./src
TESTIDIR = ./test
CPPFLAGS=-I$(IDIR) -Wall -O2
TESTCPPFLAGS=-fno-access-control -I$(TESTIDIR) -g

ODIR=./src
TESTODIR=./test

_OBJ = Main.o Paper.o Pencil.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
_TESTOBJ = Main.o UnitTest.o PencilTest.o PaperTest.o
TESTOBJ = $(patsubst %,$(TESTODIR)/%,$(_TESTOBJ))
_TESTIMPORT = Paper.o Pencil.o
TESTIMPORT = $(patsubst %,$(ODIR)/%,$(_TESTIMPORT))

$(ODIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c -o $@

$(TESTODIR)/%.o: %.c
	$(CC) $(CPPFLAGS) $(TESTCPPFLAGS) -c -o $@

all: PDK test

PDK: $(OBJ)
	$(CC) -o ./PDK $^ $(CPPFLAGS)

test: $(TESTOBJ) $(TESTIMPORT)
	$(CC) -o ./test $^ $(CPPFLAGS) $(TESTCPPFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f $(TESTODIR)/*.o
	rm PDK.exe
	rm test.exe
