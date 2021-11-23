# DIY-Ultrasonic-Sensor
Tugas Besar Kuliah Semester 3  

################################  
Repo ini berisi tentang proyek DIY Ultrasonic sensor  
Pada perkuliahan semester 3 ini kita diberi tugas untuk membuat suatu module sensor  
Kelompok ini mendapat bagian sensor yang berhubungan dengan suara  
Maka dari itu pada tugas ini kita memilih untuk membuat module sensor ultrasonic  
################################  
Pada module sensor ultrasonic ini kita menggunakan komponen-komponen sebagai berikut :  
=> Op-Amp LM324  
=> Max232  
=> Atmega328p  
=> Attiny85  
Semua komponen yang digunakan pada module sensor ini menggunakan package SMD  
Berikut skematik rangkaian dari module sensor ultrasonic ini :  
![image](https://user-images.githubusercontent.com/87922087/140260254-4bb3650d-98bf-4254-8854-eb126be2082e.png)  
Berikut fungsi dari tiap-tiap blok diatas :  
=> Transducer <=  
Berisi transducer berupa receiver dan transmitter ultrasonic  
=> Transducer TX Driver <=  
Berisi ic MAX232 yang digunakan sebagai voltage multiplier. Block ini akan mengkonversi tegangan sinyal masukan dari mikrokontroller atmega328p yang hanya sebesar 5V menjadi tegangan sebesar 7-10V yang selanjutnya diteruskan kepada ultrasonic transmitter. Proses step up tegangan ini digunakan untuk menambah jangkauan dari ultrasonic transmitter  
=> Amplifier RX Transducer <=  
Block ini digunakan untuk menguatkan sinyal yang diterima oleh ultrasonic receiver agar bisa terbaca oleh ADC atmega328p. Block ini memanfaatkan ic op-amp LM324 yang merupakan sebuah ic yang berisi 4 op-amp didalamnya. Keluaran dari block ini terhubung dengan pin ADC atmega328p yang selanjutnya akan diolah  
=> Kontroller Ultrasonic <=  
Block ini digunakan untuk mengontrol proses dari sensor ultrasonic. Block ini mengirimkan perintah ke Transducer TX Driver dan menerima masukan sinyal dari Amplifier RX Transducer. Pada block ini berisi ic atmega328p, proses control ultrasonic dapat dikontrol melalui pin ECHO dan TRIG yang dimana pin ini akan terkoneksi dengan ic attiny85  
=> Temp Sensor <=  
Block ini berisi sensor temperature berupa NTC 10k yang digunakan untuk membaca temperature dari modul sensor yan dibuat. Keluaran block ini terhubung dengan pin ADC attiny85  
=> Kontroller UART dan Temp Sensor <=  
Pada block ini berisi ic attiny85. Block ini digunakan untuk mengontrol pin ECHO dan TRIG dari controller ultrasonic lalu mengubahnya menjadi besaran panjang. Block ini juga digunakan untuk membaca masukan dari temp sensor lalu mengkonversinya menjadi besaran temperature. Selanjutnya besaran panjang dan temperature akan dikeluarkan melalui pin serial dari attiny85 yang selanjutnya data serial panjang dan temperature ini dapat dibaca melalui komunikasi serial UART dan diolah oleh controller selanjutnya. Kontroller selanjutnya dapat berupa ESP8266 yang dapat mengirimkan data panjang dan temperature melalui IoT  
=> Konektor <=  
Block ini berisi pinheader yang digunakan sebagai konektor pada modul sensor ini  
Berikut merupakan gambar render dari PCB sensor ultrasonic ini :  
=> Layer Atas <=  
![downImg](https://user-images.githubusercontent.com/87922087/142972408-27eeab5a-10c3-4f2c-ac0f-48ded6b537f9.png)  
=> Layer Bawah <=  
![downImg1](https://user-images.githubusercontent.com/87922087/142972438-dd70e104-4b69-4bdf-97ab-b572d6d56800.png)

