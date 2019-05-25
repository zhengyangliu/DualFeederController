
ifneq ($(V),1)
Q		:= @
NULL	:= 2>/dev/null
endif

TARGET    := rtthread

flash:
	@printf "  OPEN_OCD FLASH $<\n"
	$(Q)openocd -f openocd.cfg -c "program $(TARGET).bin 0x08000000 reset exit" 

debug:
	@printf "  GDB DEBUG $<\n"
	$(Q)arm-none-eabi-gdb -iex 'target extended | openocd -f openocd.cfg -c "gdb_port pipe"' -iex 'monitor reset halt' -ex 'load' -ex 'break main' -ex 'c' $(TARGET).elf