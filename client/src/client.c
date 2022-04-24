#include "client.h"

int main(void)
{
    /*---------------------------------------------------PARTE 1-------------------------------------------------------------*/

	// definicion de parametro utilizado para crear la instancia del archivo de config
	char* path = string_new();

	// configuro el valor de parametro para crear la instancia del archivo de config
	string_append(&path, "/home/utnso/shared_folder/so-tp0/client/configs/tp0.config");

	// creacion de la instancia del archivo de config
	t_config* config_file = config_create(path);

	// creo la key a leer del archivo config 
	char* key = string_new();
	string_append(&key, "CLAVE"); 

	// leo el value de la key del archivo de config
	char* key_value = string_new();
	key_value = config_get_string_value(config_file, key);

    // definicion de parametros utilizados para crear la instancia de logger
    char* file = string_new();
    char* process_name = string_new();
    bool is_active_console;
    t_log_level level;

    // configuro el valor de parametros para crear la instancia de logger
    string_append(&file, "/home/utnso/shared_folder/so-tp0/client/logs/tp0.log");
    string_append(&process_name, "PROCESO_DEL_TP0");
    is_active_console = true;
    level = LOG_LEVEL_INFO;

    // creacion de la instancia del logger
    t_log* logger = log_create(file, process_name, is_active_console, level);

	// usamos log_info para loggear el string "Soy un Log"
	log_info(logger, key_value);

	// cierro la instancia del archivo de config
	config_destroy(config_file);

	// cerramos el logger
	log_destroy(logger);
}
