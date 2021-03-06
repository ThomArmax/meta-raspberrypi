include conf/machine/include/rpi-default-settings.inc
include conf/machine/include/rpi-default-versions.inc
include conf/machine/include/rpi-default-providers.inc

SOC_FAMILY = "rpi"
include conf/machine/include/soc-family.inc

IMAGE_FSTYPES ?= "tar.bz2 ext3 rpi-sdimg"

SERIAL_CONSOLE = "115200 ttyAMA0"

XSERVER = " \
    xserver-xorg \
    xf86-input-evdev \
    xf86-input-mouse \
    xf86-input-keyboard \
    xf86-video-fbdev \
    "

KERNEL_DEVICETREE_3.18.y = " \
    ds1307-rtc-overlay.dtb \
    hifiberry-amp-overlay.dtb \
    hifiberry-dac-overlay.dtb \
    hifiberry-dacplus-overlay.dtb \
    hifiberry-digi-overlay.dtb \
    iqaudio-dac-overlay.dtb \
    iqaudio-dacplus-overlay.dtb \
    lirc-rpi-overlay.dtb \
    pcf8523-rtc-overlay.dtb \
    pps-gpio-overlay.dtb \
    w1-gpio-overlay.dtb \
    w1-gpio-pullup-overlay.dtb \
    "

KERNEL_DEVICETREE_4.1.y = " \
    overlays/hifiberry-amp-overlay.dtb \
    overlays/hifiberry-dac-overlay.dtb \
    overlays/hifiberry-dacplus-overlay.dtb \
    overlays/hifiberry-digi-overlay.dtb \
    overlays/i2c-rtc-overlay.dtb \
    overlays/iqaudio-dac-overlay.dtb \
    overlays/iqaudio-dacplus-overlay.dtb \
    overlays/lirc-rpi-overlay.dtb \
    overlays/pps-gpio-overlay.dtb \
    overlays/w1-gpio-overlay.dtb \
    overlays/w1-gpio-pullup-overlay.dtb \
    overlays/rpi-ft5406-overlay.dtb \
    "

# Really supported starting from linux-raspberrypi 3.18.y only
KERNEL_DEVICETREE ?= " \
    bcm2708-rpi-b.dtb \
    bcm2708-rpi-b-plus.dtb \
    bcm2709-rpi-2-b.dtb \
    ${@bb.utils.contains('PREFERRED_VERSION_linux-raspberrypi', '3.18.%', '${KERNEL_DEVICETREE_3.18.y}', '', d)} \
    ${@bb.utils.contains('PREFERRED_VERSION_linux-raspberrypi', '4.1.%', '${KERNEL_DEVICETREE_4.1.y}', '', d)} \
    "
KERNEL_IMAGETYPE ?= "Image"

MACHINE_FEATURES = "kernel26 apm usbhost keyboard vfat ext2 screen touchscreen alsa bluetooth wifi sdio"

# Raspberry Pi has no hardware clock
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

MACHINE_EXTRA_RRECOMMENDS += " kernel-modules"

# Set Raspberrypi splash image
SPLASH = "psplash-raspberrypi"

IMAGE_BOOT_FILES ?= "bcm2835-bootfiles/* ${KERNEL_IMAGETYPE};${SDIMG_KERNELIMAGE}"
