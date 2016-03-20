# s.a. https://github.com/alfonsotames/meta-kodi/blob/master/recipes-kodi/images/kodi-image.bb

DESCRIPTION = "Kodi - Media player and entertainment system"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE.GPL;md5=930e2a5f63425d8dd72dbd7391c43c46"

DEPENDS = " \
	alsa-lib \
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
	mariadb \
	libass \
	libdcadec \
	libcrossguid \
	libtinyxml \
	yajl \
	gettext \
	samba \
  "
# todo: libbluray

# libfslvpuwrap
# python-elementtree
# libass
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
SRC_URI = "git://github.com/xbmc/xbmc.git;branch=${BRANCH} \
           file://0001-use-pkginfo.patch \
					 file://0001-dont-do-static-detection.patch \
					 file://0001-ass_crosscompile.patch \
					 file://0001-run-swig-without-java-support.patch \
					 file://0001-smbclient-dont-use-host-system.patch \
					 file://0001-dont-seek-intl.patch \
					 "

S = "${WORKDIR}/git/"

inherit pkgconfig gettext cmake

FILES_${PN} += "/usr/share/icons/hicolor"

OECMAKE_SOURCEPATH = "${S}/project/cmake/"
EXTRA_OECMAKE = " \
  -DDEPENDS_PATH=${STAGING_DIR_TARGET}/usr \
	-DNATIVEPREFIX=${STAGING_DIR_NATIVE} \
	-DENABLE_VAAPI=OFF \
	-DENABLE_VDPAU=OFF \
	-DENABLE_OPTICAL=OFF \
	-DENABLE_X11=OFF \
	-DENABLE_CEC=OFF \
	-DENABLE_AIRTUNES=OFF \
	-DENABLE_PLIST=OFF \
	-DENABLE_BLURAY=OFF \
	-DENABLE_MICROHTTPD=OFF \
	-DENABLE_DVDCSS=OFF \
	"
