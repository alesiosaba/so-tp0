#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_info(logger, "Soy un log");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");

	// Loggeamos el valor de config
	char* clave = config_get_string_value(config, "CLAVE");
	log_info(logger, clave);

	/* ---------------- LEER DE CONSOLA ---------------- */

	// leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(clave, conexion);

	// Armamos y enviamos el paquete
	// paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
    // definicion de parametros utilizados para crear la instancia de logger
    char* file = string_new();
    char* process_name = string_new();
    bool is_active_console;
    t_log_level level;

    // configuro el valor de parametros para crear la instancia de logger
    string_append(&file, "/home/utnso/shared_folder/so-tp0/client/logs/tp0.log");
    string_append(&process_name, "CLIENTE");
    is_active_console = true;
    level = LOG_LEVEL_INFO;

	t_log* nuevo_logger = log_create(file, process_name, is_active_console, level);

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	// definicion de parametro utilizado para crear la instancia del archivo de config
	char* path = string_new();

	// configuro el valor de parametro para crear la instancia del archivo de config
	string_append(&path, "/home/utnso/shared_folder/so-tp0/client/cliente.config");

	// creacion de la instancia del archivo de config
	t_config* nuevo_config = config_create(path);

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	while(strcmp(leido,"\0") != 0)
	{
		log_info(logger, leido);
		free(leido);

		leido = readline("> ");
	}

	// ¡No te olvides de liberar las lineas antes de regresar!
	free(leido);

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	log_destroy(logger);
	config_destroy(config);
	close(conexion);
}