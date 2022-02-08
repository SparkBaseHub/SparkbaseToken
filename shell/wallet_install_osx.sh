#!/bin/bash

function prepare_system() {
echo -e "Prepare update system"
brew install autoconf automake berkeley-db4 libtool boost miniupnpc libnatpmp pkg-config python3 qt5 zmq libevent qrencode gmp libsodium rust

# if you want to build the disk image with make deploy (.dmg / optional), you need RSVG
brew install librsvg
# and macdeployqtplus dependencies
pip3 install ds_store mac_alias

clear 
}

function fetch_wallet() {
echo -e "Fetch wallet"
cd $HOME
git -C SparkbaseToken pull || git clone https://github.com/SparkBaseHub/SparkbaseToken.git
}

function compile_wallet() {
echo -e "Compile wallet"
cd $HOME/SparkbaseToken

# use Berkeley DB 4.8
echo -e "Prepare Berkeley DB 4.8"
./contrib/install_db4.sh

chmod 755 autogen.sh
chmod 755 share/genbuild.sh
./autogen.sh
./configure --with-unsupported-ssl --disable-tests --disable-bench
make
make install
chmod 755 fetch-params.sh
./util/fetch-params.sh
}


prepare_system
fetch_wallet
compile_wallet
