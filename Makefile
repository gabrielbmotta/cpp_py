all:
	cmake -B build .
	cmake --build build --parallel 4

clean:
	rm -rf build
