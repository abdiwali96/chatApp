#! /bin/bash
read -p "Do you want to provide an admin user and password? [(Y)es or (N)o] " userInput
case $userInput in
	[Yy]* )
		echo -n "Enter the admin user? [Enter ntu-admin if your machine is using the default admin user] "
		read USER
		echo -n "Enter the admin password.  "
		read -s PASS
		;;
	[Nn]* )
		echo "Using the default password!"
		PASS=!A1b2C3d4E5#
		USER=ntu-admin
		;;
	* ) 
		echo "Please answer yes or no."
		;;
esac

su - ${USER} << !
${PASS}

echo ${PASS} | sudo -S dpkg --configure -a
echo ${PASS} | sudo -S apt update
echo ${PASS} | sudo -S apt upgrade -y
echo ${PASS} | sudo -S apt dist-upgrade -y
echo ${PASS} | sudo -S apt autoremove -y
echo ${PASS} | sudo -S apt autoclean -y
echo ${PASS} | sudo -S apt install libtbb-dev build-essential gcc make cmake cmake-gui cmake-curses-gui libssl-dev -y
echo ${PASS} | sudo -S apt install doxygen graphviz libcppunit-dev catch libclang-common-8-dev qtbase5-private-dev -y
echo ${PASS} | sudo -S rm -rf ~/repositories
mkdir -p ~/repositories
cd repositories
git clone https://code.qt.io/qt/qtmqtt.git
cd qtmqtt
git checkout 5.12.8
mkdir build
cd build
qmake qmake -r ..
make
echo ${PASS} | sudo -S make install
echo ${PASS} | sudo -S ldconfig
echo ${PASS} | sudo -S updatedb
echo "Finished to update the machine!"
