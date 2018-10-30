#include <iostream>
#include "SampleApp/MQTTClient.h"

MQTTClient::MQTTClient() {

}

MQTTClient::~MQTTClient() {

}

bool MQTTClient::init(const char *id, const char *host, int port) {
    is_connected = false;
    int rc = reinitialise(id, true);
    if (rc != MOSQ_ERR_SUCCESS) {
        return false;
    }

    int keep_alive = 60;
    connect(host, port, keep_alive);
    
    // create loop thread
    loop_tid = std::thread(&MQTTClient::loop2, MQTTClient::Instance());
    return true;
}

void MQTTClient::on_connect(int rc) {
    std::cout << "Client connected: " << rc << std::endl;
    is_connected = true;
}

void MQTTClient::on_message(const struct mosquitto_message *message) {

}

void MQTTClient::on_subscribe(int mid, int qos_count, const int *granted_qos) {

}

void MQTTClient::loop2() {
    int rc = 0;
    while(1) {
        rc = MQTTClient::Instance()->loop();
        if (rc) {
            MQTTClient::Instance()->reconnect();
        }
    }
}
