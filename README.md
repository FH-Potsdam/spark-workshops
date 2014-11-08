Sparkcore workshop  
==================

This is a code repository for the spark core workshop that took place at [IXDS](http://www.ixds.com/) on 2014.11.07 in winter semster 2014/2015 FH-Potsdam University of Applied Sciences Potsdam (Germany)  

###Contents   

*web examples*  

####spark-ajax  

Use ajax to make a call to the spark API.   

####spark-client-side  

This is an example that uses the client side library (also using a bit of ajax). To get this working create a file called "private" with your credentials next to the "main.js". Like this:  

    {
      "username":"you@example.me",
      "password":"superdupersecret"
    }

Then execute the "http-server" and go to [http://0.0.0.0:8080/](http://0.0.0.0:8080/)  

####spark-helper by [@jflasher](https://github.com/jflasher) 

See [this repo](https://github.com/jflasher/spark-helper) for further infos. An elaborated example also using ajax.  

####web-interface by [@suda](https://github.com/suda)  

See this repo for further infos. An more simple but still great example to use the Spark API.  

see it here [suda.github.io/spark-web-interface/](http://suda.github.io/spark-web-interface/) or here [fh-potsdam.github.io/spark-web-interface/](http://fh-potsdam.github.io/spark-web-interface/).  

*firmware examples*

####src/sparkworkshop_publish  

A simple application that has a function a variable and a publish event.  

####src/sparkworkshop_subscribe  

A simple application that has a variable and a subscribe event.  

### prerequisites  

- Get a spark [account](https://www.spark.io/signup)  

####Automated install:  

This will install all dependencies, clone the repo, init all submodules and install all npm modules and bower components. You always should read scripts like this before using them see the source here: https://raw.githubusercontent.com/FH-Potsdam/2014-2015-WiSe-spark-core-workshop/master/install.sh  

Run in terminal:  

    cd ~/Desktop
    curl -L https://raw.githubusercontent.com/FH-Potsdam/2014-2015-WiSe-spark-core-workshop/master/install.sh | sh

####Manual install  

On Mac OSX the easiest whay is using [homebrew](http://brew.sh/).  

    ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"  

Then run:  

    brew doctor

Then:

    brew install node  

- On Windows [download](http://nodejs.org/download/) the binary.  

- Now install the spark-cli (command line interface)  

Run the following commands in your terminal:  

    npm install -g spark-cli  

For some of the examples ([spark-client-side](https://github.com/FH-Potsdam/2014-2015-WiSe-spark-core-workshop/tree/master/spark-client-side) & [spark-ajax](https://github.com/FH-Potsdam/2014-2015-WiSe-spark-core-workshop/tree/master/spark-ajax)) you also will need to have [bower](http://bower.io/) and [Grunt.js](http://gruntjs.com/) installed and you need to use the http-server.  

    npm install -g bower
    npm install -g grunt-cli
    npm install -g http-server

Now login into the spark cloud.

    spark cloud login  

###claim Core & first Blink  

1. We have 8 cores in the lab. So we asume that on the sparkcore is something  (maybe some code leftovers from another students or he is out of the box) but we don't know what the state is. If you run into the message that the core is claimed by someone else please give me a heads up. The person who had the core before needs to unclaim it.  
2. Unbox the core and plug it into your computer with a micro usb cabel. One o the cores needs to have its antenna connected. (it is the white one.)  
3. Put your core into listenning mode by pressing the mode button for 3 seconds. If this does not work try the [factory reset](http://docs.spark.io/connect/#appendix-factory-reset)
4. Setup your core with wifi credentials and so on. Run `spark setup` in the terminal and follow the instructions. Have your wifi credentials with you. If you run into problems try using the [USB connection version](http://docs.spark.io/connect/#connecting-your-core-connect-over-usb)  
5. If the core is out of the box there is still ["tinker"](http://docs.spark.io/tinker/) installed. This allows you to talk to pins from your phone or from the commandline. Enter into your Terminal `spark function call YOUR_CORES_NAME digitalWrite "D7/HIGH"` to turn on the build in LED. 
6. Go to [www.spark.io/build](https://www.spark.io/build) you should be able to see your core under "Cores" on the left hand side at the bottom.  
7. Congrats start programming your core.

### Deeper usage  

This repo has two firmware examples:  

1. sparkworkshop_publish  
2. sparkworkshop_subscribe  

You could set up two sparkcores with each one having one of the examples.  

There are:  

- 2 Variables (one from each core)  
- 1 Function (from the publish core)  
- 1 Event (also from the publish core)  

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
    spark subscribe fhpid sergantfuzzyboots  



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

Compile your local source (in the cloud):  

    spark compile src/sparkworkshop_publish

Now flash your firmware (via usb):  

    spark flash --usb firmware_1415035556019.bin seargantfuzzyboots

You can also compile in the cloud and flash remotly like this. Then you dont need to send him into Ddfu mode:  

    spark flash sergantfuzzyboots src/sparkworkshop_publish

See the keynotes for more infos
------------


###To Dos:  

- Sparkjs server side example  
- setup own spark cloud  

### Thanks to:  

- [@edgarsilva](https://github.com/edgarsilva)  
- [@jflasher](https://github.com/jflasher)  
- [@suda](https://github.com/suda)  

##License  

Copyright (c) 2014 Fabian "fabiantheblind" Morón Zirfas & FH-Potsdam  
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software  without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to  permit persons to whom the Software is furnished to do so, subject to the following conditions:  
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  

see also http://www.opensource.org/licenses/mit-license.php
