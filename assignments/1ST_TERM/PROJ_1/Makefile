#@copyright: Ibrahim Shokry
Project_name=High_Pressure_Detection
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INC=-I .
LIBS=
SRC = $(wildcard *.c)
AS = $(wildcard *.s)
OBJ= $(SRC:.c=.o)
ASOBJ= $(AS:.s=.o)

all: $(Project_name).bin
	@echo "=============== Build is done ==============="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INC) $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf 
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.elf *.bin *.o *.map
	
clean:
	rm *.elf *.bin *.map