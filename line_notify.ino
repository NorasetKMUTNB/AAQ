bool safe_state = 1;

 void notify(float pm) {
    // SendWriteRequestToThingSpeak(t);
    // if ( pm < 50.0 && safe_state == 0) {
    if ( pm < 50.0) {
    // หากค่าอุณหภูมิน้อยกว่า30องศา LINE Notify จะแจ้งเตือนข้อความ
    LINE.notify("\nอากาศบริเวณนี้ปลอดภัยงับ \nค่า PM2.5:"+ String(pm,3));
    change_state(safe_state);
    }
    // else if ( pm >= 50.0 && safe_state == 1) {
    else if ( pm >= 50.0) {
    //หากค่าอุณหภูมิมากกว่าเท่ากับ30องศา LINE Notify จะแจ้งเตือนข้อความ
    LINE.notify("\nอากาศบริเวณนี้ต้องใส้ mask ป้องกันแล้วนะงับ \nค่า PM2.5:"+String(pm,3));
    change_state(safe_state);
    }
}

bool change_state(bool state){
  state = !state;
}

void check_device(){
  // Check Disconnect Device 
  if (!Check_dht() && !check_sps30()) {
    // disconect 2
    LINE.notify("\nDHT22 and SPS30 are disconnect");

  } else if ( Check_dht() && !check_sps30()) {
    // sps30 disconnect 
    LINE.notify("\nSPS30 is disconnect");

  } else if ( !Check_dht() && check_sps30()){
    // dht22 disconnect 
    LINE.notify("\nDHT22 is disconnect");
  }
}