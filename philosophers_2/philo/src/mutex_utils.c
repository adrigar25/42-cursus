/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/03 23:03:44 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** MUTEX UTILITIES - Funciones para manejo seguro de variables compartidas
**
** Estas funciones simplifican el acceso a variables compartidas entre hilos,
** encapsulando el patrón lock-modify-unlock en funciones reutilizables.
**
** EJEMPLO DE USO:
**
** En lugar de escribir:
**     pthread_mutex_lock(&table->sim_stop_lock);
**     table->sim_stop = 1;
**     pthread_mutex_unlock(&table->sim_stop_lock);
**
** Puedes simplemente usar:
**     set_int(&table->sim_stop_lock, &table->sim_stop, 1);
**
** Para leer:
** En lugar de:
**     pthread_mutex_lock(&table->sim_stop_lock);
**     int stop = table->sim_stop;
**     pthread_mutex_unlock(&table->sim_stop_lock);
**
** Usa:
**     int stop = get_int(&table->sim_stop_lock, &table->sim_stop);
**
** BENEFICIOS:
** - Código más limpio y legible
** - Menos posibilidad de olvidar unlock
** - Consistencia en el manejo de mutex
** - Menos líneas de código
*/

#include "philo.h"

/*
** Establece un valor entero de forma segura con mutex
*/
void	set_int(pthread_mutex_t *mutex, int *dest, int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

/*
** Obtiene un valor entero de forma segura con mutex
*/
int	get_int(pthread_mutex_t *mutex, int *src)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *src;
	pthread_mutex_unlock(mutex);
	return (value);
}

/*
** Establece un valor long de forma segura con mutex
*/
void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

/*
** Obtiene un valor long de forma segura con mutex
*/
long	get_long(pthread_mutex_t *mutex, long *src)
{
	long	value;

	pthread_mutex_lock(mutex);
	value = *src;
	pthread_mutex_unlock(mutex);
	return (value);
}

/*
** Establece un valor unsigned int de forma segura con mutex
*/
void	set_uint(pthread_mutex_t *mutex, unsigned int *dest, unsigned int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

/*
** Obtiene un valor unsigned int de forma segura con mutex
*/
unsigned int	get_uint(pthread_mutex_t *mutex, unsigned int *src)
{
	unsigned int	value;

	pthread_mutex_lock(mutex);
	value = *src;
	pthread_mutex_unlock(mutex);
	return (value);
}

/*
** Establece un valor unsigned long de forma segura con mutex
*/
void	set_ulong(pthread_mutex_t *mutex, unsigned long *dest,
		unsigned long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

/*
** Obtiene un valor unsigned long de forma segura con mutex
*/
unsigned long	get_ulong(pthread_mutex_t *mutex, unsigned long *src)
{
	unsigned long	value;

	pthread_mutex_lock(mutex);
	value = *src;
	pthread_mutex_unlock(mutex);
	return (value);
}

/*
** Incrementa un valor entero de forma segura con mutex
*/
void	increment_int(pthread_mutex_t *mutex, int *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

/*
** Incrementa un valor unsigned int de forma segura con mutex
*/
void	increment_uint(pthread_mutex_t *mutex, unsigned int *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

/*
** Incrementa un valor long de forma segura con mutex
*/
void	increment_long(pthread_mutex_t *mutex, long *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

/*
** Verifica si un valor booleano (int) es verdadero de forma segura
*/
int	check_bool(pthread_mutex_t *mutex, int *flag)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *flag;
	pthread_mutex_unlock(mutex);
	return (result);
}

/*
** Manejo genérico de mutex mediante una acción.
** Devuelve 0 en éxito, o código de error de pthread_* en fallo.
** Acciones soportadas (ver philo.h):
** - MUTEX_INIT:    pthread_mutex_init(mutex, NULL)
** - MUTEX_LOCK:    pthread_mutex_lock(mutex)
** - MUTEX_TRYLOCK: pthread_mutex_trylock(mutex)
** - MUTEX_UNLOCK:  pthread_mutex_unlock(mutex)
** - MUTEX_DESTROY: pthread_mutex_destroy(mutex)
*/
int	mutex_handle(pthread_mutex_t *mutex, int action)
{
	if (!mutex)
		return (1);
	if (action == MUTEX_INIT)
		return (pthread_mutex_init(mutex, NULL));
	if (action == MUTEX_LOCK)
		return (pthread_mutex_lock(mutex));
	if (action == MUTEX_TRYLOCK)
		return (pthread_mutex_trylock(mutex));
	if (action == MUTEX_UNLOCK)
		return (pthread_mutex_unlock(mutex));
	if (action == MUTEX_DESTROY)
		return (pthread_mutex_destroy(mutex));
	return (1);
}

/*
** Verifica si la simulación ha sido detenida de forma segura
*/
int	simulation_stopped(t_table *table)
{
	int	ret;

	ret = 0;
	mutex_handle(&table->sim_stop_lock, MUTEX_LOCK);
	if (table->sim_stop == 1)
		ret = 1;
	mutex_handle(&table->sim_stop_lock, MUTEX_UNLOCK);
	return (ret);
}
