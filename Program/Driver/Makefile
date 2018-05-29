module = roboticArmKM
ifneq ($(KERNELRELEASE),)
obj-m := $(module).o
else

module_dir ?= /lib/modules/$$(uname -r)/build

all:
	$(MAKE) -C $(module_dir) M=$$PWD modules

load:
	sudo insmod $(module).ko

unload:
	sudo rmmod $(module).ko

clean:
	$(MAKE) -C $(module_dir) M=$$PWD clean

read:
	tail -f /var/log/kern.log 

.PHONY  : clean
endif

