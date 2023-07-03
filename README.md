# Pico CLI

A minimal shell for Raspberry Pi Pico over USB serial. 

This is used to remotely power my desktop on/off via a Raspberry Pi.

```Pi <-[USB]----[MicroUSB]-> Pico <-[GPIO PINS]----[PINS]-> ATX adapter A <---[Short Ethernet Cable]---> ATX adapter B (Installed in computer case) <-[PINS]----[PINS]-> Desktop motherboard```

In this configuration, the Pico board essentially serves as a GPIO expander.

# Reference

https://github.com/raspberrypi/pico-examples/tree/master/hello_world/usb

https://wiki.blicube.com/blikvm/en/atx-guide/#2-a-board

https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf#page=19