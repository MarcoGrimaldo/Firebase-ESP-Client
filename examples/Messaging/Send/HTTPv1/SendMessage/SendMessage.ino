/**
 * Created by K. Suwatchai (Mobizt)
 * 
 * Email: k_suwatchai@hotmail.com
 * 
 * Github: https://github.com/mobizt
 * 
 * Copyright (c) 2021 mobizt
 *
*/

//This example shows how to send JSON payload FCM to a recipient via HTTPv1 API.
//This new API requires OAuth2.0 authentication.

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"

/* 1. Define the WiFi credentials */
#define WIFI_SSID "WIFI_AP"
#define WIFI_PASSWORD "WIFI_PASSWORD"

/** 2. Define the Service Account credentials (required for token generation)
 * 
 * This information can be taken from the service account JSON file.
 * 
 * To download service account file, from the Firebase console, goto project settings, 
 * select "Service accounts" tab and click at "Generate new private key" button
*/
#define FIREBASE_PROJECT_ID "PROJECT_ID"
#define FIREBASE_CLIENT_EMAIL "CLIENT_EMAIL"
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----XXXXXXXXXXXX-----END PRIVATE KEY-----\n";

/* 3. Define the ID token for client or device to send the message */
#define DEVICE_REGISTRATION_ID_TOKEN "DEVICE_TOKEN"

/* 4. Define the Firebase Data object */
FirebaseData fbdo;

/* 5. Define the FirebaseAuth data for authentication data */
FirebaseAuth auth;

/* 6. Define the FirebaseConfig data for config data */
FirebaseConfig config;

unsigned long lastTime = 0;

int count = 0;

void sendMessage();

void setup()
{

    Serial.begin(115200);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

    /* Assign the sevice account credentials and private key (required) */
    config.service_account.data.client_email = FIREBASE_CLIENT_EMAIL;
    config.service_account.data.project_id = FIREBASE_PROJECT_ID;
    config.service_account.data.private_key = PRIVATE_KEY;

    /* Assign the callback function for the long running token generation task */
    config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

    Firebase.begin(&config, &auth);

    Firebase.reconnectWiFi(true);
}

void loop()
{

    if (Firebase.ready() && (millis() - lastTime > 60 * 1000))
    {
        lastTime = millis();

        sendMessage();
    }
}

void sendMessage()
{

    Serial.print("Send Firebase Cloud Messaging... ");

    //Read more details about HTTP v1 API here https://firebase.google.com/docs/reference/fcm/rest/v1/projects.messages
    FCM_HTTPv1_JSON_Message msg;

    msg.token = DEVICE_REGISTRATION_ID_TOKEN;

    msg.notification.body = "Notification body";
    msg.notification.title = "Notification title";

    FirebaseJson json;
    String payload;

    //all data key-values should be string
    json.add("temp", "28");
    json.add("unit", "celsius");
    json.add("timestamp", "1609815454");
    json.toString(payload);
    msg.data = payload.c_str();

    if (Firebase.FCM.send(&fbdo, &msg)) //send message to recipient
        Serial.printf("ok\n%s\n\n", Firebase.FCM.payload(&fbdo).c_str());
    else
        Serial.println(fbdo.errorReason());

    count++;
}
