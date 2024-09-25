const int BUZZER = 2;  // Chân kết nối còi báo động
const int DO = 8;      // Chân đầu ra từ cảm biến-nối chân digital của MQ3

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT); // Thiết lập chân còi báo động là OUTPUT
    pinMode(DO, INPUT);      // Thiết lập chân DO là INPUT
}

void loop() {
    int alarm = 0;
    float sensor_volt;
    float RS_gas;
    float ratio;

    // -Replace the name "R0" with the value of R0 in the demo of First Test -/
    float R0 = 0.91; 
    int sensorValue = analogRead(A0);
    sensor_volt = ((float)sensorValue / 1024) * 5.0;
    RS_gas = (5.0 - sensor_volt) / sensor_volt; // Tùy thuộc vào RL trên module của bạn
    ratio = RS_gas / R0; // ratio = RS/R0
    //------------------------------------------------------------/

    Serial.print("sensor_volt = "); 
    Serial.println(sensor_volt); 
    Serial.print("RS_ratio = "); 
    Serial.println(RS_gas); 
    Serial.print("Rs/R0 = "); 
    Serial.println(ratio); 
    Serial.print("\n\n"); 

    alarm = digitalRead(DO);
    if (alarm == 1) {
        digitalWrite(BUZZER, HIGH); // Bật còi báo động
    } else {
        digitalWrite(BUZZER, LOW); // Tắt còi báo động
    }

    delay(1000); 
}

