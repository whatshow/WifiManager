cmd_/home/qxw/projects/OpenWifi/build_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/nfsd/.install := bash scripts/headers_install.sh /home/qxw/projects/OpenWifi/build_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/nfsd ./include/uapi/linux/nfsd cld.h debug.h export.h nfsfh.h stats.h; bash scripts/headers_install.sh /home/qxw/projects/OpenWifi/build_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/nfsd ./include/linux/nfsd ; bash scripts/headers_install.sh /home/qxw/projects/OpenWifi/build_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/nfsd ./include/generated/uapi/linux/nfsd ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/qxw/projects/OpenWifi/build_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/nfsd/$$F; done; touch /home/qxw/projects/OpenWifi/build_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2/linux-dev//include/linux/nfsd/.install