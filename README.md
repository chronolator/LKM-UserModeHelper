# LKM-UserModeHelper
Kernel Version: 2.6.x / 3.x / 4.x / 5.x  
Linux Kernel Module (LKM) example of calling a userland process/program.

## Dependencies
Ensure kernel headers, kernel dev packagesm and gcc is installed before building.  

Deb-based Systems:  
```
apt install linux-headers-$(uname -r) build-essential -y
```

RHEL-based Systems:  
```
yum install kernel kernel-devel kernel-headers gcc -y
```

## Install
Clone repository:  
```
git clone https://github.com/chronolator/LKM-UserModeHelper.git
```

Enter folder:  
```
cd LKM-UserModeHelper
```

Build the module:  
```
make
```

Clear dmesg:
```
dmesg --clear
```

Load the module as root:  
```
insmod ./usermodehelper.ko
```

To view the UserModeHelper output:  
```
dmesg -T --color
```

## Uninstall
Unload the module as root:  
```
rmmod usermodehelper
```
