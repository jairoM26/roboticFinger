kmod = roboticArmKM
ifneq ($(KERNELRELEASE),)
obj-m := $(kmod).o
else

KDIR ?= /lib/modules/$$(uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$$PWD modules

load:
	sudo insmod $(kmod).ko

unload:
	sudo rmmod $(kmod).ko

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

.PHONY  : clean
endif

