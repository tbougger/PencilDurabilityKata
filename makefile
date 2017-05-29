CC=g++
IDIR = ./src
TESTIDIR = ./test
CPPFLAGS=-I$(IDIR) -Wall -O2
TESTCPPFLAGS=-fno-access-control -I$(TESTIDIR) -g

ODIR=./src
TESTODIR=./test

_OBJ = Main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
_TESTOBJ = Main.o UnitTest.o PencilTest.o
TESTOBJ = $(patsubst %,$(TESTODIR)/%,$(_TESTOBJ))

$(ODIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c -o $@

$(TESTODIR)/%.o: %.c
	$(CC) $(CPPFLAGS) $(TESTCPPFLAGS) -c -o $@

all: PDK test

PDK: $(OBJ)
	$(CC) -o ./PDK $^ $(CPPFLAGS)

test: $(TESTOBJ)
	$(CC) -o ./test $^ $(CPPFLAGS) $(TESTCPPFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm -f $(TESTODIR)/*.o
	rm PDK.exe
	rm test.exe
