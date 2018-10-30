#ifndef _MQTTCLIENT_H_
#define _MQTTCLIENT_H_

#include <iostream>
#include "mosquittopp.h"
#include "SampleApp/Singleton.h"
#include <thread>
#include <iostream>

class MQTTClient: public mosqpp::mosquittopp, public Singleton<MQTTClient> {
friend class Singleton<MQTTClient>;
    bool is_connected;
public:
    MQTTClient();
    virtual ~MQTTClient();

    bool init(const char *id, const char *host, int port);
    void on_connect(int rc);
    void on_message(const struct mosquitto_message *message);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);
    
private:
    void loop2();
    
private:
    std::thread loop_tid;
};


#endif
