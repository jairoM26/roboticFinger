all:
	gcc -c roboticArmLib.c -I ./ -fPIC # compila biblioteca
	ar rv roboticArmLib.a roboticArmLib.o # crea biblioteca estatica

clean:
	rm roboticArmLib.a roboticArmLib.o