GCC_PATH=/home/qxw/projects/OpenWifi/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin

KDIR =/usr/src/linux-headers-$(shell uname -r)

# 增加linux扩展包
#CFLAGS+=-I/usr/src/linux-headers-4.2.0-27-generic/include

WifiManager: WifiManager.o
	$(GCC_PATH)/mips-openwrt-linux-gcc $(LDFLAGS) WifiManager.o -o WifiManager
WifiManager.o: WifiManager.c
	echo $(CFLAGS)
	$(GCC_PATH)/mips-openwrt-linux-gcc $(CFLAGS) -c WifiManager.c
clean:
	rm *.o WifiManager
