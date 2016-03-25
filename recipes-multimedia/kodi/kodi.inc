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
	libdvdread \
	virtual/java-native \
   ffmpeg-kodi \
  "

INC_PR = "r1"
SRC_URI = "git://github.com/xbmc/xbmc.git;branch=${BRANCH} \
					 file://0001-add-compiler-flag-pthread-dont-request-git-version.patch \
					 file://0001-dont-search-dependency-ffmpeg-on-external-build.patch \
					 file://0001-fix-library-and-include-search-paths.patch \
					 "

S = "${WORKDIR}/git/"

inherit pkgconfig gettext cmake

FILES_${PN} += "/usr/share/icons/hicolor"

OECMAKE_SOURCEPATH = "${S}/project/cmake/"
EXTRA_OECMAKE = " \
   -DVERBOSE=OFF \
   -DPLATFORM=raspberry-pi \
   -DCORE_SYSTEM_NAME=rbpi \
   -DCPU=cortex-a7 \
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
   -DENABLE_INTERNAL_FFMPEG=OFF \
	"

#ENABLE_INTERNAL_CROSSGUID=OFF

