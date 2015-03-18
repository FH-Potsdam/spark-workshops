// simple sketch on how to publish an event
// and publish a function
//
int pin = D7; // pin to toggle
boolean blinkit = false; // to see if it is on or off

int toggleBlinking(String command); // declare the function C++ style

void setup() {
  Spark.function("blink", toggleBlinking); // publish the function.
  Spark.publish("fhpid", "1", 60, PRIVATE);// publish the event to a private cloud
  pinMode(pin,OUTPUT);// set the pin to output
}

/**
 * this is a function you can call from the cloud
 * in here we will also publish an event every time the pin got toggled
 *
 * @param  {String} String command  This can be some value you send to the function
 * @return {int} returns 1 if everything whent fine -1 if the command did not match
 */
int toggleBlinking(String command){

  if(command == "toggle"){
    blinkit = !blinkit;

    if(blinkit == true){
        digitalWrite(pin,HIGH);
        // this is how to publish the event
        // if blinkit is true publish 1
        // else publish 0
        Spark.publish("fhpid", (blinkit == true) ? "1" : "0");

    }else{
        digitalWrite(pin,LOW);
                // this is how to publish the event
        // if blinkit is true publish 1
        // else publish 0
        Spark.publish("fhpid", (blinkit == true) ? "1" : "0");
    }
    return 1;
  }else{

    return -1;
  }
}

void loop() {
/*nothing to see here*/
}
