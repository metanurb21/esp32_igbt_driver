# ESP32 IXDI & IXDN IGBT gate driver used for DIY induction heater.

![Some copper scrap melting in a graphite crucible.](https://github.com/metanurb21/esp32_igbt_driver/blob/main/melting-copper.jpg)

I wanted to build a high power induction heater capable of melting metal, copper, iron, aluminium etc.
Getting it just right turned out be a bit of a project as you can imagine. I picked up a little here and a little there from scouring the internet. Given my inexperience with circuitry and schematics, I needed it to be a simple as possible. I'm always playing around with microcontrollers and I am pretty comfortable coding, so I figured if I could do most the legwork with code, it should keep the circuit design to a minimum. Here is what I came up with.

## The Board Design

I made the schematic in flux.ai [The board Gerber files.](https://github.com/metanurb21/esp32_igbt_driver/blob/main/metanurb21-esp32-pwm-ixd630-igbt-driver-v2-Gerbers-Versionedf32863.zip)

[The ESP32 driver code for Arduino IDE](https://github.com/metanurb21/esp32_igbt_driver/blob/main/esp32__igbt_gate_driver.ino)

![The ciruit board](https://github.com/metanurb21/esp32_igbt_driver/blob/main/igbt-driver.png)
