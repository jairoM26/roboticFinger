all:
	@cd Driver/ && make
	@cd Driver/ && make load
	@cd Library/ && make
	@cd Interprete/ && make

run:
	@cd Interprete/ && sudo ./roboticFinger -c configFile.txt

runGui:
	@cd GUI/ && python3 gui.py

install:
	sudo usermod -a -G dialout $(USER)
	sudo chmod a+rw /dev/ttyACM0
	sudo chmod a+rw /dev/roboticArm
	sudo apt-get install python3-tk
	

clean:
	@cd Driver/ && make unload
	@cd Driver/ && make clean
	@cd Library/ && make clean
	@cd Interprete/ && make clean