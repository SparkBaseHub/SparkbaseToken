#!/bin/bash

function prepare_system() {
if [[ $(swapon -s | wc -l) -gt 1 ]] ; then
	echo -e "Swapfile alreday set"
else

	echo -e "Prepare swapfile"
	sudo fallocate -l 4G /swapfile
	sudo chmod 600 /swapfile
	sudo mkswap /swapfile
	sudo swapon /swapfile

cat <<EOF >> /etc/fstab
/swapfile none swap sw 0 0
EOF
#exit

#sudo su -
cat <<EOF >> /etc/sysctl.conf
vm.swappiness=10
vm.vfs_cache_pressure=50
EOF
#exit

fi


echo -e "Prepare firewall"
sudo apt-get -y install fail2ban
sudo systemctl enable fail2ban
sudo systemctl start fail2ban

apt-get install ufw
sudo ufw allow OpenSSH

echo -e "Prepare update system"
sudo apt-get -y update

#sudo apt-get install -y build-essential libtool autotools-dev autoconf pkg-config libssl-dev libgmp3-dev libevent-dev automake git
sudo apt-get install -y build-essential libtool bsdmainutils autotools-dev autoconf pkg-config automake python3 automake git cargo

# new ssl support for Sparkbase
sudo apt-get install -y libsecp256k1-dev

# libboost library
#sudo apt-get install -y libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev
sudo apt-get install -y libgmp-dev libevent-dev libboost-all-dev libsodium-dev

# for wallet
sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:pivx/pivx
sudo apt-get update
sudo apt-get install -y libdb4.8-dev libdb4.8++-dev

#Optional
sudo apt-get install -y libminiupnpc-dev

#ZMQ dependencies (provides ZMQ API 4.x):
sudo apt-get install -y libzmq3-dev

clear
}

function fetch_wallet() {
cd /home
git -C SparkbaseToken pull || git clone https://github.com/SparkBaseHub/SparkbaseToken.git
}

function compile_wallet() {
cd /home/SparkbaseToken
chmod 755 autogen.sh
chmod 755 share/genbuild.sh
./autogen.sh
./configure --without-gui --with-unsupported-ssl --disable-tests --disable-bench
make
make install
chmod 755 fetch-params.sh
./util/fetch-params.sh
}


prepare_system
fetch_wallet
compile_wallet











