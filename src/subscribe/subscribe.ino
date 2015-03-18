
int pin = D7;
int state  = 0;

void toggleLed(const char *event, const char *data);

void toggleLed(const char *event, const char *data){
  if (strcmp(data, "1") == 0){
    digitalWrite(pin,HIGH);
    state = 1;
  }
  else if(strcmp(data, "0") == 0){
    digitalWrite(pin,LOW);
    state = 0;
  }
}


void setup() {

pinMode(pin, OUTPUT);
  Spark.variable("state",&state, INT);
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
