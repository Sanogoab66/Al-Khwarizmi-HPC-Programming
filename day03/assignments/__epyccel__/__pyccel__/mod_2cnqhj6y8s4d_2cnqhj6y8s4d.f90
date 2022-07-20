module mod_2cnqhj6y8s4d_2cnqhj6y8s4d


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function solve_2d_nonlinearconv_pyccel(u, un, v, vn, nt, dt, dx, dy, l &
        ) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: un(0:,0:)
    real(f64), intent(inout) :: v(0:,0:)
    real(f64), intent(inout) :: vn(0:,0:)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: l
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: t
    integer(i64) :: i
    integer(i64) :: j

    !##   Assign initial conditions
    !#   set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    !$omp parallel num_threads(l)
    u(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    !#   set hat function I.C. : v(.5<=x<=1 && .5<=y<=1 ) is 2
    v(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    row = size(u, 2_i64, i64)
    col = size(u, 1_i64, i64)
    !$omp barrier
    !fill the update of u and v
    !$omp do private(i, j)
    do t = 0_i64, nt - 1_i64, 1_i64
      un(:, :) = u(:, :)
      vn(:, :) = v(:, :)
      !mise a jour
      do i = 1_i64, row - 1_i64 - 1_i64, 1_i64
        do j = 1_i64, col - 1_i64 - 1_i64, 1_i64
          u(j, i) = un(j, i) - un(j, i) * (dt / dx) * (un(j, i) - un(j, &
                i - 1_i64)) - vn(j, i) * (dt / dy) * (un(j, i) - un(j - &
                1_i64, i))
          v(j, i) = vn(j, i) - un(j, i) * (dt / dx) * (vn(j, i) - vn(j, &
                i - 1_i64)) - vn(j, i) * (dt / dy) * (vn(j, i) - vn(j - &
                1_i64, i))
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel
    Out_0001 = 0_i64
    return

  end function solve_2d_nonlinearconv_pyccel
  !........................................

end module mod_2cnqhj6y8s4d_2cnqhj6y8s4d
