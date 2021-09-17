# Bootloader with jump fixed-address
One example of bootloader with fixed jump address. 
In this example, there are one bootloader and two APPs. 
The bootlaoder could jump into the different fixed address based on the GPIO input. 
The lesson learn here, two main topics we need to pay attention: 

## Deinit is necessary before jump into App from bootloader. 
When the bootloader implement GPIO, especially Timer, the bootloader is not able to jump to application address.
During the debug, the interrupt is still there and ""application does not work if registers are not reset"". 
