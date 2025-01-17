module mod_qk4s4feg44dk_qk4s4feg44dk


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_1d_burger_pyccel(u, un, nt, nx, dt, dx, nu) result( &
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
    integer(i64) :: j
    integer(i64) :: k

    !fill the update of u
    do i = 0_i64, nt - 1_i64, 1_i64
      do j = 0_i64, nx - 1_i64, 1_i64
        un(j) = u(j)
      end do
      u(:) = 0_i64
      do k = 1_i64, nx - 1_i64 - 1_i64, 1_i64
        u(k) = un(k) - un(k) * (dt / dx) * (un(k) - un(k - 1_i64)) + nu &
              * dt / dx ** 2_i64 * (un(k + 1_i64) - 2_i64 * un(k) + un( &
              k - 1_i64))
      end do
    end do
    Out_0001 = 0_i64
    return

  end function solve_1d_burger_pyccel
  !........................................

end module mod_qk4s4feg44dk_qk4s4feg44dk
