/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
/*  Private Funtions of protocol example common */

#pragma once

#include "esp_err.h"
#include "esp_wifi.h"
#include "sdkconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

#if CONFIG_CONNECT_IPV6
#define MAX_IP6_ADDRS_PER_NETIF (5)

#if defined(CONFIG_CONNECT_IPV6_PREF_LOCAL_LINK)
#define CONNECT_PREFERRED_IPV6_TYPE ESP_IP6_ADDR_IS_LINK_LOCAL
#elif defined(CONFIG_CONNECT_IPV6_PREF_GLOBAL)
#define CONNECT_PREFERRED_IPV6_TYPE ESP_IP6_ADDR_IS_GLOBAL
#elif defined(CONFIG_CONNECT_IPV6_PREF_SITE_LOCAL)
#define CONNECT_PREFERRED_IPV6_TYPE ESP_IP6_ADDR_IS_SITE_LOCAL
#elif defined(CONFIG_CONNECT_IPV6_PREF_UNIQUE_LOCAL)
#define CONNECT_PREFERRED_IPV6_TYPE ESP_IP6_ADDR_IS_UNIQUE_LOCAL
#endif // if-elif CONFIG_CONNECT_IPV6_PREF_...

#endif


#if CONFIG_CONNECT_IPV6
extern const char *ipv6_addr_types_to_str[6];
#endif

void wifi_start(void);
void wifi_stop(void);
esp_err_t wifi_sta_do_connect(wifi_config_t wifi_config, bool wait);
esp_err_t wifi_sta_do_disconnect(void);
bool is_our_netif(const char *prefix, esp_netif_t *netif);
void print_all_netif_ips(const char *prefix);
void wifi_shutdown(void);
esp_err_t wifi_connect(void);
void ethernet_shutdown(void);
esp_err_t ethernet_connect(void);

#ifdef __cplusplus
}
#endif
