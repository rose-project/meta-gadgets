DESCRIPTION = "libdcadec  DTS Coherent Acoustics decoder with support for HD extensions"
LICENSE = "LGPL-2.1"
LIC_FILES_CHKSUM = "file://COPYING.LGPLv2.1;md5=4fbd65380cdd255951079008b364516c"

PR = "r0"
inherit autotools pkgconfig

SRC_URI = "git://github.com/foo86/dcadec.git"
SRCREV = "0e074384c9569e921f8facfe3863912cdb400596"

S = "${WORKDIR}/git"

do_configure_append() {
  sed -i 's,%PREFIX%,/,;s,%LIBDIR%,${libdir},;s,%INCLUDEDIR%,${includedir},' ${S}/dcadec.pc.in
}

do_compile_prepend() {
  #export CONFIG_SHARED=1
  export PREFIX=${D}/usr/
  cd ${S}
}

do_install() {
   #export CONFIG_SHARED=1
   export PREFIX=${D}/usr
   cd ${S}
   install -d ${D}/usr/lib
   install -d ${D}/usr/include
   make install
}

FILES_${PN}-dev += " \
  ${includedir}/${PN} \
  ${libdir}/pkgconfig/dcadec.pc \
  "
