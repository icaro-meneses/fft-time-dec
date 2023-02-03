# Atividade: Implementação da DFT usando a matriz

É uma atividade que consiste na implementação da Transformada Rápida de 
Fourier(FFT) por decimação no Tempo (algoritmo de Cooley-Tukey(1965)).

## Dependências

Na sua distribuição linux, certifique-se de já ter instalado os pacotes:

- gcc
- make
- octave
- pdflatex

## Instruções de Build e Execução

1. Clone o repositório na sua máquina

```
$ git clone https://github.com/icaro-meneses/fft-time-dec
$ cd fft-time-dec
```

2. Para realizar a compilação do programa

```
$ make release
```

3. Para executar somente o programa:

```
$ ./fft_time_dec.x
```

ou

```
$ make run
```

4. Para executar o programa e exportar o arquivo em .pdf:

```
$ make run graph
```

5. Caso precise fazer a limpeza dos arquivos, execute: `make clean`

6. **Extra:** Para realizar a compilação no modo de DEBUG:

```
$ make debug
```

**Nota:** O código ainda requer testes.

