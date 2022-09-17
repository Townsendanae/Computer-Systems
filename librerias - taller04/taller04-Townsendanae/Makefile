hash: libsha1.a main.c
	#TODO: Compilación con linking estático
	gcc -static -o hash main.c ./libsha1.a

hash_dyn: libsha1.so main.c
	#TODO: Compilación con linking dinámico
	#incluir al comando -->  -Wl,-rpath,. -L. -lsha1
	gcc -o hash_dyn main.c libsha1.so -Wl,-rpath,. -L. -lsha1
.PHONY: clean
clean:
	rm -rf hash hash_dyn
