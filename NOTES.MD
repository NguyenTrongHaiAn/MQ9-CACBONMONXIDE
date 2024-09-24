**float R0 = 0.91;**    
R0 là điện trở của cảm biến trong điều kiện không có khí (hoặc trong không khí sạch). Giá trị này thường được xác định trong điều kiện chuẩn và có thể thay đổi tùy thuộc vào cảm biến cụ thể mà bạn đang sử dụng.
  
**sensor_volt = ((float)sensorValue / 1024) * 5.0;**  
Dòng này chuyển đổi giá trị sensorValue thành điện áp (V).  
Công thức sử dụng:  
sensorValue / 1024 sẽ chuyển đổi giá trị từ khoảng 0-1023 thành khoảng 0-1 (tỉ lệ).  
Nhân với 5.0 để chuyển đổi sang điện áp (V).  
    
**RS_gas = (5.0 - sensor_volt) / sensor_volt;**  
RS_gas là điện trở của cảm biến khi có khí. Công thức này dựa trên nguyên tắc Ohm và sự thay đổi điện áp trong cảm biến:  
  
**ratio = RS_gas / R0;**  
ratio là tỷ lệ giữa điện trở của cảm biến (RS_gas) và điện trở chuẩn (R0).  
Tỷ lệ này giúp bạn xác định nồng độ khí trong môi trường so với điều kiện chuẩn. Nếu tỷ lệ cao, có nghĩa là nồng độ khí cao hơn so với điều kiện chuẩn; ngược lại, tỷ lệ thấp cho thấy nồng độ khí thấp hơn.
