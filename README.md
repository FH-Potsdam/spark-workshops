Sparkcore workshop  
==================

This is a code repository for the spark core workshop in winter semster 2014/2015 FH-Potsdam University of Applied Sciences Potsdam (Germany)  

ToDos:  
- what's Spark Core?  
- what is nodejs?  

- Proof wire less Connection
- get value to webpage
- controll from Web Server 
- nodejs website Control Core

### Topics:  

#### prerequisites  
- Get a spark [account](https://www.spark.io/signup)  
- Install [node.js](http://nodejs.org/)  

On Mac OSX the esiest whay is using [homebrew](http://brew.sh/).  

    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"  

Then run:  

    brew doctor

Then:

    brew install node  

- On Windows [download](http://nodejs.org/download/) the binary.  

- Now install the spark-cli (command line interface)  

Run the following commands in your terminal:  

    npm install -g spark-cli  
    spark cloud login  


####claim Core & first Blink  

1. We have 8 cores in the lab. So we asume that on the sparkcore is something  (maybe some code leftovers from another sutdent or he is out of the box) but we don't know what the state is.  
2. Unbox the core and plug it into your computer with a micro usb cabel.  
3. Put your core into listenning mode by pressing the mode button for 3 seconds.
4. Setup your core with wifi credentials and so on. Run `spark setup` in the terminal and follow the instructions. Have your wifi credentials with you. 
5. Go to [www.spark.io/build](https://www.spark.io/build) you should be able to see your core under "Cores" on the left hand side at the bottom.  
6. Congrats start programming your core. 

For example like this. The counter is a published variable. That is accesable from to the cloud.  



    int toggleBlinking(String command);
    int pin = D7;
    int count = 0;
    boolean blinkit = false;
    
    
    void setup() {
      Spark.variable("count",&count, INT);
      Spark.function("blink", toggleBlinking);
    pinMode(pin,OUTPUT);
    }
    
    int toggleBlinking(String command){
      if(command == "toggle"){
        blinkit = !blinkit;
        return 1;
      }else{
        return -1;
      }
    }
    
    void loop() {
    
      if(blinkit == true){
        Spark.publish("blinking", "1", 60, PRIVATE);
    
        digitalWrite(pin,HIGH);
        delay(1000);
    
        digitalWrite(pin,LOW);
        delay(1000);
      }else{
      }
      count++;
    }



Get Your API token and your core ID from [www.spark.io/build](https://www.spark.io/build) and go to [interface.fh-potsdam.de/spark-core/helper](http://interface.fh-potsdam.de/spark-core/helper/). You will get the login credentials in the workshop. If your not part of the workshop. Get the web interface and install it on your own server. I recommend [uberspace.de](https://uberspace.de/).  

Login and enter your ID and API token.

- Enter as "Function Name" "blink" and as "data" "toggle" and  hit post.
- Get the value of the `count` variable.  

You can also access these infos from the command line 

In the terminal run:  

    spark monitor count

Now you can see the progress of count.  

This will list all functions

    spark function list
    
Result is something like this:  

    Listfunctions called
    polling server to see what cores are online, and what functions are available
    Retrieving cores... (this might take a few seconds)
    sergantfuzzyboots (123456789012345678) has 1 functions
      int blink(String args) 

To call the blink function run (with your core id of course):  

    spark function call 123456789012345678 blink "toggle"

To get the count value run:  

    spark monitor 123456789012345678 count

To get the all your events run:  

    spark subscribe mine

Te get a specific event run:  

    # you could also use the core id
    spark subscribe blinking sergantfuzzyboots  



###DFU MODE (DEVICE FIRMWARE UPGRADE)
[source](http://docs.spark.io/connect/#appendix-dfu-mode-device-firmware-upgrade)
If you are wish to program a Core with a custom firmware via USB, you'll need to use this mode. This mode triggers the on-board bootloader that accepts firmware binary files via the dfu-utility.
Procedure:  

make sure you have the dfu-utils installed  

    brew install dfu-utils

1. Hold down BOTH buttons
2. Release only the RST button, while holding down the MODE button.
3. Wait for the LED to start flashing yellow
4. Release the MODE button

Compile your local source:  

    spark compile sparkworkshop

Now flash your firmware:  

    spark flash --usb firmware_1415035556019.bin seargantfuzzyboots

------------



### Links:  

This is a simple webinterface for interaction with sparkcores [github.com/FH-Potsdam/spark-helper](https://github.com/FH-Potsdam/spark-helper) see it in action here [id.fhp.de/spark-core/helper](http://interface.fh-potsdam.de/spark-core/helper/)  

##License  

Copyright (c) 2014 Fabian "fabiantheblind" Morón Zirfas & FH-Potsdam  
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software  without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  permit persons to whom the Software is furnished to do so, subject to the following conditions:  
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  

see also http://www.opensource.org/licenses/mit-license.php


