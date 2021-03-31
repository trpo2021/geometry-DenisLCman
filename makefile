
all:bin/main

bin/main: obj/main.o obj/geometrylib.a
	gcc obj/main.o -Wall -Werror -L. obj/geometrylib.a -o bin/main

obj/main.o:src/main.c
	gcc -c src/main.c -Wall -Werror -o obj/main.o

obj/CheckInjectSpace.o:src/lib/CheckInjectSpace.c
	gcc -c src/lib/CheckInjectSpace.c -Wall -Werror -o obj/CheckInjectSpace.o

obj/OutputError.o:src/lib/OutputError.c
	gcc -c src/lib/OutputError.c -Wall -Werror -o obj/OutputError.o

obj/OutputInfo.o:src/lib/OutputInfo.c
	gcc -c src/lib/OutputInfo.c -Wall -Werror -o obj/OutputInfo.o

obj/Calc_Sq_Perim.o:src/lib/Calc_Sq_Perim.c
	gcc -c src/lib/Calc_Sq_Perim.c -Wall -Werror -o obj/Calc_Sq_Perim.o

obj/geometrylib.a: obj/CheckInjectSpace.o obj/OutputError.o obj/OutputInfo.o obj/Calc_Sq_Perim.o
	ar rcs $@ $^

run:
	./bin/main

clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "main" -exec rm {} \;

.PHONY: clean run all
