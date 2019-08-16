CXXFLAGS=-I/usr/local/Cellar/avr-gcc/9.1.0/avr/include
COMPILER=avr-gcc
OBJCOPY=avr-objcopy
MCU=-mmcu=atmega328p
TARGET=led.elf
HEX_TARGET=led.hex

build: led.elf
	${OBJCOPY} -O ihex ${TARGET} ${HEX_TARGET}
	rm lights.o main.o led.elf

led.elf: main.o lights.o
	${COMPILER} -g ${MCU} -o ${TARGET} main.o lights.o

main.o: lights.o
	${COMPILER} ${CXXFLAGS} -g -Os ${MCU} -c main.c -o main.o

lights.o:
	${COMPILER} ${CXXFLAGS} -g -Os ${MCU} -c lights.c -o lights.o

.PHONY: clean

clean:
	rm led.hex main.o lights.o led.elf

.PHONY: upload

upload:
	avrdude -C ${avrdudeConf} -v -patmega328p -carduino -P/dev/${usbPort} -b115200 -D -Uflash:w:led.hex:i