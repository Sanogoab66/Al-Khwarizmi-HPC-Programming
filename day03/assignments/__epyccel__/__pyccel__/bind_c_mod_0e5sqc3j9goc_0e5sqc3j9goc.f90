module bind_c_mod_0e5sqc3j9goc_0e5sqc3j9goc

  use mod_0e5sqc3j9goc_0e5sqc3j9goc, only: matrix_prod

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine bind_c_matrix_prod(n0_A, n1_A, A, n0_B, n1_B, B, n0_C, n1_C &
        , C, N, M) bind(c)

    implicit none

    integer(i64), value :: n0_A
    integer(i64), value :: n1_A
    real(f64), intent(inout) :: A(0:n1_A - 1_i64,0:n0_A - 1_i64)
    integer(i64), value :: n0_B
    integer(i64), value :: n1_B
    real(f64), intent(inout) :: B(0:n1_B - 1_i64,0:n0_B - 1_i64)
    integer(i64), value :: n0_C
    integer(i64), value :: n1_C
    real(f64), intent(inout) :: C(0:n1_C - 1_i64,0:n0_C - 1_i64)
    integer(i64), value :: N
    integer(i64), value :: M

    call matrix_prod(A, B, C, N, M)

  end subroutine bind_c_matrix_prod
  !........................................

end module bind_c_mod_0e5sqc3j9goc_0e5sqc3j9goc
