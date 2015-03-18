// simple sketch that publishes a variable
// to the cloud
int count = 0; // our counter
int ping = 0; // this is just to have an on off value
void setup(){
  Spark.variable("count",&count, INT); // publish the variable
  Spark.variable("ping",&ping, INT); // publish the ther variable
}


void loop(){

delay(100);
  // Every 1/10 second increment the cout variable
  count++;
// to have some timeing
// if every 100 counts the variable ping gets
// set to 1
if(count%100 < 10){
    ping = 1;
  }else{
    ping = 0;
  }
}
