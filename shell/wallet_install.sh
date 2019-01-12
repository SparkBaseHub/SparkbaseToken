

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
exit

#sudo su -
cat <<EOF >> /etc/sysctl.conf
vm.swappiness=10
vm.vfs_cache_pressure=50
EOF
exit

fi


echo -e "Prepare firewall"
sudo apt-get -y install fail2ban
sudo systemctl enable fail2ban
sudo systemctl start fail2ban

apt-get install ufw
sudo ufw allow OpenSSH

echo -e "Prepare update system"
sudo apt-get -y update

sudo apt-get install -y build-essential libtool autotools-dev autoconf pkg-config libssl-dev libgmp3-dev libevent-dev automake git

# new ssl support for SparkBase
sudo apt-get install -y libsecp256k1-dev

# libboost library
sudo apt-get install -y libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev

# for wallet
sudo apt-get install -y software-properties-common
sudo add-apt-repository -y ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install -y libdb4.8-dev libdb4.8++-dev

#Optional
sudo apt-get install -y libminiupnpc-dev

#ZMQ dependencies (provides ZMQ API 4.x):
sudo apt-get install -y libzmq3-dev

# Dependencies for the GUI: Ubuntu
#sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler

# libqrencode (optional) can be installed with:
sudo apt-get install -y libqrencode-dev

clear
}

function fetch_wallet() {
cd /home
git -C SparkBase pull || git clone https://github.com/SparkBaseHub/SparkBase.git
}

function compile_wallet() {
cd /home/SparkBase
chmod 755 autogen.sh
chmod 755 share/genbuild.sh
./autogen.sh
./configure --with-unsupported-ssl
./configure --without-gui --with-unsupported-ssl
make
make install
}


prepare_system
fetch_wallet
compile_wallet











