CC = cc
CFLAGS = -Wall -Wextra

all: temp fooball

temp: temp.c
	$(CC) $(CFLAGS) -o temp temp.c
fooball: fooball.c
	$(CC) $(CFLAGS) -o fooball fooball.c
