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

#include <math.h>
#include <stdio.h>
#include <complex.h>
#include "matrix_operations.h"
#include "fft_tdec.h"
#include "out_file.h"

#define SIGNAL_SIZE 8192
#define FFT_SIZE	8192

int
main(void)
{
	float complex* signal_example;
	float complex* fft_output;
	float* fft_freqs;
	float* fft_abs;

	float freq_A, freq_B;
	float sample_frequency = 8.0e3f;
	float sample_period	   = 1.0f / sample_frequency;

	signal_example		   = vector_create_cpx(SIGNAL_SIZE);
	fft_output			   = vector_create_cpx(FFT_SIZE);
	fft_freqs			   = vector_create(FFT_SIZE);

	get_fft_freqs(fft_freqs, FFT_SIZE, sample_period);

	freq_A = 1000.0f;
	freq_B = 2000.0f;
	for (int n = 0; n < SIGNAL_SIZE; n++)
	{
		signal_example[n] =
			csinf(TWO_PI * freq_A * n * sample_period) +
			0.5f * csinf(TWO_PI * freq_B * n * sample_period +
						 ((3.0f * PI) / 4.0f));
	}

	fill_vector(fft_output, signal_example, FFT_SIZE, SIGNAL_SIZE);

#ifdef DEBUG_MODE
	printf("Signal Example (Complex Form):\n");
	print_vector_cpx(signal_example, SIGNAL_SIZE);
#endif

	fft_dec_time(fft_output, FFT_SIZE, false);
	fft_abs = abs_fft_calc(fft_output, FFT_SIZE);

#ifdef DEBUG_MODE
	printf("FFT Output (Complex Form):\n");
	print_vector_cpx(fft_output, FFT_SIZE);
	printf("FFT Freqs:\n");
	print_vector(fft_freqs, FFT_SIZE);
	printf("FFT Output (Complex Form):\n");
	print_vector_cpx(fft_output, FFT_SIZE);
	printf("FFT Output (Magnitude):\n");
	print_vector(fft_abs, FFT_SIZE);
#endif

	printf("Outputting the data files...\n");
	output_data_cpx("input_signal.txt", signal_example, SIGNAL_SIZE);
	output_data("fft_freqs.txt", fft_freqs, FFT_SIZE);
	output_data_cpx("fft_out.txt", fft_output, FFT_SIZE);
	output_data("fft_abs.txt", fft_abs, FFT_SIZE);

	vector_delete_cpx(signal_example);
	vector_delete_cpx(fft_output);

	vector_delete(fft_freqs);
	vector_delete(fft_abs);

	return 0;
}
