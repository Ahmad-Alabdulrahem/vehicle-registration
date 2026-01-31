prog: Lab3.o functions.o
          gcc -o styr Lab3.c functions.o


Lab4.o: Lab3.c lab3.h
          gcc -c Lab3.c

functions.o: functions.c lab3.h
          gcc -c functions.c