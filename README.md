# KernelBlockDevice
As simple as it gets!

divided into 3 parts:
* dawidModule.c - creating kernel module
* deviceCreation.c - creating,destroying,setting permissions device
* deviceActions.c- read write operations on the device

source: Anil Kumar Pugalia - Device Drivers

# How to use
compile:
```
$ make
```

test module:
```
$ make test
```
this will:
 1. remove loaded module,
 2. insert module, 
 3. read data from device: cat /dev/dawid
 4. write data to decice: echo -n "test" > /dev/dawid
 5. read data fom device: cat /dev/dawid
