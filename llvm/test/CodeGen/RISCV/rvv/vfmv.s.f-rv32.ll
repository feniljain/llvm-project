; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc -mtriple=riscv32 -mattr=+d,+v,+zfh -target-abi ilp32d -verify-machineinstrs < %s | FileCheck %s

declare <vscale x 1 x half> @llvm.riscv.vfmv.s.f.nxv1f16(<vscale x 1 x half>, half, i32)

define <vscale x 1 x half> @intrinsic_vfmv.s.f_f_nxv1f16(<vscale x 1 x half> %0, half %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv1f16:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e16, mf4, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 1 x half> @llvm.riscv.vfmv.s.f.nxv1f16(<vscale x 1 x half> %0, half %1, i32 %2)
  ret <vscale x 1 x half> %a
}

declare <vscale x 2 x half> @llvm.riscv.vfmv.s.f.nxv2f16(<vscale x 2 x half>, half, i32)

define <vscale x 2 x half> @intrinsic_vfmv.s.f_f_nxv2f16(<vscale x 2 x half> %0, half %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv2f16:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e16, mf2, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 2 x half> @llvm.riscv.vfmv.s.f.nxv2f16(<vscale x 2 x half> %0, half %1, i32 %2)
  ret <vscale x 2 x half> %a
}

declare <vscale x 4 x half> @llvm.riscv.vfmv.s.f.nxv4f16(<vscale x 4 x half>, half, i32)

define <vscale x 4 x half> @intrinsic_vfmv.s.f_f_nxv4f16(<vscale x 4 x half> %0, half %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv4f16:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e16, m1, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 4 x half> @llvm.riscv.vfmv.s.f.nxv4f16(<vscale x 4 x half> %0, half %1, i32 %2)
  ret <vscale x 4 x half> %a
}

declare <vscale x 8 x half> @llvm.riscv.vfmv.s.f.nxv8f16(<vscale x 8 x half>, half, i32)

define <vscale x 8 x half> @intrinsic_vfmv.s.f_f_nxv8f16(<vscale x 8 x half> %0, half %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv8f16:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e16, m2, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 8 x half> @llvm.riscv.vfmv.s.f.nxv8f16(<vscale x 8 x half> %0, half %1, i32 %2)
  ret <vscale x 8 x half> %a
}

declare <vscale x 16 x half> @llvm.riscv.vfmv.s.f.nxv16f16(<vscale x 16 x half>, half, i32)

define <vscale x 16 x half> @intrinsic_vfmv.s.f_f_nxv16f16(<vscale x 16 x half> %0, half %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv16f16:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e16, m4, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 16 x half> @llvm.riscv.vfmv.s.f.nxv16f16(<vscale x 16 x half> %0, half %1, i32 %2)
  ret <vscale x 16 x half> %a
}

declare <vscale x 32 x half> @llvm.riscv.vfmv.s.f.nxv32f16(<vscale x 32 x half>, half, i32)

define <vscale x 32 x half> @intrinsic_vfmv.s.f_f_nxv32f16(<vscale x 32 x half> %0, half %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv32f16:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e16, m8, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 32 x half> @llvm.riscv.vfmv.s.f.nxv32f16(<vscale x 32 x half> %0, half %1, i32 %2)
  ret <vscale x 32 x half> %a
}

declare <vscale x 1 x float> @llvm.riscv.vfmv.s.f.nxv1f32(<vscale x 1 x float>, float, i32)

define <vscale x 1 x float> @intrinsic_vfmv.s.f_f_nxv1f32(<vscale x 1 x float> %0, float %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv1f32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e32, mf2, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 1 x float> @llvm.riscv.vfmv.s.f.nxv1f32(<vscale x 1 x float> %0, float %1, i32 %2)
  ret <vscale x 1 x float> %a
}

declare <vscale x 2 x float> @llvm.riscv.vfmv.s.f.nxv2f32(<vscale x 2 x float>, float, i32)

define <vscale x 2 x float> @intrinsic_vfmv.s.f_f_nxv2f32(<vscale x 2 x float> %0, float %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv2f32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e32, m1, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 2 x float> @llvm.riscv.vfmv.s.f.nxv2f32(<vscale x 2 x float> %0, float %1, i32 %2)
  ret <vscale x 2 x float> %a
}

declare <vscale x 4 x float> @llvm.riscv.vfmv.s.f.nxv4f32(<vscale x 4 x float>, float, i32)

define <vscale x 4 x float> @intrinsic_vfmv.s.f_f_nxv4f32(<vscale x 4 x float> %0, float %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv4f32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e32, m2, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 4 x float> @llvm.riscv.vfmv.s.f.nxv4f32(<vscale x 4 x float> %0, float %1, i32 %2)
  ret <vscale x 4 x float> %a
}

declare <vscale x 8 x float> @llvm.riscv.vfmv.s.f.nxv8f32(<vscale x 8 x float>, float, i32)

define <vscale x 8 x float> @intrinsic_vfmv.s.f_f_nxv8f32(<vscale x 8 x float> %0, float %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv8f32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e32, m4, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 8 x float> @llvm.riscv.vfmv.s.f.nxv8f32(<vscale x 8 x float> %0, float %1, i32 %2)
  ret <vscale x 8 x float> %a
}

declare <vscale x 16 x float> @llvm.riscv.vfmv.s.f.nxv16f32(<vscale x 16 x float>, float, i32)

define <vscale x 16 x float> @intrinsic_vfmv.s.f_f_nxv16f32(<vscale x 16 x float> %0, float %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv16f32:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e32, m8, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 16 x float> @llvm.riscv.vfmv.s.f.nxv16f32(<vscale x 16 x float> %0, float %1, i32 %2)
  ret <vscale x 16 x float> %a
}

declare <vscale x 1 x double> @llvm.riscv.vfmv.s.f.nxv1f64(<vscale x 1 x double>, double, i32)

define <vscale x 1 x double> @intrinsic_vfmv.s.f_f_nxv1f64(<vscale x 1 x double> %0, double %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv1f64:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e64, m1, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 1 x double> @llvm.riscv.vfmv.s.f.nxv1f64(<vscale x 1 x double> %0, double %1, i32 %2)
  ret <vscale x 1 x double> %a
}

declare <vscale x 2 x double> @llvm.riscv.vfmv.s.f.nxv2f64(<vscale x 2 x double>, double, i32)

define <vscale x 2 x double> @intrinsic_vfmv.s.f_f_nxv2f64(<vscale x 2 x double> %0, double %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv2f64:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e64, m2, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 2 x double> @llvm.riscv.vfmv.s.f.nxv2f64(<vscale x 2 x double> %0, double %1, i32 %2)
  ret <vscale x 2 x double> %a
}

declare <vscale x 4 x double> @llvm.riscv.vfmv.s.f.nxv4f64(<vscale x 4 x double>, double, i32)

define <vscale x 4 x double> @intrinsic_vfmv.s.f_f_nxv4f64(<vscale x 4 x double> %0, double %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv4f64:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e64, m4, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 4 x double> @llvm.riscv.vfmv.s.f.nxv4f64(<vscale x 4 x double> %0, double %1, i32 %2)
  ret <vscale x 4 x double> %a
}

declare <vscale x 8 x double> @llvm.riscv.vfmv.s.f.nxv8f64(<vscale x 8 x double>, double, i32)

define <vscale x 8 x double> @intrinsic_vfmv.s.f_f_nxv8f64(<vscale x 8 x double> %0, double %1, i32 %2) nounwind {
; CHECK-LABEL: intrinsic_vfmv.s.f_f_nxv8f64:
; CHECK:       # %bb.0: # %entry
; CHECK-NEXT:    vsetvli zero, a0, e64, m8, tu, mu
; CHECK-NEXT:    vfmv.s.f v8, fa0
; CHECK-NEXT:    ret
entry:
  %a = call <vscale x 8 x double> @llvm.riscv.vfmv.s.f.nxv8f64(<vscale x 8 x double> %0, double %1, i32 %2)
  ret <vscale x 8 x double> %a
}
