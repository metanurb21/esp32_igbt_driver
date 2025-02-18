# ESP32 IXDI & IXDN IGBT gate driver used for DIY induction heater.

![Some copper scrap melting in a graphite crucible.](https://github.com/metanurb21/esp32_igbt_driver/blob/main/images/melting-copper.jpg)

I wanted to build a high power induction heater capable of melting metal, copper, iron, aluminium etc.
Getting it just right turned out be a bit of a project as you can imagine. I picked up a little here and a little there from scouring the internet. Given my inexperience with circuitry and schematics, I needed it to be a simple as possible. I'm always playing around with microcontrollers and I am pretty comfortable coding, so I figured if I could do most the legwork with code, it should keep the circuit design to a minimum. Here is what I came up with.

## The Board Design

I will put all the good stuff up here for the impatient and/or well informed and leave all the details below.

I made the schematic in flux.ai [The board Gerber files.](https://github.com/metanurb21/esp32_igbt_driver/blob/main/files/metanurb21-esp32-pwm-ixd630-igbt-driver-v2-Gerbers-Versionedf32863.zip)

[The components list](https://github.com/metanurb21/esp32_igbt_driver/blob/main/files/pick_and_place.csv)

[The ESP32 driver code for Arduino IDE](https://github.com/metanurb21/esp32_igbt_driver/blob/main/code/esp32__igbt_gate_driver.ino)

![The ciruit board](https://github.com/metanurb21/esp32_igbt_driver/blob/main/images/igbt-driver.png)

This setup is probably not the perfect PCB or design, like I said, I am just learning. This setup does not operate a phase loop lock to autotune, it's all manual. That approach is my next build attempt. It does however work pretty well from 10khz to 100khz. I have two coils of different sizes and they resonate at around 82khz and 52khz. The current code is set to range from 10khz to 100khz. To change that, you just change some of the variables. I have ran this thing for hours and hit it pretty hard with decent voltage and amps. So far so good. The trick is to keep all the components cool. This is done with a combination of fans and water blocks with a pump circulating cool water around all the hot spots.

Liquid cooled things:

- The IGBTS.
- The IXDN gate drivers.
- The coil and the tank capacitor.

Air coolled with heat sinks:

- The circuit board and anything else you want.

## The components you will need to build?

There is no single or correct way to build an induction heater. I have built 3 or 4 differnt boards with different approaches. Each version required slightly different setup and components. The things you have to get right are the IGBT gate signals, adequate protection from voltage and current spikes and the proper blance of values to make the heating coil resonate so that it produces the maximum and most efficient electro magnetic coupling (power) to the intended work piece.

Apart from the driver board, you will need to build:
A high power IGBT full-bridge inverter.
A copper pipe heating coil.
A coupling transformer with Litz wire.
A GTD (gate drive transformer).
A liquid cooling network for the IGBT's and the the tank capacitor.
Various different value power sources depending on the approach youy take.

Other items you will need are, a variac is recomended 30A. A pond pump. Some high-heat rubber pipe, A large full bridge recifier, Heat sinks, fans, water blocks, large guage wire, magnet wire, some high heat fiberglass pipe insulation, a kiln crucible and I would sugest a prinkling of some ceramic fiber insulation here and there to protect things. It gets kinda scary your first time!

Once you have blown everything up one or twice and you are up and running, you should be looking something like this. Or better!. :)

![Testing it out](https://github.com/metanurb21/esp32_igbt_driver/blob/main/images/induction-heating-snapshot.jpg)
