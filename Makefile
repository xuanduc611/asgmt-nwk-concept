CC = gcc
CPPFLAGS = -Iip_math
CFLAGS = -Wall -O2
RM = rm -f
MAINEXE = test
MAINDEP = ip_math/ip_math.h
MAINOBJS = test.o ip_math/ip_math.o

all : $(MAINEXE)

# Generate output and link object files
$(MAINEXE): $(MAINOBJS)
	$(CC) $(MAINOBJS) -o $@ -lm

$(MAINOBJS): $(MAINDEP)

clean:
	$(RM) $(MAINEXE) $(MAINOBJS) *.out

.PHONY: all clean