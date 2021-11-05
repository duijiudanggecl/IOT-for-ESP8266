void user_init(void)
{
  uart_init(BIT_RATE_115200, BIT_RATE_115200);	// 
  os_delay_us(60000);
  CFG_Load();	
	MQTT_InitConnection(&mqttClient, sysCfg.mqtt_host, sysCfg.mqtt_port, sysCfg.security);

	MQTT_InitClient(&mqttClient, sysCfg.device_id, sysCfg.mqtt_user, sysCfg.mqtt_pass, sysCfg.mqtt_keepalive, 1);

	MQTT_OnConnected(&mqttClient, mqttConnectedCb);		
	MQTT_OnDisconnected(&mqttClient, mqttDisconnectedCb);	
	MQTT_OnPublished(&mqttClient, mqttPublishedCb);		
	MQTT_OnData(&mqttClient, mqttDataCb);					
	WIFI_Connect(sysCfg.sta_ssid, sysCfg.sta_pwd, wifiConnectCb);
	INFO("\r\nSystem started ...\r\n");
}
