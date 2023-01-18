ppid:
	g++ -o ppid ppid.cpp
	strip ppid

install:
	cp ppid ~/.local/bin/ppid

all: ppid
