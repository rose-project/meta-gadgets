DESCRIPTION = "FFMPEG for Kodi"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE.md;md5=acda96fe91ccaabc9cd9d541806a0d37"

PR = "r0"

inherit autotools pkgconfig gettext

SRC_URI = "git://github.com/xbmc/FFmpeg.git;branch=release/3.0-xbmc"
SRCREV = "bbab50b66f61f38415ea1fbc93314712b90901e2"


S = "${WORKDIR}/git/"

#TODO fix hard coded
# arch
# -march=armv7ve -mfpu=neon-vfpv4  -mfloat-abi=hard -mcpu=cortex-a7


do_configure() {
    cd ${S}
    export PKG_CONFIG_PATH="pkgconfig"
    export CCPREFIX="${STAGING_DIR_TARGET}/usr/lib/${TARGET_PREFIX}"

    ./configure \
        --enable-cross-compile \
        --target-os=linux \
        --arch=armv7ve \
        --cross-prefix=${TARGET_PREFIX} \
        --prefix=/usr \
        --sysroot=${STAGING_DIR_TARGET} \
        --extra-cflags="-I${STAGING_DIR_TARGET}/usr/include ${BUILD_CFLAGS} -march=armv7ve -mfpu=neon-vfpv4  -mfloat-abi=hard -mcpu=cortex-a7" \
        --extra-ldflags="-L${STAGING_DIR_TARGET}/usr/lib" \
        --disable-vdpau \
        --disable-devices \
        --disable-doc \
        --disable-ffplay \
        --disable-ffmpeg \
        --disable-ffprobe \
        --disable-ffserver \
      --disable-sdl \
      --enable-gpl \
      --enable-runtime-cpudetect \
      --enable-postproc \
      --enable-pthreads \
      --enable-muxer=spdif \
      --enable-muxer=adts \
      --enable-muxer=asf \
      --enable-muxer=ipod \
      --enable-encoder=ac3 \
      --enable-encoder=aac \
      --enable-encoder=wmav2 \
      --enable-protocol=http \
      --disable-libdcadec \
      --enable-encoder=png \
      --enable-encoder=mjpeg
}

do_compile_prepend() {
	cd ${S}
}

do_install_prepend() {
	cd ${S}
}
