CC=g++
IDIR = .
CPPFLAGS=-I$(IDIR) -Wall -O2

ODIR=.

_OBJ = Main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c -o $@

PDK: $(OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
	rm PDK.exe
