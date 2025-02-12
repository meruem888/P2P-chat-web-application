#pragma once
#include <tox.h>
#include <string>
#include <list>
#include <sodium.h>
#include <unistd.h>
#include <thread>
#include "../event_loop/event_loop.hpp"
#include <glog/logging.h>

namespace tox{
    struct dht_node {
        const char *ip;
        uint16_t port;
        const char key_hex[TOX_PUBLIC_KEY_SIZE*2 + 1];
    };
    class self_node {
        public:
            self_node( event::event_loop *main_event_loop,
                    std::list<dht_node> *dht_node_list = nullptr,
                    std::string *serialization_path = nullptr );
            ~self_node();
            std::thread spawn();
            void stop_instance();
            event::event_loop *main_event_loop;
        private:
            friend class self_node_cb;
            void node_bootstrap();
            bool setup_options();
            void set_tox_id();
            void connect_cb();
            std::string * serialization_path;
            std::string * user_name;
            std::string * user_status;
            std::string * user_tox_id;
            std::list<dht_node> *dht_node_list;
            Tox_Options   node_options;
            bool node_first_run;
            bool tox_stopped = false;
            /* node_status */
            Tox* tox_c_instance;
            void main_loop();
            void register_handlers(); 
            void register_tox_callbacks();
            void update_savedata_file();
            bool auto_accept = false;
            bool enable_trace = true;
            const char *savedata_filename = "savedata.tox";
            const char *savedata_tmp_filename = "savedata.tox.tmp";

    };
};
