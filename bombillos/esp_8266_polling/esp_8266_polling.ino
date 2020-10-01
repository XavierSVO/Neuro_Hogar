//librerias
#include <ESP8266WiFi.h>
//ssid (nombre) del router
const char* ssid = "";
//password del router
const char* password = "";
//direccion ip del host
String host = "";

void setup() {
  // put your setup code here, to run once:
  //declarar los baudios por segundos para la comunicacion Serial
  Serial.begin(115200);
  //Iniciar la conexion con el router
  WiFi.begin(ssid, password);
  //esperar a que se realice la conexion
  //mientras la conexion con el wifi no sea exitosa
  while (WiFi.status() != WL_CONNECTED)
  {
    //esperar 500 milisegundos
    delay(500);
    //imprimir por el monitor serial el estado de la conexion
    Serial.print("Conectadose al wifi");
  }
  //Si la conexion fue exitosa imprimir la direccion ip que asigno el router a nuestro node mediante dhcp
  Serial.print(WiFi.localIP());




}



void loop() {
  // put your main code here, to run repeatedly:
  //declarar una instancia de Wifi Client
  WiFiClient client;
  //declarar el puerto de http donde nos conectaremos
  const int httpPort = 80;
  //si el cliente no se conecta con el host por el puerto http
  if (!client.connect(host, httpPort))
  {
    Serial.println("Conexion del cliente por http fallida");
    return;
  }
  //variable donde se almacenera la url de nuestro router;
  String url = "http://" + host;
  //datos que enviaremos con el metodo post

  String data = "var1=" ;
  //declarar el metodo de envio de datos de php
  String method = "POST ";
  //la instruccion que enviaremos al servidor;
  client.print(method + url + " HTTP/1.0\r\n" +
               "Host: " + host + "\r\n" +
               "Accept: *" + "/" + "*\r\n" +
               "Content-Length: " + data.length() + "\r\n" +
               "Content-Type:application/x-www-form-urlencoded\r\n" +
               "\r\n" + data);
  //colocar un retraso esperando que se envio toda la instruccion
  delay(10);
  //leer las respuestas del servidor
  Serial.print("Respuetas del servidor");
  //mienstras el servidor este disponible
  while (client.available())
  {
    //obtener en una linea las respuestas del servidor
    String line = client.readStringUntil('\r');
    //Imprimir en el monitor serial las respuestas del servidor
    Serial.print(line);

  }












}
