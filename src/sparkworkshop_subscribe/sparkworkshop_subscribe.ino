int pin = D7;
int state  = 0;
void myHandler(const char *event, const char *data);

void setup() {
  Spark.variable("state",&state, INT);
  Spark.subscribe("blinking", myHandler, MY_DEVICES);
pinMode(pin, OUTPUT);
}

void loop() {
}
void myHandler(const char *event, const char *data){
  if (!strcmp(data, "1")){
    digitalWrite(pin,HIGH);
    state = 1;
  }
  else if(!strcmp(data, "0")){
    digitalWrite(pin,LOW);
    state = 0;
  }
}
