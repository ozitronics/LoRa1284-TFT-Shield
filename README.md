# LoRa1284 TFT Shield

A display shield for the LoRa1284 module. It includes an 8-pin connector for a colour TFT/IPS display module and 3 pushbuttons.

Colour TFT display modules are commonly available. You can order one (fitted) with the shield or purchase your own elsewhere. ** The only requirement is that it has an 8-pin header ie. includes chip select (CS) pin**. 

The display interfaces to the LoRa1284 via the SPI port and pins D21, D22 and D23. Analog pin A7 is used to read the pushbuttons. The display backlight can be controlled using PWM pin D3 (via a solder jumper).

A row of header pins either side of the LoRa1284 socket allows easy connection to all LoRa1284 I/O pins.

All of this on a compact board measuring just 65 x 42 mm (2.55" x 1.65").

### **Why did I make it?**

I needed a way to display data in my projects. I could have used an LCD but a TFT display offers so many more options. Not only is it a colour display but you can also use different size fonts, draw graphs and even display images. The pushbuttons are useful for creating a menu system and inputting data.

### **TFT library**

There are a number of Arduino libraries available to control the TFT displays. A search for "TFT" in the Arduino library manager will return quite a few. Just be aware of the driver IC used in your particular display.

### **Analog keypad library**

There are also a number of libraries available to read the pushbuttons connected to an analog pin. I have developed a simple, easy to use library called "SimpleButtons" (you can read more about it on my Github page).
