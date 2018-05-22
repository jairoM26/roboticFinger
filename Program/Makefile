all:
	@cd Driver/ && make
	@cd Driver/ && make load
	@cd Library/ && make
	@cd Interprete/ && make

run:
	@cd Interprete/ && sudo ./roboticFinger -c configFile.txt

runGui:
	@cd GUI/ && python3 gui.py

clean:
	@cd Driver/ && make unload
	@cd Driver/ && make clean
	@cd Library/ && make clean
	@cd Interprete/ && make clean