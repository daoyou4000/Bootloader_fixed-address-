# Bootloader with jump fixed-address
One example of bootloader with fixed jump address. 
In this example, there are one bootloader and two APPs. 
The bootlaoder could jump into the different fixed address based on the GPIO input. 
The lesson learn here, two main topics we need to pay attention: 

## 1, Deinit is necessary before jump into App from bootloader. 
When the bootloader implement GPIO, especially Timer, the bootloader is not able to jump to application address.
During the debug, the interrupt is still there and **application does not work if registers are not reset**.
The target of this deinit process is totally the reverse process of the intialization process, and registers is good to be reset before the initialization. 
![image](https://github.com/daoyou4000/Bootloader_fixed-address-/blob/main/images/Intialization.PNG)

**Then the deinitilization process should follow the reverse sequence**

![image](https://github.com/daoyou4000/Bootloader_fixed-address-/blob/main/images/Deinit.PNG)


## 2, Secondly, the Vector Table need to be assigned in application.
The application does not work at all if the VTOR is not assigned with the correct address. 
It gives the **offset address** of Vector Table.

![image](https://github.com/daoyou4000/Bootloader_fixed-address-/blob/main/images/Vector_Table.PNG)
