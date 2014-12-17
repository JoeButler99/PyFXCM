#!/bin/bash



# Nice display
function print_in_colour() {
	echo -e "\n\033[1;36m##################################################"
	echo "   * $1"
	echo -e "################################################## \033[0m\n";
}

if [ ! -f ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz ]; then
	print_in_colour "Collect API Tarball"
	wget http://fxcodebase.com/bin/forexconnect/1.3.1/ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz
fi 
tar zxvf ForexConnectAPI-1.3.1-Linux-x86_64.tar.gz

print_in_colour "Build and copy headers and libraries"
cd ForexConnectAPI-1.3.1-Linux-x86_64/
cp -a include/* ../include/
cp -a samples/cpp/sample_tools/include/* ../include/
cp -L lib/*.so ../lib/
cd samples/cpp/sample_tools/
./fxbuild.sh
cp lib/libsample_tools.so ../../../../lib/

print_in_colour "Install libyaml dev library and libboost-python-dev"
sudo apt-get install libyaml-dev libboost-python-dev

print_in_colour "Removing downloaded libraries"
rm -rf ForexConnectAPI-1.3.1*


exit 0
