SRC=main3G.C image.C sink.C source.C PNMreader.C PNMwriter.C filters.C filter.C logging.C
OBJ=$(SRC:.C=.o)

prog: $(OBJ)
	g++ $(OBJ) -o proj3G

.C.o: $<
	g++  -g -I. -c $<

run:
	./proj3G 3B_input.pnm output.pnm
	open output.pnm
	cat proj3G_checksum

clean:
	rm *.o proj3G logger.txt output.pnm proj3G_checksum
