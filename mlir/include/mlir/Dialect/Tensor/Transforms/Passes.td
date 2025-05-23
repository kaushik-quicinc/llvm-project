//===-- Passes.td - pass definition file -------------------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_TENSOR_TRANSFORMS_PASSES
#define MLIR_DIALECT_TENSOR_TRANSFORMS_PASSES

include "mlir/Pass/PassBase.td"

def FoldTensorSubsetOpsPass : Pass<"fold-tensor-subset-ops"> {
  let summary = "Fold tensor subset ops into producer/consumer ops";
  let description = [{
    The pass folds tensor subset ops into producer/consumer ops.

    At the moment, the following foldings occur when possible:
      - tensor.extract_slice into vector.transfer_read
      - vector.transfer_write into tensor.insert_slice

  }];
  let dependentDialects = [
      "affine::AffineDialect", "tensor::TensorDialect", "vector::VectorDialect"
  ];
}

#endif // MLIR_DIALECT_TENSOR_TRANSFORMS_PASSES
