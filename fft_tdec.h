/*
 * ======================================================================
 *
 *       Filename:  fft_tdec.h
 *
 *    Description:  Header file for function prototypes for
 *					the implementation of FFT (decimation in
 *					time).
 *
 *        Version:  1.0
 *        Created:  25/01/23 16:29:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Icaro Meneses Ferreira de Santana
 *					(Icaro Meneses),
 *					icaro.santana.dev@hotmail.com
 *
 * ======================================================================
 */

#ifndef FFT_TDEC_LIB_H
#define FFT_TDEC_LIB_H

#include <complex.h>
#include <stdbool.h>

#define PI	   3.141592653589793f
#define TWO_PI (2.0f * PI)

/*
 * ===  FUNCTION  ==================================================
 *         Name:  fill_vector
 *  Description:  Fill a (Nx1) destination vector with source
 *				  signal vector.
 * =================================================================
 */
void
fill_vector(float complex* dest_vector,
			float complex* src_vector,
			const int dest_vector_size,
			const int src_vector_size);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  get_fft_freqs
 *  Description:  Fill a array with the FFT sample frequencies
 * ==================================================================
 */
void
get_fft_freqs(float* freq_array,
			  const int window_length,
			  const float sample_spacing);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  fft_dec_time
 *  Description:  Performs the Fast Fourier Transform (Decimation
 *				  in time) of a sampled signal as input and
 *				  returns a vector with the complex values of FFT.
 *				  The parameter inverse_mode determines if the
 *				  procedure performed will be FFT or IFFT.
 * =================================================================
 */
void
fft_dec_time(float complex* signal, int N, bool inverse_mode);

/*
 * ===  FUNCTION  ==================================================
 *         Name:  abs_fft_calc
 *  Description:  Calculates the magnitude(absolute value) of
 *				  a previous calculated FFT.
 * =================================================================
 */
float*
abs_fft_calc(float complex* fft, const int fft_size);

#endif
