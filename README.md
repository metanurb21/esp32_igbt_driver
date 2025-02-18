# ESP32 IXDI & IXDN IGBT gate driver used for DIY induction heater.

![Some copper scrap melting in a graphite crucible.](https://github.com/metanurb21/esp32_igbt_driver/blob/main/images/melting-copper.jpg)

I wanted to build a high power induction heater capable of melting metal, copper, iron, aluminium etc.
Getting it just right turned out be a bit of a project as you can imagine. I picked up a little here and a little there from scouring the internet. Given my inexperience with circuitry and schematics, I needed it to be a simple as possible. I'm always playing around with microcontrollers and I am pretty comfortable coding, so I figured if I could do most the legwork with code, it should keep the circuit design to a minimum. Here is what I came up with.

## The Board Design

I made the schematic in [flux.ai](https://www.flux.ai/metanurb21/esp32-pwm-ixd630-igbt-driver-v2?editor=schematic). Here is a link to [The board Gerber files.](https://github.com/metanurb21/esp32_igbt_driver/blob/main/files/metanurb21-esp32-pwm-ixd630-igbt-driver-v2-Gerbers-Versionedf32863.zip)

[The components list](https://github.com/metanurb21/esp32_igbt_driver/blob/main/files/pick_and_place.csv)

[The ESP32 driver code for Arduino IDE](https://github.com/metanurb21/esp32_igbt_driver/blob/main/code/esp32__igbt_gate_driver.ino)

![3D representation of the driver ciruit board](https://github.com/metanurb21/esp32_igbt_driver/blob/main/images/igbt-driver.png)

This setup is probably not the perfect PCB or design, like I said, I am just learning. This setup does not operate a [phase loop lock](https://en.wikipedia.org/wiki/Phase-locked_loop) to autotune, it's all manual. I have an LED that glows when I am in resonance and I can hear and see the current being drawn. My buddy calls it "Tune for maximum smoke" :wink:. The PLL approach is my next build attempt. It does however work pretty well from 10khz to 100khz. I have two coils of different sizes and they resonate at around 82khz and 52khz. The current code is set to range from 10khz to 100khz. To change that, you just change some of the variables. I decided to go with a rotary encoder instead of an analog read from a potentiometer on the ESP32. It's a lot more accurate, doesn't bounce around at all and does not suffer from interference. I have ran this thing for hours and hit it pretty hard with decent voltage and amps. So far so good. Pay attention to what's going on and keep all the components cool. This is done with a combination of fans and water blocks with a pump circulating cool water around all the hot spots.

Liquid cooled things:

- The IGBTS.
- The IXDN gate drivers.
- The coil and the tank capacitor.

Air coolled with heat sinks:

- The circuit board and anything else you want.

## The components you will need to build and aquire.

There is no single or correct way to build an induction heater. I have built 3 or 4 differnt boards with different approaches. Each version required slightly different setup and components. The things you have to get right are the IGBT gate signals, adequate protection from voltage and current spikes and the proper blance of values to make the heating coil resonate so that it produces the maximum and most efficient electro magnetic coupling (power) to the intended work piece.

## To Build

Apart from the driver board, you will need to build:
A high power IGBT full-bridge inverter. There many schematics available from a google search.
A copper pipe heating coil. 1/4" or 3/8" pipe
A coupling transformer [I used 4 of these](https://www.easternvoltageresearch.com/ferrite-core-5000-1/) with Litz wire (multi stranded magnet wire rope you can make).
A GTD (gate drive transformer). You can make or buy from [eastern voltage research](https://www.easternvoltageresearch.com/gate-transformer-kit-5000-1/).
A liquid cooling network for the IGBT's and the the tank capacitor. Common sense and some basic building and fabricating skills required.
Various different value power sources depending on the approach youy take., 5V, 12V, 15V.

## To Aquire

Other items you will need are: [A 30A variac is recomended](https://www.ebay.com/itm/375079366063). [Various capacitors](https://www.ebay.com/itm/234559065702) and [snubber caps](https://www.ebay.com/itm/396177418199?_skw=snubber+capacitopr&itmmeta=01JMDDCM8SQPJGYN1PYTKN86BS&hash=item5c3e03a7d7:g:VE4AAOSwAYdno4WP&itmprp=enc%3AAQAKAAAA0FkggFvd1GGDu0w3yXCmi1c9mWgMXZX5fwHpwCae7OcaRXv1trcV3pJHvxD7N%2BYRzYReG5U4lVD76NHHILRzqmooxb7L2cbUsKP2JHcCTopAn1pdaqD1sa0glHSgaajgOATGAaY3qhzo%2BHvpVgDuLP%2FbjWafyUHbSjMkNS7ixHWHxHD6KvJA9vZjk2rkU%2FkQ3LNl9oBzikCl3rA7CmxaXTL2N42wPFiJ0QYJF6qiNYs4mD%2FDD%2FP0W9Pats5fIZlX6m4r4gOI%2FzUm9CFR3ZX5Mfk%3D%7Ctkp%3ABk9SR6bGsq2jZQ). Some copper bus bars, A pond pump. Some high-heat rubber pipe, A large full bridge recifier, Heat sinks, fans, water blocks, large guage wire, magnet wire, some high heat fiberglass pipe insulation, a kiln crucible and I would sugest a prinkling of some ceramic fiber insulation here and there to protect things. It gets kinda scary your first time!
Most of these things you can find on eBay, Amazon and your local hardware store.
The larger capacitors, snubber caps and IGBT's you will need to source from eBay or Alibaba etc.
For great quality stuff geared towards high voltage enthusiasts, I use https://www.easternvoltageresearch.com/

For the large current water cooled capacitors, I recommend [Dawncap.](https://www.dawncapacitors.com/home). These things can get really pricey if you go top name brand. I would suggest for getting started, you buy from Dawncap. I have bought a few different ones over the past year, and I can attest that they hold up and get the job done. The caps I have are:

[DAWNCAP DCC-5H 2.6UF 700V 950A 400KVAR Water cooled large current Big Current Resonant Capacitor](https://www.aliexpress.us/item/3256805434541389.html?spm=a2g0o.order_list.order_list_main.21.21ef1802Jx87JR&gatewayAdapt=glo2usa)
[DAWNCAP DCC 3.5UF 1200V AC 120A Water &Wind cooled large current Big Current Resonant Capacitor](https://www.aliexpress.us/item/3256805388886798.html?spm=a2g0o.order_list.order_list_main.26.21ef1802Jx87JR&gatewayAdapt=glo2usa)
[DAWNCAP DCC 2UF 600V 650A Water cooled large current Big Current Resonant Capacitor](https://www.aliexpress.us/item/3256805387045331.html?spm=a2g0o.order_list.order_list_main.31.21ef1802Jx87JR&gatewayAdapt=glo2usa)

:open_mouth: 950A!!!, getting real serious ya. All have served me well.

For IGBT bricks, it's nice to have quality bricks like Infineon etc. You can get them used on eBay or you can get new cheaper ones on Alibaba. Again, you get what you pay for but while experimenting and blowing crap up, It's fine to go cheaper and then you can replace with the quality products when you are ready. [Some cheaper ones here](https://www.aliexpress.us/item/3256805870685571.html?spm=a2g0o.order_list.order_list_main.277.21ef1802ginfNj&gatewayAdapt=glo2usa). One note, it's not always better to go bigger, like 400A or 600A. The bigger they get, the slower the gate times. We want to keep things as fast as possible since we are dealing with very high frequency switching.

Once you've blown everything up once or twice and you are finally up and running, you should be looking something like this. Or better!. :)

![Image of fully operating unduction heater on work bench](https://github.com/metanurb21/esp32_igbt_driver/blob/main/images/induction-heating-snapshot.jpg)
