CC=g++
CFLAGS = -Wall -Wextra -Werror -std=c++17 -g
LINUX_FLAGS = -lm -lncurses -lcheck -lsubunit -lm -lrt -lpthread
MACOS_FLAGS = -lm -lncurses
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

ifeq ($(shell uname), Linux)
    LDFLAGS = $(LINUX_FLAGS)
endif
ifeq ($(shell uname), Darwin)
    LDFLAGS = $(MACOS_FLAGS)
endif

all:	install

install:
	mkdir -p build
	$(CC) $(CFLAGS) brick_game/*/*.c* gui/cli/*.c* -o tetris $(LDFLAGS) -o build/tetris
	echo 0 > build/the_best_score.txt
	rm -rf temp
	mkdir temp
	cd temp && qmake ../gui/desktop/s*
	cd temp && make
	cp temp/snake_game build
	
	rm -rf temp

uninstall:
	rm -rf build
desktop:
	rm -rf temp
	mkdir temp
	cd temp && qmake ../gui/desktop/s*
	cd temp && make
	cd temp && ./snake_game
	rm -rf temp

gcov_report:  
	$(CC) $(CFLAGS)  brick_game/*/sn*.c* tests/*.cpp   $(LDFLAGS) -fprofile-arcs -ftest-coverage -o test -lgtest
	make run_tests
	lcov -c -d . --no-external -o test.info
	genhtml -o report test.info
	open ./report/index.html
	rm -rf test.info *.gcda *.gcno
back.a:
	$(CC) $(CFLAGS) -c brick_game/*/*.c* $(LDFLAGS) 
	ar rc back.a *.o
	rm -rf *.o
test:	back.a
	$(CC) $(CFLAGS) tests/*.cpp -L. back.a  $(LDFLAGS) -fprofile-arcs -ftest-coverage -o test -lgtest
	make run_tests
	
cli: 
	$(CC) $(CFLAGS) brick_game/*/*.c* gui/cli/*.c* -o tetris $(LDFLAGS)
	make run_game

format:
	clang-format -style=google -i */*/*.c* */*/*.h */*/*/*.c* */*/*/*.h tests/*.c*

style:
	clang-format -style=google -n */*/*.c* */*/*.h */*/*/*.c* */*/*/*.h tests/*.c*
valgrind:	back.a
	$(CC) $(CFLAGS) tests/*.cpp -L. back.a  $(LDFLAGS) -fprofile-arcs -ftest-coverage -o test -lgtest
	valgrind --tool=memcheck --leak-check=yes ./test
    
clean:
	rm -rf *.o a.out *.info *.gcda *.gcno  back.a tetris test report temp
run_tests:
	./test
run_game:
	./tetris
dvi:
	open doc.html

dist:
	mkdir -p builder
	cp -a brick_game builder
	cp -a gui builder
	cp -a *.txt builder
	cp -a doc.html builder
	tar -czf Tetris.tar.gz builder
	rm -rf builder	

