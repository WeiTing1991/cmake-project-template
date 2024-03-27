clean:
    find Build/ -type f -maxdepth 1 -deletelean :
run :
	cmake -B build/
	cmake -G "MinGW Makefiles" -S . -B build/

