MODULE_NAME=dawidModule
obj-m += $(MODULE_NAME).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
start:
	sudo insmod $(MODULE_NAME).ko
stop:
	sudo rmmod $(MODULE_NAME).ko
info:
	sudo lsmod | grep $(MODULE_NAME)
test:
	sudo rmmod $(MODULE_NAME).ko
	sudo insmod $(MODULE_NAME).ko
	cat /dev/dawid
	echo -n "test" > /dev/dawid
	cat /dev/dawid
