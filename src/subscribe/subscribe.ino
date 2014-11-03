int pin = D7;

void setup() {
  pinMode(pin, OUTPUT);
  Spark.subscribe("blinking", myHandler, MY_DEVICES);
  Serial.begin(9600);
}

void myHandler(const char *event, const char *data){
  i++;
  Serial.print(i);
  Serial.print(event);
  Serial.print(", data: ");
  if (data)
    Serial.println(data);
  else
    Serial.println("NULL");
}


void loop() {


}
