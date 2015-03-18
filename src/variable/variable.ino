// simple sketch that publishes a variable
// to the cloud
int count = 0;
int ping = 0;
void setup(){
  Spark.variable("count",&count, INT);
  Spark.variable("ping",&ping, INT);

}

void loop(){
delay(100);
    count++;


if(count%100 < 10){
    ping = 1;

  }else{
    ping = 0;
  }
}
