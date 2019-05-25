REM @echo off

ECHO %1

if "%1" == "flash" goto flash
if "%1" == "debug" goto debug

:flash
echo "OpenOCD flash bin"
call openocd -f openocd.cfg -c "program rtthread.bin 0x08000000 reset exit"
goto end

:debug
echo "OpenOCD debug elf"
call arm-none-eabi-gdb -iex 'target extended | openocd -f openocd.cfg -c "gdb_port pipe"' -iex 'monitor reset halt' -ex 'load' -ex 'break main' -ex 'c' rtthread.elf
goto end

end: