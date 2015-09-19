#!/bin/sh

if [ $# -lt 1 ] ; then
  echo "Usage: mksrcdist version"
  echo
  echo "Example: mksrcdist.sh 1.1.4"
  exit
fi

SRC_VERSION=$1
COMPRESSED_VERSION=`echo $SRC_VERSION | tr -d .`

rm -rf dist_wrk  
mkdir dist_wrk
cd dist_wrk

export CVSROOT=:pserver:anonymous@cvs.openev.sf.net:/cvsroot/openev

echo "Please type [ENTER] if prompted for a password."
cvs login 

cvs checkout openev

if [ \! -d openev ] ; then
  echo "cvs checkout reported an error ... abandoning mksrcdist"
  cd ..
  rm -rf dist_wrk
  exit
fi

find openev -name CVS -exec rm -rf {} \;

mv openev openev-${SRC_VERSION}

rm -f ../openev-${SRC_VERSION}.tar.gz ../openev${COMPRESSED_VERSION}.zip

tar cf ../openev-${SRC_VERSION}.tar openev-${SRC_VERSION}
gzip -9 ../openev-${SRC_VERSION}.tar
zip -r ../openev${COMPRESSED_VERSION}.zip openev-${SRC_VERSION}

cd ..
rm -rf dist_wrk
