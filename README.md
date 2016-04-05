# Nabto Heat Control Template

A template to demonstrate Nabto.

# Ionic client

Building and running:
```
# Install nodejs and npm using brew on a mac with xcode installed
brew install node

# Install npm cli modules; cordova and ionic globally
npm install cordova ionic -g

# Start a new ionic app using the nabto-heat-control starter
ionic start myApp https://github.com/nabto/nabto-heat-control-template

# Install the nabto cordova plugin
ionic plugin add cordova-plugin-nabto

# Add platforms
ionic platform add ios android

# Manually replace ios linker flags according to plugin readme using xcode
# "-ObjC" to "-force_load $(BUILT_PRODUCTS_DIR)/libCordova.a -lstdc++".
# Optionally raise deployment target to 8.0 or above.

# Set your nabto device id in 'www/js/app.js'

# Build the project for ios or android
ionic build ios

# Open xcode and run or run the simulator directly from the command line
ionic emulate ios
```

# uNabto Device Application

This part is targeted to run on a Raspberry Pi (any version).

Building and running:
```
# Access the Raspberry Pi
ssh pi@raspberry

# Fetch the template repo
git clone https://github.com/nabto/nabto-heat-control-template

# Update the unabto submodule
git submodule update --init

# Install cmake if not already present
sudo apt-get install cmake

# Create a build directory
mkdir build
cd build

# Build the unabto demo
cmake ../nabto-heat-control/device
make

# Run the demo with a device ID and key (https://portal.nabto.com/)
./nabto-heat-control -d <ID> -s -k <KEY>
```
