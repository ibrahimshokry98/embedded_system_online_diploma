/* ARM cortex M3 linker script
 * Eng: Ibrahim Shokry
 * 10/5/2023
 */

MEMORY
{
	flash(RX) : ORIGIN =0x08000000 ,LENGTH = 128K
	ram(RWX)  : ORIGIN =0x20000000 ,LENGTH = 20K
}


SECTIONS
{
	.text :
	{
		*(.vectors)
		*(.text)
		*(.rodata)
		_E_TEXT = . ;
	}>flash
	.data :
	{
		_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}>ram AT>flash
	.bss :
	{
		_S_BSS = .;
		*(.bss)
		. = ALIGN(4);
		_E_BSS = .;
		. = . + 0x1000 ;
		_Stack_top = . ;
	}>ram
}





