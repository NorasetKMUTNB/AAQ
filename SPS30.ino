
#define SP30_COMMS Serial1
#define DEBUG 0

float read_sps(){

  sps30.start();
  uint8_t ret, error_cnt = 0;
  struct sps_values val;

  // loop to get data
  do {

    ret = sps30.GetValues(&val);

    // data might not have been ready
    if (ret == SPS30_ERR_DATALENGTH){

        if (error_cnt++ > 3) {
          Serial.println( "Error SPS30 during reading values: 1");
          return(false);
        }
    }

    // if other error
    else if(ret != SPS30_ERR_OK) {
     Serial.println( "Error SPS30 during reading values: 2");

      return(false);
    }

  } while (ret != SPS30_ERR_OK);

  float pm = val.MassPM2;
  // Serial.print("PM2.5 = ");
  // Serial.println(pm);
  sps30.stop();
  return pm;
}

void connect_sps30(){
  // SPS30 setup
  SP30_COMMS.begin(115200, SERIAL_8N1, 23, 19);

  // Initialize SPS30 library
  init_sps30();

  // check for SPS30 connection
  check_sps30();
 
  // reset SPS30 connection
  reset_sps30();

  // start measurement
  start_sps30();
}

void init_sps30(){
  // Initialize SPS30 library
  if (! sps30.begin(&SP30_COMMS))
  Serial.println("Could not set serial communication channel.");
}

bool check_sps30(){
  // check for SPS30 connection
  if (! sps30.probe()){
    Serial.println("could not probe / connect with SPS30.");
    return false;
  }
  else{
    // Serial.println(("Detected SPS30."));
    return true;
  }
}

void reset_sps30(){
  // reset SPS30 connection
  if (! sps30.reset()) Serial.println("could not reset.");  
}

void start_sps30(){
  // start measurement
  if (sps30.start()) Serial.println(F("Measurement started"));
  else Serial.println( "Could NOT start measurement");
}