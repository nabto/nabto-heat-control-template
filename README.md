# Nabto Heat Control Template

A template to demonstrate Nabto.

# Ionic client

...

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

# Create a build directory
mkdir build
cd build

# Build the unabto demo
cmake ../nabto-heat-control/device
make

# Run the demo with a device ID and key (https://portal.nabto.com/)
./nabto-heat-control -d <ID> -s -k <KEY>
```
