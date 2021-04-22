
all:bin/main

bin/main: obj/src/main.o obj/lib/geometrylib.a
	gcc obj/src/main.o -Wall -Werror -L. obj/lib/geometrylib.a -o $@

obj/src/main.o:src/main.c
	gcc -c src/main.c -Wall -Werror -o $@

obj/src/CheckInjectSpace.o:src/lib/CheckInjectSpace.c
	gcc -c src/lib/CheckInjectSpace.c -Wall -Werror -o $@

obj/src/OutputError.o:src/lib/OutputError.c
	gcc -c src/lib/OutputError.c -Wall -Werror -o $@

obj/src/OutputInfo.o:src/lib/OutputInfo.c
	gcc -c src/lib/OutputInfo.c -Wall -Werror -o $@

obj/src/Calc_Sq_Perim.o:src/lib/Calc_Sq_Perim.c
	gcc -c src/lib/Calc_Sq_Perim.c -Wall -Werror -o $@

obj/src/FigureSection.o:src/lib/FigureSection.c
	gcc -c src/lib/FigureSection.c -Wall -Werror -o $@

test: bin/test
	./bin/test

bin/test: obj/test/main.o obj/test/calctest.o obj/test/testFigure.o obj/test/testInput.o obj/lib/geometrylib.a
	gcc obj/test/main.o obj/test/calctest.o obj/test/testFigure.o obj/test/testInput.o -Wall -Werror -L. obj/lib/geometrylib.a -o bin/test -I thirdparty -I src/lib

obj/test/main.o: test/main.c
	gcc -c $< -Wall -Werror -o $@ -I thirdparty -I src/lib

obj/test/calctest.o: test/calctest.c
	gcc -c $< -Wall -Werror  -o $@ -I thirdparty -I src/lib

obj/test/testFigure.o: test/testFigure.c
	gcc -c $< -Wall -Werror  -o $@ -I thirdparty -I src/lib

obj/test/testInput.o: test/testInput.c
	gcc -c $< -Wall -Werror  -o $@ -I thirdparty -I src/lib

obj/lib/geometrylib.a: obj/src/CheckInjectSpace.o obj/src/OutputError.o obj/src/OutputInfo.o obj/src/Calc_Sq_Perim.o obj/src/FigureSection.o
	ar rcs $@ $^
	
run:
	./bin/main

clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "main" -exec rm {} \;
	find . -name "test" -exec rm {} \;

.PHONY: clean run all
