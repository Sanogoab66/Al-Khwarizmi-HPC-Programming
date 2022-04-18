module mod_pm9flcwrmjeq_pm9flcwrmjeq


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_1d_diff_pyccel(u, un, nt, nx, dt, dx, nu) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:)
    real(f64), intent(inout) :: un(0:)
    integer(i64), value :: nt
    integer(i64), value :: nx
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: nu
    integer(i64) :: i
    integer(i64) :: k
    integer(i64) :: j

    do i = 0_i64, nt - 1_i64, 1_i64
      do k = 0_i64, nx - 1_i64, 1_i64
        un(k) = u(k)
      end do
      do j = 1_i64, nx - 1_i64 - 1_i64, 1_i64
        u(j) = un(j) + nu * dt / dx ** 2_i64 * (un(j + 1_i64) - 2_i64 * &
              un(j) + un(j - 1_i64))
      end do
    end do
    !fill the update of u
    Out_0001 = 0_i64
    return

  end function solve_1d_diff_pyccel
  !........................................

end module mod_pm9flcwrmjeq_pm9flcwrmjeq
