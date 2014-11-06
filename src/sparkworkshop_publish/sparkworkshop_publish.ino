int toggleBlinking(String command);
int pin = D7;
int count = 0;
boolean blinkit = false;
int update = 1000;

void setup() {
  Spark.variable("count",&count, INT);
  Spark.function("blink", toggleBlinking);
  Spark.publish("fhpid", "1", 60, PRIVATE);

  pinMode(pin,OUTPUT);

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
  }else{

    return -1;
  }
}

void loop() {
    if(millis() > update){
        update+= millis();
        Spark.publish("fhpid", (blinkit == true) ? "1" : "0");
    }
    count++;
}