#pragma once
class SubscriberData
{
public:
	SubscriberData();
	~SubscriberData();
};

// KLASE W SUMIE MOZNA WYWALIC UB TA STRUKTURE JAKKOS DO NIEJ WRZUCI 

typedef unsigned int UINT_PTR, *PUINT_PTR;
typedef UINT_PTR	SOCKET;
typedef SOCKET mosq_sock_t;

typedef struct mosquitto_message {
	int mid;
	char *topic;
	void *payload;
	int payloadlen;
	int qos;
	bool retain;
};

typedef struct userdata__simple {
	struct mosquitto_message *messages;
	int max_msg_count;
	int message_count;
	bool want_retained;
};

typedef struct userdata__callback {
	const char *topic;
	int (*callback)(struct mosquitto *, void *, const struct mosquitto_message *);
	void *userdata;
	int qos;
	int rc;
};

struct libmosquitto_will {
	char *topic;
	void *payload;
	int payloadlen;
	int qos;
	bool retain;
};

struct libmosquitto_tls {
	char *cafile;
	char *capath;
	char *certfile;
	char *keyfile;
	char *ciphers;
	char *tls_version;
	int(*pw_callback)(char *buf, int size, int rwflag, void *userdata);
	int cert_reqs;
};


