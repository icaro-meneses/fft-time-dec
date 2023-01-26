/*
 * ======================================================================
 *
 *       Filename:  fft_tdec.c
 *
 *    Description:  Source file for function implementation
 *					of FFT (decimation in time).
 *
 *        Version:  1.0
 *        Created:  25/01/23 16:32:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#include "fft_tdec.h"
#include "matrix_operations.h"
#include <stdio.h>
#include <complex.h>
#include <math.h>

void
fill_vector(float complex* dest_vector,
			float complex* src_vector,
			const int dest_vector_size,
			const int src_vector_size)
{
	int fill_op_size = src_vector_size;

	/* If the size of source vector is greater than destination
	 * vector, the source vector size is cut-off to same size of
	 * destination vector.
	 * Otherwise, the source vector is automatically zero-padded
	 * */
	if (src_vector_size > dest_vector_size)
	{
		fill_op_size = dest_vector_size;
	}

	for (int item = 0; item < fill_op_size; item++)
	{
		dest_vector[item] = src_vector[item];
	}
}

void
get_dft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing)
{
	int middle = ((window_length - 1) / 2) + 1;
	int i;
	int aux = 0;

	for (i = 0; i < middle; i++)
	{
		freq_array[i] = i;
	}

	i	= middle;
	aux = (-1) * (window_length / 2);
	while (aux < 0)
	{
		freq_array[i] = aux;

		aux++;
		i++;
	}

	for (i = 0; i < window_length; i++)
	{
		freq_array[i] =
			(float)freq_array[i] / (window_length * sample_spacing);
	}
}

void
fft_dec_time(float complex* signal, int N, bool inverse_mode)
{
	int Ndiv2 = N / 2;

	float complex* x_even;
	float complex* x_odd;

	if (N == 1)
	{
		return;
	}

	x_even = vector_create_cpx(Ndiv2);
	x_odd  = vector_create_cpx(Ndiv2);

	for (int n = 0; n < (Ndiv2); n++)
	{
		x_even[n] = signal[2 * n];
		x_odd[n]  = signal[2 * n + 1];
	}

	fft_dec_time(x_even, Ndiv2, false);
	fft_dec_time(x_odd, Ndiv2, false);

	float complex argument =
		(!inverse_mode) ? (-I * TWO_PI) : (I * TWO_PI);
	for (int k = 0; k < (Ndiv2); k++)
	{
		float complex Wn  = cexpf((argument * k) / N);
		signal[k]		  = x_even[k] + (Wn * x_odd[k]);
		signal[k + Ndiv2] = x_even[k] - (Wn * x_odd[k]);
	}

	vector_delete_cpx(x_even);
	vector_delete_cpx(x_odd);
}

