/*
*
*
*
*/
#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <MQTT_Client.hpp>
#include "SubscriberData.hpp"

enum mosq_err_t {
	MOSQ_ERR_SUCCESS = 0,
	MOSQ_ERR_INVAL = 3,
	MOSQ_ERR_NOMEM = 1,
};

struct mosquitto* mosquitto_new(const char *id, bool clean_session, void *obj);

bool callbackFun(MQTT_Client_NS::MQTT_Client::MQTT_Data_t& );
int mosquitto_subscribe_simple(
	struct mosquitto_message **messages,
	int msg_count,
	bool want_retained,
	const char *topic,
	int qos,
	const char *host,
	int port,
	const char *client_id,
	int keepalive,
	bool clean_session,
	const char *username,
	const char *password,
	const struct libmosquitto_will *will,
	const struct libmosquitto_tls *tls);

int mosquitto_subscribe_callback(
	int(*callback)(struct mosquitto *, void *, const struct mosquitto_message *),
	void *userdata,
	const char *topic,
	int qos,
	const char *host,
	int port,
	const char *client_id,
	int keepalive,
	bool clean_session,
	const char *username,
	const char *password,
	const struct libmosquitto_will *will,
	const struct libmosquitto_tls *tls);

int mosquitto_will_set(struct mosquitto *mosq, const char *topic, int payloadlen, const void *payload, int qos, bool retain);

void mosquitto_destroy(struct mosquitto *mosq);

int mosquitto_username_pw_set(struct mosquitto *mosq, const char *username, const char *password);

void mosquitto_destroy(struct mosquitto *mosq);

int mosquitto_tls_set(struct mosquitto *mosq,
	const char *cafile, const char *capath,
	const char *certfile, const char *keyfile,
	int(*pw_callback)(char *buf, int size, int rwflag, void *userdata));

int mosquitto_tls_opts_set(struct mosquitto *mosq, int cert_reqs, const char *tls_version, const char *ciphers);

void mosquitto_connect_callback_set(struct mosquitto *mosq, void(*on_connect)(struct mosquitto *, void *, int));

void mosquitto_message_callback_set(struct mosquitto *mosq, void(*on_message)(struct mosquitto *, void *, const struct mosquitto_message *));

static void on_connect(struct mosquitto *mosq, void *obj, int rc);

static void on_message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);

int mosquitto_connect(struct mosquitto *mosq, const char *host, int port, int keepalive);

int mosquitto_loop_forever(struct mosquitto *mosq, int timeout, int max_packets);

static int on_message_simple(struct mosquitto *mosq, void *obj, const struct mosquitto_message *message);

void mosquitto_message_free_contents(struct mosquitto_message *message);

int mosquitto_subscribe(struct mosquitto *mosq, int *mid, const char *sub, int qos);

int mosquitto_disconnect(struct mosquitto *mosq);

int mosquitto_message_copy(struct mosquitto_message *dst, const struct mosquitto_message *src);

#endif
