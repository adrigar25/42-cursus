#include <stdio.h>
#include <stdlib.h>

int	handle_error(int error_code)
{
    const char *msg;

    if (error_code == 1)
        msg = "Archivo de mapa no encontrado";
    else if (error_code == 2)
        msg = "Mapa inválido";
    else if (error_code == 3)
        msg = "Error de memoria";
    else if (error_code == 4)
        msg = "Error al inicializar gráficos";
    else
        msg = "Error desconocido";
    fprintf(stderr, "Error: %s\n", msg);
    return (0);
}