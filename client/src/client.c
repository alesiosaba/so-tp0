#include "client.h"

int main(void)
{
    /*---------------------------------------------------PARTE 1-------------------------------------------------------------*/

    // definicion de parametros utilizados para crear la instancia de logger
    char* file = string_new();
    char* process_name = string_new();
    bool is_active_console;
    t_log_level level;

    // configuro el valor de parametros para crear la instancia de logger
    string_append(&file, "/home/utnso/logs/tp0.log");
    string_append(&process_name, "PROCESO_DEL_TP0");
    is_active_console = true;
    level = LOG_LEVEL_INFO;

    // creacion de la instancia del logger
    t_log* logger = log_create(file, process_name, is_active_console, level);

	// usamos log_info para loggear el string "Soy un Log"
	log_info(logger, "Soy un Log");

	// cerramos el logger
	log_destroy(logger);
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

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
}
