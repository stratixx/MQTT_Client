/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca protokół klienta MQTT
*
*/

#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <boost/smart_ptr.hpp>
#include <string>
#include "Connection.h"

namespace MQTT_Client_NS
{
	using namespace std;
	using namespace boost;

    class MQTT_Client;

    class MQTT_Client
    {
    public:
      //typedef std::shared_ptr<MQTT_Client*>   PMQTT_Client;
      //typedef std::weak_ptr<MQTT_Client*>     PWMQTT_Client;
      typedef struct
      {
        typedef enum
        {
          NONE,
          TEXT, 

        }data_t;

        string data;
        data_t dataType;
        string topic;
      }MQTT_Data_t;

      typedef bool (*callback_t)(MQTT_Data_t&);
      typedef int port_t;
      typedef std::string address_t;
      typedef std::string topicName_t;

      Connection* connection;
      callback_t callback;
      port_t port;
      address_t address;

      bool spinOnce();
      bool spin();

      bool setConnectionType(std::string);
      void setCallback(callback_t);
      void setPort(port_t);
      void setAddress(std::string&);
      void setAddress(const char*);

      bool connect(std::string hostname, port_t port, int keepalive);
      void disconnect();

      bool subscribe(std::string&);
      bool subscribe(const char*);

      bool unsubscribe(std::string&);
      bool unsubscribe(const char*);

      bool publish(std::string&, MQTT_Data_t&);
      bool publish(const char*, MQTT_Data_t&);


      MQTT_Client();
      ~MQTT_Client();
    private:
		//PMQTT_Client mqtt_ClientPtr_;
    };

	//#################################################
	// mosquitto od Doliego


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
		int(*callback)(struct mosquitto *, void *, const struct mosquitto_message *);
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


	struct mosquitto {

	};

	enum mosq_err_t {
		MOSQ_ERR_SUCCESS = 0,
		MOSQ_ERR_INVAL = 3,
		MOSQ_ERR_NOMEM = 1,
	};

	struct mosquitto* mosquitto_new(const char *id, bool clean_session, void *obj);

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

}

#endif