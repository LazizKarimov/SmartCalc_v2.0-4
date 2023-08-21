G=g++ -std=c++17
GCC=$(G) -Wall -Wextra
LIBS=-lgtest -lgtest_main -lpthread

SOURCES = SmartCalc2.0/Tests/tests.cc SmartCalc2.0/Model/model.cc

all: install open

tests: clean
	@$(GCC) $(SOURCES) -o test $(LIBS)
	@./test

gcov_report: clean
	$(GCC) --coverage $(SOURCES) -o test $(LIBS)
	chmod +x *
	./test
	lcov --ignore-errors mismatch -t "test" -o test.info --no-external -c -d .
	genhtml -o report/ test.info
	open ./report/index.html

clean:
	@-rm -rf test
	@-rm -rf test.info
	@-rm -rf *.gcda
	@-rm -rf *.gcno
	@-rm -rf report
	@-rm -rf leaks*

leaks: clean
	 @echo .................. testing for leaks ..................
	 @$(GCC) $(SOURCES) -lgtest -o leaks -g
	 CK_FORK=no leaks --atExit -- ./leaks
	 @make clean


clang_format:
	 @echo ------------------ clang-format check -----------------------
	 @cp ../materials/linters/.clang-format .clang-format
	 clang-format -n SmartCalc2.0/*/*.cc SmartCalc2.0/*/*.h
	 @rm .clang-format

install: clean
	 mkdir build
	 cd SmartCalc2.0 && qmake && make && make clean && rm Makefile
	 cd ..
	 mv SmartCalc2.0/SmartCalc.app build
	 rm SmartCalc2.0/.qmake.stash

uninstall:
	 -rm -rf build

dvi:
	 open readme.md

dist:
	 @-rm -rf Archive_SmartCalc_v2.0/
	 @mkdir Archive_SmartCalc_v2.0/
	 @mkdir Archive_SmartCalc_v2.0/src
	 @mv ./build/SmartCalc.app Archive_SmartCalc_v2.0/src/
	 @tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	 @-rm -rf Archive_SmartCalc_v2.0/
	 @-rm -rf build

open:
	 cd build/SmartCalc.app/Contents/MacOS && ./SmartCalc
