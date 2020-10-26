#include <benchmark/benchmark.h>
#include <string.h>
#include <cstdint>
#include <limits>

#define N (32*1024)

double A[N];
double B[N];
double sum = 0;

#define BODY \
  if (i % 3 != 0) \
    sum += A[i]; \
  else \
    A[i] = A[i-1] + i;
  
//  A[i] = A[i-1] + i;
 
 // sum += A[i];

static void NoUnroll(benchmark::State &state) {
  for (auto _ : state) {
    #pragma nounroll
    for (int i = 1; i < N; ++i) {
      BODY
    }
    benchmark::ClobberMemory();
  }
}
BENCHMARK(NoUnroll);


static void Unroll4(benchmark::State &state) {
  for (auto _ : state) {
    #pragma unroll 4
    for (int i = 1; i < N; ++i) {
      BODY
    }
    benchmark::ClobberMemory();
  }
}
BENCHMARK(Unroll4);


static void Unroll16(benchmark::State &state) {
  for (auto _ : state) {
    #pragma unroll 16
    for (int i = 1; i < N; ++i) {
      BODY
    }
    benchmark::ClobberMemory();
  }
}
BENCHMARK(Unroll16);

static void Unroll64(benchmark::State &state) {
  for (auto _ : state) {
    #pragma unroll 64
    for (int i = 1; i < N; ++i) {
      BODY
    }
    benchmark::ClobberMemory();
  }
}
BENCHMARK(Unroll64);

static void Unroll128(benchmark::State &state) {
  for (auto _ : state) {
    #pragma unroll 128
    for (int i = 1; i < N; ++i) {
      BODY
    }
    benchmark::ClobberMemory();
  }
}
BENCHMARK(Unroll128);

static void Unroll256(benchmark::State &state) {
  for (auto _ : state) {
    #pragma unroll 256
    for (int i = 1; i < N; ++i) {
      BODY
    }
    benchmark::ClobberMemory();
  }
}
BENCHMARK(Unroll256);



BENCHMARK_MAIN();
