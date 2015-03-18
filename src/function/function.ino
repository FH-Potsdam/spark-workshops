// simple sketch that shows how to
// publish a function to the cloud

int pin = D7; // the pin to toggle

boolean blinkit = false; // to see if it is on or of

int toggleBlinking(String command); // declare the function C++ style

void setup(){
  pinMode(pin,OUTPUT);// define the pin as output
  Spark.function("blink", toggleBlinking);// publish the function
}

void loop(){
  /*
   nothing to see here
   everything happens in the function toggleBlink
  */
}

/**
 * this is a function you can call from the cloud
 * @param  {String} String command  This can be some value you send to the function
 * @return {int} returns 1 if everything whent fine -1 if the command did not match
 */
int toggleBlinking(String command){

  if(command == "toggle"){
    blinkit = !blinkit;
    if(blinkit == true){
        digitalWrite(pin,HIGH);
    }else{
        digitalWrite(pin,LOW);
    }
    return 1;
  } else {
    return -1;
  }
}
