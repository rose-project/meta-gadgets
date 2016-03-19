# s.a. https://github.com/alfonsotames/meta-kodi/blob/master/recipes-kodi/images/kodi-image.bb

DESCRIPTION = "Kodi - Media player and entertainment system"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE.GPL;md5=930e2a5f63425d8dd72dbd7391c43c46"

DEPENDS = " \
	alsa-lib \
	python \
	python-distutils \
	python-textutils \
	python-sqlite3 \
	python-pickle \
	python-logging \
	python-curses \
	python-compile \
	python-compiler \
	python-fcntl \
	python-shell \
	python-multiprocessing \
	python-subprocess \
	python-xmlrpc \
	python-netclient \
	python-netserver \
	python-unixadmin \
	python-compression \
	python-json \
	python-unittest \
	python-mmap \
	python-difflib \
	python-pprint \
	python-git \
	python-pkgutil \
	python-pycairo \
	python-mako \
	mpeg2dec \
	boost \
	cmake \
	zlib \
	dbus \
  swig \
	taglib \
	tiff \
	swig-native \
	libxslt \
	flac \
	libvorbis \
	udev \
	curl \
	lzo \
	avahi \
	cairo pango fontconfig freetype \
  libsquish \
	wayland \
	virtual/libgles2 \
	virtual/egl \
  "
# todo: libbluray

# libfslvpuwrap
# python-elementtree
# libass
# mariadb
# libmodplug
# yajl
# libtinyxml
# libtinyxml-native
# libcdio
# jasper
# libssh
# samba
# libmicrohttpd
# rtmpdump
# libplist
# shairplay
# ffmpeg-kodi
# libcec

INC_PR = "r1"
SRC_URI = "git://github.com/xbmc/xbmc.git;branch=${BRANCH}"

S = "${WORKDIR}/git/"

inherit autotools lib_package pkgconfig gettext python-dir

EXTRA_OECONF=" --disable-debug \
	--build=${BUILD_SYS} \
	--host=${HOST_SYS} \
	--target=${TARGET_SYS} \
	--prefix=${D}/opt/kodi \
	--disable-pulse \
	--disable-projectm \
	--disable-x11 \
	--disable-libcec \
	--disable-gl \
	--disable-vdpau \
	--disable-vaapi \
	--disable-openmax \
	--enable-wayland \
	--enable-gles \
	--enable-udev \
	--disable-texturepacker \
	--disable-airplay \
	--disable-airtunes \
	--enable-optimizations \
	--enable-avahi \
	--disable-mid \
	--enable-rsxs \
	--disable-libcec \
	LIBS=' -llzma '"

CXXFLAGS += " -I${STAGING_KERNEL_DIR}/include/uapi -I${STAGING_KERNEL_DIR}/include "
CFLAGS += " -I${STAGING_KERNEL_DIR}/include/uapi -I${STAGING_KERNEL_DIR}/include "

FILES_${PN} += "/usr/share/icons/hicolor"

EXTRA_OEMAKE = "'BUILDDIR=${S}/build'"

do_configure_prepend () {
	export TINYXML_CFLAGS="-I/${STAGING_INCDIR}"
	export TINYXML_LIBS="-L${STAGING_LIBDIR} -ltinyxml"
	export SQUISH_CFLAGS="-I/${STAGING_INCDIR}"
	export SQUISH_LIBS="-L${STAGING_LIBDIR} -lsquish"
	export PYTHON_EXTRA_LDFLAGS=""
	export PYTHON_EXTRA_LIBS="-lz"
	export PYTHON_VERSION="${PYTHON_BASEVERSION}"
	export PYTHON_NOVERSIONCHECK="no-check"
	export PYTHON_CPPFLAGS="-I/${STAGING_INCDIR}/${PYTHON_DIR}"
	export PYTHON_LDFLAGS="-L${STAGING_LIBDIR} -lpython${PYTHON_BASEVERSION}"

  cd ${S}
	./bootstrap
}

do_compile() {
   cd ${S}
   make BUILDDIR=${BUILDDIR} DESTDIR=${D}
}

do_install() {
   cd ${S}
	 install -d ${D}
   make BUILDDIR=${BUILDDIR} DESTDIR=${D} install
}

INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"

PACKAGES = "${PN}"
