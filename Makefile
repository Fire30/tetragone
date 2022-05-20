default: compile

directories:
	mkdir -p build
	mkdir -p bin

compile_root_payload: directories
	gcc -std=gnu99 -DDEBUG  -Iinclude/ src/root_payload.c -o build/root_payload -Wall -Werror -lpthread
	xxd -i -a build/root_payload > build/root_payload.h
	sed -i -e 's/unsigned/static unsigned/g' build/root_payload.h
	sed -i 's/build_root_payload/root_payload/g' build/root_payload.h
	cp build/root_payload.h include/

compile: compile_root_payload .FORCE
	gcc -std=gnu99 -m32 -DDEBUG  -Iinclude/ src/tetragone.c -o bin/tetragone -Wall -Werror -lpthread

run: compile
	./bin/tetragone

clean:
	rm -rf build
	rm -rf bin
	rm -rf tetragone
	rm -rf include/root_payload.h

.FORCE:
