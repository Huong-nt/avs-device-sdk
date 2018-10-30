#!/usr/bin/env python
# -*- coding: utf-8 -*-
from datetime import datetime
import paho.mqtt.client as paho
import yaml
from pixels import pixels

TOPIC_LED = 'avs/led/control'

ACTION = {
    'LISTEN': pixels.listen,
    'THINK': pixels.think,
    'SPEAK': pixels.speak,
    'OFF': pixels.off,
}
pixels.think()

def on_connect(mosq, obj, flags, rc):
    print("rc: " + str(rc))

def on_message(mosq, obj, msg):
    payload = yaml.safe_load(msg.payload)
    print "%-30s  %s" % (str(datetime.now()), payload)
    if payload['action'] in ACTION:
        ACTION[payload['action']]()

if __name__ == '__main__':
    client = paho.Client()
    client.on_message = on_message
    client.on_connect = on_connect
    client.connect("127.0.0.1", 1883, 60)
    client.subscribe([(TOPIC_LED, 0)])
    client.loop_forever()
