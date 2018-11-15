#include <ArduinoJson.h>
#include <HttpPacket.h>
 
#define DEVICE_ID "78488"
#define HOSTADD "api.heclouds.com"
#define API_KEY  "B4ZGKmtaL5eJw6NIpjEEI+kULqQ="
#define TRYTIMES 3
#define RET_OK   0
#define RET_ERR  1
 
unsigned long timer1 = 0, timer2 = 0, comeIn = 0, goOut = 0;
char flag1 = 0, flag2 = 0;
StaticJsonBuffer<200> jsonBuffer;
char jsonStr[200] = {0};
HttpPacketHead packetHead;
 
void setup()
{
    Serial1.begin(115200);
    Serial.begin(115200);
 
    while (!Serial1)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
 
    attachInterrupt(0, getEventTime1, FALLING);
    attachInterrupt(1, getEventTime2, FALLING);
 
    while (1)
    {
        Serial1.println("AT+COPS?\r");
        delay(200);
 
        if (Serial1.find("CHINA") == true )
        {
            Serial.println("CHINA MOBILE");
            break;
        }
    }
    sendCmd("AT+CLPORT=\"TCP\",\"2000\"\r");
}
 
void loop()
{
    establishTCPConnect("AT+CIPSTART=\"TCP\",\"183.230.40.33\",\"80\"\r");
    startSendData("AT+CIPSEND\r");
    JsonObject &jsonData = jsonBuffer.createObject();
 
    JsonArray &data = jsonData.createNestedArray("datastreams");
    addJsonDataRecord("come_in", comeIn, data);
    addJsonDataRecord("Go_out", goOut, data);
 
    jsonData.printTo(jsonStr, 200);
 
    packetHead.setHostAddress(HOSTADD);
    packetHead.setDevId(DEVICE_ID);
    packetHead.setAccessKey(API_KEY);
    packetHead.createCmdPacket(POST, TYPE_DATAPOINT, jsonStr);
 
    Serial1.print(packetHead.content);
    jsonData.printTo(Serial1);
    Serial1.println("");
    delay(500);
    closeTCPConnect("AT+CIPCLOSE\r");
    delay(1000);
}
 
void getEventTime1(void)
{
    timer1 = millis();
    Serial.println(timer1);
    flag1 = 1;
 
    if (flag2)
    {
        flag1 = 0;
        flag2 = 0;
        if (timer2 > timer1)
        {
            comeIn ++;
        }
        else
        {
            goOut ++;
        }
    }
}
 
void getEventTime2(void)
{
    timer2 = millis();
    Serial.println(timer2);
    flag2 = 1;
 
    if (flag1)
    {
        flag1 = 0;
        flag2 = 0;
        if (timer2 > timer1)
        {
            comeIn ++;
        }
        else
        {
            goOut ++;
        }
    }
}
 
void addJsonDataRecord(char key[], int value, JsonArray &array)
{
    JsonObject &root = array.createNestedObject();
    root.add("id", key);
    JsonArray &data = root.createNestedArray("datapoints");
    JsonObject &root1 = data.createNestedObject();
    root1.add("value", value);
}
 
char startSendData(String data)
{
    int i = 0;
    Serial1.println(data);
    while (1)
    {
        delay(1000);
        if ((Serial1.find(">") == true) || i > TRYTIMES)
        {
            Serial.println(data);
            break;
        }
        Serial1.println(data);
        i++;
    }
    return RET_OK;
}
 
char sendCmd(String data)
{
    int i = 0;
    Serial1.println(data);
    while (1)
    {
        delay(1000);
        if ((Serial1.find("OK") == true))//|| i > TRYTIMES)
        {
            Serial.println(data);
            break;
        }
        Serial1.println(data);
        i++;
    }
    return RET_OK;
}
 
char establishTCPConnect(String data)
{
    int i = 0;
    Serial1.println(data);
    while (1)
    {
        delay(1000);
        if ((Serial1.find("CONNECT OK") == true) || i > TRYTIMES)
        {
            //LedFlash();
            Serial.println("CONNECT OK");
            break;
        }
        Serial1.println(data);
        i++;
    }
    return RET_OK;
}
 
char closeTCPConnect(String data)
{
    int i = 0;
    Serial1.println(data);
    while (1)
    {
        delay(1000);
        if ((Serial1.find("CLOSE OK") == true) || i > TRYTIMES)
        {
            Serial.println("CLOSE OK");
            break;
        }
        Serial1.println(data);
        i++;
    }
    return RET_OK;
}