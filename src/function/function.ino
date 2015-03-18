// simple sketch that shows how to
// publish a function to the cloud

int pin = D7;

boolean blinkit = false;

int toggleBlinking(String command);

void setup(){
  pinMode(pin,OUTPUT);
  Spark.function("blink", toggleBlinking);
}

void loop(){
  /*
   nothing to see here
   everything happens in the function toggleBlink
  */
}

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
