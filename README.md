# lumini_8x8_and_metro_express

## Hardware

1.  [Adafruit Metro M0 Express](https://learn.adafruit.com/adafruit-metro-rp2040/pinouts)
2.  [SparkFun LuMini LED Matrix - 8x8](https://learn.sparkfun.com/tutorials/lumini-8x8-matrix-hookup-guide?_ga=2.269100921.9462074.1712349924-870672267.1710346008)
3.  [Potentiometer, CUI Devices PTN15-C10NB10](https://www.cuidevices.com/product/motion-and-control/potentiometers/trimmer-potentiometers/ptn15-c10nb10)

## Pinout

| Adafruit Metro M0 Express        | SparkFun LuMini | Wire Colour In Picture |
| :------------------------------- | :-------------- | :--------------------- |
| 5V                               | 5V              | Red                    |
| GND                              | GND             | Black                  |
| Digital 6 / SPI0 SCK             | CI              | Grey                   |
| Digital 7 / SPI0 SDO / SPI0 MOSI | DI              | Blue                   |


<p align="center"><img src="/readme_assets/sparkfun_lumini_and_adafruit_metro.png" width="800"/></p>
<br/>
<p align="center"><img src="/readme_assets/readme_overall.png" width="800"/></p>
<br/>

## Setup

1.  Wire the hardware as described in the Pinout section.
2.  Confirm that the Adafruit Metro's _DC Jack_ switch is in the _OFF_ position.
3.  Connect the Adafruit Metro to your development computer with a micro-USB cable.
4.  Start the Arduino IDE on your development computer.
5.  Install the [FastLED library](https://github.com/FastLED/FastLED/).
    At the time of writing, you do this by:
    - [Download the library](https://github.com/FastLED/FastLED/archive/master.zip) as a _.zip_
    - In the Arduino IDE, select _Sketch ⟶ Include Library ⟶ Add .ZIP Library..._
    - Select the library and then _Open_
6.  Open the Arduino Sketch from this repository, [lumini_metro_example](./lumini_metro_example.ino).
7.  Updload the Sketch to the Adafruit Metro by:
    - Select the Board
    - Select the Port
    - Select the _Upload_ button
