; This test lets globalopt split the global struct and array into different
; values. This used to crash, because globalopt forgot to put the new var in the
; same address space as the old one.

; RUN: llvm-as < %s | opt -globalopt | llvm-dis > %t
; Check that the new global values still have their address space
; RUN: cat %t | grep global.*addrspace

@struct = internal global { i32, i32 } zeroinitializer addrspace(1)
@array = internal global [ 2 x i32 ] zeroinitializer addrspace(1)

define i32 @foo() {
  %A = load i32 addrspace(1) * getelementptr ({ i32, i32 } addrspace(1) * @struct, i32 0, i32 0)
  %B = load i32 addrspace(1) * getelementptr ([ 2 x i32 ] addrspace(1) * @array, i32 0, i32 0)
  ; Use the loaded values, so they won't get removed completely
  %R = add i32 %A, %B
  ret i32 %R
}

; We put stores in a different function, so that the global variables won't get
; optimized away completely.
define void @bar(i32 %R) {
  store i32 %R, i32 addrspace(1) * getelementptr ([ 2 x i32 ] addrspace(1) * @array, i32 0, i32 0)
  store i32 %R, i32 addrspace(1) * getelementptr ({ i32, i32 } addrspace(1) * @struct, i32 0, i32 0)
  ret void
}

