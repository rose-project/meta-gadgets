DESCRIPTION = "Kodi - Media player and entertainment system"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE.GPL;md5=930e2a5f63425d8dd72dbd7391c43c46"

BRANCH = "Jarvis"
SRCREV="a6d8b948448985d8ab27e96d66e1214a855e50f5"

PR = "r1"

BBCLASSEXTEND = "native"

SRC_URI = "git://github.com/xbmc/xbmc.git;branch=${BRANCH}"
S = "${WORKDIR}/git/"

inherit autotools lib_package pkgconfig gettext native

DEPENDS = "curl-native \
           cmake-native "

do_configure() {
	 cd ${S}/tools/depends/
   ./bootstrap
	 ./configure --prefix=${STAGING_DIR_NATIVE}
}

do_compile() {
  cd ${S}/tools/depends/native
  make JsonSchemaBuilder
}

do_install() {
  ln -s ${STAGING_DIR_NATIVE}/${BUILD_SYS}-gnu-native/bin/JsonSchemaBuilder ${STAGING_DIR_NATIVE}/bin/JsonSchemaBuilder
}
