CC=g++
IDIR = . -I../src
CPPFLAGS=-fno-access-control -I$(IDIR) -Wall -g -O2

ODIR=.

_OBJ = Main.o UnitTest.o PencilTest.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c -o $@

test: $(OBJ)
	$(CC) -o test $^ $(CPPFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm test.exe
