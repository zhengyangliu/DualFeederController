

if ($args[0] -eq "flash") {
    Write-Host "OpenOCD Flash"
    openocd -f openocd.cfg -c "program rtthread.bin 0x08000000 reset exit"
}