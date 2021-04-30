
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

/** Prerequisites
 * 
 * Cloud Functions deployment requires the pay-as-you-go (Blaze) billing plan.
 * 
 * IAM owner permission required for service account used and Cloud Build API must be enabled,
 * https://github.com/mobizt/Firebase-ESP-Client#iam-permission-and-api-enable
*/

/* Cloud Functions deployment requires the pay-as-you-go (Blaze) billing plan. */

/** This example shows how to list the Cloud Functions. 
 * 
 * This operation required OAUth2.0 authentication.
*/

/** Due to the processing power in ESP8266 is weaker than ESP32, the OAuth2.0 token generation takes time then this example
 * will check for token to be ready in loop prior to list the Cloud Functions.
*/

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

/* 2. Define the Firebase project host name (required) */
#define FIREBASE_PROJECT_HOST "PROJECT_ID.firebaseio.com"

/** 3. Define the Service Account credentials (required for token generation)
 * 
 * This information can be taken from the service account JSON file.
 * 
 * To download service account file, from the Firebase console, goto project settings, 
 * select "Service accounts" tab and click at "Generate new private key" button
*/
#define FIREBASE_PROJECT_ID "PROJECT_ID"
#define FIREBASE_CLIENT_EMAIL "CLIENT_EMAIL"
const char PRIVATE_KEY[] PROGMEM = "-----BEGIN PRIVATE KEY-----XXXXXXXXXXXX-----END PRIVATE KEY-----\n";

/* 4. Define the project location e.g. us-central1 or asia-northeast1 */
//https://firebase.google.com/docs/projects/locations
#define PROJECT_LOCATION "PROJECT_LOCATION"

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

bool taskCompleted = false;

unsigned long dataMillis = 0;

/* The function to list the Cloud Functions */
void listFunctions();

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

    /* Assign the project host (required) */
    config.host = FIREBASE_PROJECT_HOST;

    /* Assign the Service Account credentials */
    config.service_account.data.client_email = FIREBASE_CLIENT_EMAIL;
    config.service_account.data.project_id = FIREBASE_PROJECT_ID;
    config.service_account.data.private_key = PRIVATE_KEY;

    /* Assign the callback function for the long running token generation task */
    config.token_status_callback = tokenStatusCallback;

    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);

#if defined(ESP8266)
    //Set the size of WiFi rx/tx buffers in the case where we want to work with large data.
    fbdo.setBSSLBufferSize(1024, 1024);
#endif
}

void loop()
{
    if (Firebase.ready() && !taskCompleted)
    {
        listFunctions();
        taskCompleted = true;
    }
}

void listFunctions()
{

    Serial.println("------------------------------------");
    Serial.println("List the Googgle Cloud Functions...");

    if (Firebase.Functions.listFunctions(&fbdo, FIREBASE_PROJECT_ID /* project id */, PROJECT_LOCATION /* project location */, 1 /* page size */))
    {
        Serial.println("PASSED");
        Serial.println(fbdo.payload());
        Serial.println("------------------------------------");
        Serial.println();
    }
    else
    {
        Serial.println("FAILED");
        Serial.println("REASON: " + fbdo.errorReason());
        Serial.println("------------------------------------");
        Serial.println();
    }
}
