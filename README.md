# Nabto Heat Control Template

A template to demonstrate Nabto.

# Ionic client

Note: The `cordova-plugin-nabto` is not officially released yet.

Building and running:
```
# Install nodejs and npm using brew on a mac with xcode installed
brew install node

# Install npm cli modules; cordova and ionic globally
npm install cordova ionic -g

# Start a new ionic app using the nabto-heat-control starter (which includes the cordova-plugin-nabto)
ionic start myApp nabto-heat-control

# Add ios as a platform to ionic
ionic platform add ios

# > Manually set ios linker flags according to README with XCode

# Build the ios project
ionic build ios

# Open XCode and run or run the simulator directly from the commandline
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
