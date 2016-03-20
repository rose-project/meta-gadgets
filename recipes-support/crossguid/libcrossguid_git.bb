SUMMARY = "Lightweight cross platform C++ GUID/UUID library"
SECTION = "libs"
PR = "r1"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=1373274bc8d8001edc54933919f36f68"

PROVIDES = "libcrossguid"

DEPENDS = "ossp-uuid"

SRC_URI = "git://github.com/graeme-hill/crossguid.git"



SRCREV = "8f399e8bd4252be9952f3dfa8199924cc8487ca4"

S = "${WORKDIR}/git"

do_compile() {
  cd ${S}
  #${CXX} -std=c++11 -Wall -shared -fPIC -o libcrossguid.so guid.cpp
  ${CXX} -c guid.cpp -o guid.o -Wall -std=c++11 -DGUID_LIBUUID
  ${AR} rvs libcrossguid.a guid.o
}

do_install() {
   cd ${S}
   install -d ${D}/usr/lib
   install -d ${D}/usr/include
   #install -m 0644 ${S}/libcrossguid.so ${D}/usr/lib
   install -m 0644 ${S}/libcrossguid.a ${D}/usr/lib
   install -m 0666 ${S}/guid.h ${D}/usr/include
}
