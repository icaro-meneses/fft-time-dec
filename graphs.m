close all;
clear all;
clc;

%%
% Data reading from file
data_fft_abs = fopen('./fft_abs.txt', 'r');
data_fft_frq = fopen('./fft_freqs.txt', 'r');

sig_in_cpx = dlmread('./input_signal.txt', ' ', 0, 0);
fft_cpx = dlmread('./fft_out.txt', ' ', 0, 0);
fft_abs = fscanf(data_fft_abs, "%f\n");
fft_frq = fscanf(data_fft_frq, "%f\n");

fclose(data_fft_abs);
fclose(data_fft_frq);

sig_in_real = sig_in_cpx(:, 1);
sig_in_imag = sig_in_cpx(:, 2);
fft_real = fft_cpx(:, 1);
fft_imag = fft_cpx(:, 2);
N_fft = length(fft_abs);
n_signal = [0: 1: length(sig_in_real) - 1];

%%
% DFT Plots
fft_fig = figure();
subplot(2, 1, 1);
stem(fft_frq, fft_abs / (N_fft / 2), 'filled', 'linewidth', 2);
set(gca, 'FontSize', 8);
hold on;
title('FFT Magnitude', 'fontsize', 12);
grid on;
hold off;

subplot(2, 1, 2);
stem(fft_frq, fft_real, 'filled', 'linewidth', 2);
set(gca, 'FontSize', 8);
hold on;
stem(fft_frq, fft_imag, 'filled', 'linewidth', 2);
title('FFT in Complex Form', 'fontsize', 12);
legend({'Real part', 'Imaginary part'}, 'fontsize', 10);
grid on;
hold off;

print_size = "-S1024,768";
print(fft_fig, "fft_plot.pdf", "-dpdflatexstandalone", print_size);
system("pdflatex fft_plot");

