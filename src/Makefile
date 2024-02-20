CC=g++
CPP=-std=c++17 -lstdc++
EXTRAS=-lm
OS=$(shell uname)
ifeq ($(OS), Linux)
	LEAKS = valgrind --leak-check=full --track-origins=yes -s ./test
	GCOVFLAGS = --coverage
	GTEST=`pkg-config --cflags --libs gtest`
	OPEN=xdg-open
else
	LEAKS = leaks --atExit -- ./test
	GCOVFLAGS = -fprofile-arcs -ftest-coverage
	GTEST=-lm -lgtest
	OPEN=open
endif

# Checks if compiler is not clang since max_size() is deprecated on clang but not gcc
# and will prevent the program from compiling (By default MacOS uses gcc as an alias to clang)
ifneq ($(CXX), c++)
	COMPILE_KILL=-Wall -Wextra -Werror
endif

# This works on linux & on regular mac but may fail on campus macs due to
# their unique configuration
# GTEST=`pkg-config --cflags --libs gtest`
# Try uncommenting this if pkg-config fails
# GTEST=-lm -lgtest

all: clean test codestyle 

test: clean
	$(CC) s21model.cc test.cc $(CPP) $(GTEST) $(EXTRAS) -o test $(COMPILE_KILL)
	./test

gcov_report: clean
	$(CC) $(GCOVFLAGS) s21model.cc test.cc $(CPP) $(GTEST) $(EXTRAS) -o test $(COMPILE_KILL)
	./test
	gcov test_gcov
	lcov -t "s21calc_2" --no-external -o s21calc_2.info -c -d .
	genhtml -o report s21calc_2.info
	$(OPEN) ./report/index.html
	rm -rf *.o test *.gcda *.gcno *.info

install: dist
	cp -rf s21calc_2.pro *.cc *.h *.cpp *.ui *.texi ../build
	cd ../build; qmake s21calc_2.pro
	make -C ../build
	$(OPEN) ../build/

uninstall:
	rm -rf ../build

dist:
	mkdir -p ../build
	tar -cvzf ../build/s21calc_2.tgz Makefile *.cc *.h *.pro *.cpp *.ui *.texi

dvi:
	makeinfo --html documentation.texi
	$(OPEN) ./documentation/index.html

codestyle:
	cp ../materials/linters/.clang-format .
	clang-format -i *.cc *.h
	clang-format -n *.cc *.h
	rm -rf .clang-format
	
check: test
	cppcheck --enable=all --language=c++ --std=c++17 --suppress=unusedFunction --suppress=missingInclude --suppress=unknownMacro --suppress=unmatchedSuppression *.cc
	$(LEAKS)

clean:
	rm -rf *.0 *.a *.gcno *.gcda *.info *.out report *.dSYM *.gch *.o test2.out .vscode .DS_Store *.gcov test_cov test documentation build
