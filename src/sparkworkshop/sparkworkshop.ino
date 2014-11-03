
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