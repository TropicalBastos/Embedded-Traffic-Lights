# Embedded Traffic Lights

Built for the atmega328p chip, though can be built and uploaded to an Arduino as well since its based on the same chip family.

## Building

1. Ensure you have the avr-gcc compiler to compile the project for the correct hardware

2. Ensure that you also have avr-objcopy and avrdude installed on your system as they will be needed during the make process (avrdude for uploading the binary to the chip)

3. Run `make` to build the .hex binary

4. Run `make clean` to remove the compiled object code that has already been linked into the .hex binary

5. Change the environment variables present in `upload.sh` to match your configuration

6. Run `sh upload.sh` to upload to your chip connected via USB

7. The following circuitry will need to be wired:

- The red LED to pin 18 (or digital pin 12)
- The amber LED to pin 17 (or digital pin 11)
- The green LED to pin 16 (or digital pin 10)
- 3.3V connected to one side of the push button
- The other side of the push button connected to pin 11 (or digital pin 5)

8. Don't forget the jump wire back to ground to complete the circuit and add in appropriate resistors.