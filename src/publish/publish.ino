
int pin = D7;
boolean blinkit = false;
int update = 5000;

int toggleBlinking(String command);

void setup() {
  Spark.function("blink", toggleBlinking);
  Spark.publish("fhpid", "1", 60, PRIVATE);
  pinMode(pin,OUTPUT);

}

int toggleBlinking(String command){

  if(command == "toggle"){

    blinkit = !blinkit;
    if(blinkit == true){
        digitalWrite(pin,HIGH);

        Spark.publish("fhpid", (blinkit == true) ? "1" : "0");

    }else{
        digitalWrite(pin,LOW);
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
