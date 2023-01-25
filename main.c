/*
 * ======================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  FFT by decimation in time
 *
 *        Version:  1.0
 *        Created:  25/01/23 01:32:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "matrix_operations.h"
#include <stdio.h>
#include <complex.h>

#define SIGNAL_SIZE 8

#define PI			3.141592653589793f
#define TWO_PI		(2.0 * PI)

int
main(void)
{
	float complex* signal_example;

	float freq_A, freq_B;
	float sample_frequency = 16.0e3f;
	float sample_period	   = 1.0f / sample_frequency;

	signal_example		   = vector_create_cpx(SIGNAL_SIZE);

	freq_A				   = 1000.0f;
	freq_B				   = 2000.0f;
	for (int n = 0; n < SIGNAL_SIZE; n++)
	{
		signal_example[n] =
			csinf(TWO_PI * freq_A * n * sample_period) +
			0.5f * csinf(TWO_PI * freq_B * n * sample_period +
						 ((3.0f * PI) / 4.0f));
	}

#ifdef DEBUG_MODE
	printf("Signal Example (Complex Form):\n");
	print_vector_cpx(signal_example, SIGNAL_SIZE);
#endif

	vector_delete_cpx(signal_example);

	return 0;
}
