// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 5
// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -o - -emit-llvm %s | opt -S -passes=mem2reg | FileCheck %s
// Test ARM64 SIMD vcreate intrinsics

// REQUIRES: aarch64-registered-target || arm-registered-target

#include <arm_neon.h>

// CHECK-LABEL: define <2 x float> @test_vcreate_f32(
// CHECK-SAME: i64 noundef [[A1:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-NEXT:  [[ENTRY:.*:]]
// CHECK-NEXT:    [[A1_ADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[__RET:%.*]] = alloca <2 x float>, align 8
// CHECK-NEXT:    [[__PROMOTE:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[TMP:%.*]] = alloca <2 x float>, align 8
// CHECK-NEXT:    store i64 [[A1]], ptr [[A1_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load i64, ptr [[A1_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0]], ptr [[__PROMOTE]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load <2 x float>, ptr [[__PROMOTE]], align 8
// CHECK-NEXT:    store <2 x float> [[TMP1]], ptr [[__RET]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load <2 x float>, ptr [[__RET]], align 8
// CHECK-NEXT:    store <2 x float> [[TMP2]], ptr [[TMP]], align 8
// CHECK-NEXT:    [[TMP3:%.*]] = load <2 x float>, ptr [[TMP]], align 8
// CHECK-NEXT:    ret <2 x float> [[TMP3]]
//
float32x2_t test_vcreate_f32(uint64_t a1) {
  return vcreate_f32(a1);
}
