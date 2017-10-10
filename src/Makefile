GCC_PATH=/home/qxw/projects/OpenWifi/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/bin

WifiManager: WifiManager.o
	$(GCC_PATH)/mips-openwrt-linux-gcc $(LDFLAGS) WifiManager.o -o WifiManager
WifiManager.o: WifiManager.c
	$(GCC_PATH)/mips-openwrt-linux-gcc $(CFLAGS) -c WifiManager.c
clean:
	rm *.o WifiManager
