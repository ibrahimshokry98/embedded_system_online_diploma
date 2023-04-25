#@copyright: Ibrahim Shokry
Project_name=unit3_lab4_cortexM4
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INC=-I ./inc
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
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf 
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.elf *.bin *.axf *.o
	
clean:
	rm *.elf *.bin *.axf