// this is an simple example how to listen to an event
// it needs another core to use the publish example
// provided in the repo
// if you toggle the LED on the other core
// on and off this core will react to it
//
int pin = D7; // the pin to toggle
int state  = 0; // a variable to publish

void toggleLed(const char *event, const char *data); // this handles the incoming evetns

/**
 * see
 * http://docs.spark.io/firmware/#spark-subscribe
 * for further info
 * The event is
 */
void toggleLed(const char *event, const char *data){
  Serial.print(event);
  Serial.print(", data: ");
  if (data){
    Serial.println(data);
  }else{
    Serial.println("NULL");
    }
  }

  // compare if the data is 1
  // if so turn on the LED
  if (strcmp(data, "1") == 0){
    digitalWrite(pin,HIGH);
    state = 1;
  }else if(strcmp(data, "0") == 0){
    // if the data is 0 turn of the LED
    digitalWrite(pin,LOW);
    state = 0;
  }
}


void setup() {
  pinMode(pin, OUTPUT); // the output pin
  Spark.variable("state",&state, INT); // this is just for reference
  // to see if we have subscribed to the event we once blink the led
  //
  bool gotit = Spark.subscribe("fhpid", toggleLed, MY_DEVICES);
  if(gotit == true){
      digitalWrite(pin, HIGH);
      delay(500);
      digitalWrite(pin, LOW);
  }

}

void loop() {
  /* nothing to see here */
}
