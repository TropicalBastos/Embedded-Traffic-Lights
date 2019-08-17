CFLAGS=-I/usr/local/Cellar/avr-gcc/9.1.0/avr/include
COMPILER=avr-gcc
OBJCOPY=avr-objcopy
MCU=-mmcu=atmega328p
TARGET=led.elf
HEX_TARGET=led.hex

build: led.elf
	${OBJCOPY} -O ihex ${TARGET} ${HEX_TARGET}

led.elf: main.o controller.o lights.o
	${COMPILER} -g ${MCU} -o ${TARGET} main.o controller.o lights.o

main.o: controller.o
	${COMPILER} ${CFLAGS} -g -Os ${MCU} -c main.c -o main.o

controller.o: lights.o
	${COMPILER} ${CFLAGS} -g -Os ${MCU} -c controller.c -o controller.o

lights.o:
	${COMPILER} ${CFLAGS} -g -Os ${MCU} -c lights.c -o lights.o

.PHONY: clean

clean:
	rm main.o lights.o controller.o led.elf

.PHONY: upload

upload:
	avrdude -C ${avrdudeConf} -v -patmega328p -carduino -P/dev/${usbPort} -b115200 -D -Uflash:w:led.hex:i