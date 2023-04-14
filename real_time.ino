int printLocalTime( int (& Time_now) [3] ){

  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return 0;
  }
  Time_now[0] = timeinfo.tm_hour;
  Time_now[1] = timeinfo.tm_min;
  Time_now[2] = timeinfo.tm_sec;
  
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.println("-----------------------------------");
}