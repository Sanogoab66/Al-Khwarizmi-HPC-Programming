module mod_owwwg7hihh3d_owwwg7hihh3d


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine navier_openmp(nit, nt, u, un, b, v, vn, dt, nx, ny, dx, dy, &
        p, pn, rho, nu, num)

    implicit none

    integer(i64), value :: nit
    integer(i64), value :: nt
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: un(0:,0:)
    real(f64), intent(inout) :: b(0:,0:)
    real(f64), intent(inout) :: v(0:,0:)
    real(f64), intent(inout) :: vn(0:,0:)
    real(f64), value :: dt
    integer(i64), value :: nx
    integer(i64), value :: ny
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), intent(inout) :: p(0:,0:)
    real(f64), intent(inout) :: pn(0:,0:)
    integer(i64), value :: rho
    real(f64), value :: nu
    integer(i64), value :: num
    integer(i64) :: n
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: q

    !un = u
    !vn = v
    !b = u
    !$omp parallel num_threads(num)
    !$omp do
    do n = 0_i64, nt - 1_i64, 1_i64
      un(:, :) = u(:, :)
      vn(:, :) = v(:, :)
      !$omp sections
      !$omp section
      !Calcul de p
      row = size(p, 2_i64, i64)
      col = size(p, 1_i64, i64)
      b(1_i64:size(b, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(b, 2_i64, &
            i64) - 1_i64 - 1_i64) = rho * (1_i64 / dt * ((u(2_i64:, &
            1_i64:size(u, 2_i64, i64) - 1_i64 - 1_i64) - u(0_i64:size(u &
            , 1_i64, i64) - 2_i64 - 1_i64, 1_i64:size(u, 2_i64, i64) - &
            1_i64 - 1_i64)) / (2_i64 * dx) + (v(1_i64:size(v, 1_i64, &
            i64) - 1_i64 - 1_i64, 2_i64:) - v(1_i64:size(v, 1_i64, i64 &
            ) - 1_i64 - 1_i64, 0_i64:size(v, 2_i64, i64) - 2_i64 - &
            1_i64)) / (2_i64 * dy)) - ((u(2_i64:, 1_i64:size(u, 2_i64, &
            i64) - 1_i64 - 1_i64) - u(0_i64:size(u, 1_i64, i64) - 2_i64 &
            - 1_i64, 1_i64:size(u, 2_i64, i64) - 1_i64 - 1_i64)) / ( &
            2_i64 * dx)) ** 2_i64 - 2_i64 * ((u(1_i64:size(u, 1_i64, &
            i64) - 1_i64 - 1_i64, 2_i64:) - u(1_i64:size(u, 1_i64, i64 &
            ) - 1_i64 - 1_i64, 0_i64:size(u, 2_i64, i64) - 2_i64 - &
            1_i64)) / (2_i64 * dy) * (v(2_i64:, 1_i64:size(v, 2_i64, &
            i64) - 1_i64 - 1_i64) - v(0_i64:size(v, 1_i64, i64) - 2_i64 &
            - 1_i64, 1_i64:size(v, 2_i64, i64) - 1_i64 - 1_i64)) / ( &
            2_i64 * dx)) - ((v(1_i64:size(v, 1_i64, i64) - 1_i64 - &
            1_i64, 2_i64:) - v(1_i64:size(v, 1_i64, i64) - 1_i64 - &
            1_i64, 0_i64:size(v, 2_i64, i64) - 2_i64 - 1_i64)) / (2_i64 &
            * dy)) ** 2_i64)
      !$omp section
      !Calcul de p
      pn(:, :) = p(:, :)
      !$omp do
      do q = 0_i64, nit - 1_i64, 1_i64
        pn(:, :) = p(:, :)
        p(1_i64:size(p, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(p, 2_i64 &
              , i64) - 1_i64 - 1_i64) = ((pn(2_i64:, 1_i64:size(pn, &
              2_i64, i64) - 1_i64 - 1_i64) + pn(0_i64:size(pn, 1_i64, &
              i64) - 2_i64 - 1_i64, 1_i64:size(pn, 2_i64, i64) - 1_i64 &
              - 1_i64)) * dy ** 2_i64 + (pn(1_i64:size(pn, 1_i64, i64) &
              - 1_i64 - 1_i64, 2_i64:) + pn(1_i64:size(pn, 1_i64, i64) &
              - 1_i64 - 1_i64, 0_i64:size(pn, 2_i64, i64) - 2_i64 - &
              1_i64)) * dx ** 2_i64) / (2_i64 * (dx ** 2_i64 + dy ** &
              2_i64)) - dx ** 2_i64 * dy ** 2_i64 / (2_i64 * (dx ** &
              2_i64 + dy ** 2_i64)) * b(1_i64:size(b, 1_i64, i64) - &
              1_i64 - 1_i64, 1_i64:size(b, 2_i64, i64) - 1_i64 - 1_i64)
        p(size(p, 1_i64, i64) - 1_i64, :) = p(size(p, 1_i64, i64) - &
              2_i64, :)
        p(:, 0_i64) = p(:, 1_i64)
        p(0_i64, :) = p(1_i64, :)
        p(:, size(p, 2_i64, i64) - 1_i64) = 0_i64
      end do
      !$omp end do
      !$omp section
      u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(u, 2_i64, &
            i64) - 1_i64 - 1_i64) = un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) &
            - un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size &
            (un, 2_i64, i64) - 1_i64 - 1_i64) * dt / dx * (un(1_i64: &
            size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64, &
            i64) - 1_i64 - 1_i64) - un(0_i64:size(un, 1_i64, i64) - &
            2_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64 &
            )) - vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64: &
            size(vn, 2_i64, i64) - 1_i64 - 1_i64) * dt / dy * (un(1_i64 &
            :size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64 &
            , i64) - 1_i64 - 1_i64) - un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(un, 2_i64, i64) - 2_i64 - 1_i64 &
            )) - dt / (2_i64 * rho * dx) * (p(2_i64:, 1_i64:size(p, &
            2_i64, i64) - 1_i64 - 1_i64) - p(0_i64:size(p, 1_i64, i64) &
            - 2_i64 - 1_i64, 1_i64:size(p, 2_i64, i64) - 1_i64 - 1_i64 &
            )) + nu * (dt / dx ** 2_i64 * (un(2_i64:, 1_i64:size(un, &
            2_i64, i64) - 1_i64 - 1_i64) - 2_i64 * un(1_i64:size(un, &
            1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - &
            1_i64 - 1_i64) + un(0_i64:size(un, 1_i64, i64) - 2_i64 - &
            1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64)) + dt / &
            dy ** 2_i64 * (un(1_i64:size(un, 1_i64, i64) - 1_i64 - &
            1_i64, 2_i64:) - 2_i64 * un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) &
            + un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 0_i64:size &
            (un, 2_i64, i64) - 2_i64 - 1_i64)))
      v(1_i64:size(v, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(v, 2_i64, &
            i64) - 1_i64 - 1_i64) = vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) &
            - un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size &
            (un, 2_i64, i64) - 1_i64 - 1_i64) * dt / dx * (vn(1_i64: &
            size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64, &
            i64) - 1_i64 - 1_i64) - vn(0_i64:size(vn, 1_i64, i64) - &
            2_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64 &
            )) - vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64: &
            size(vn, 2_i64, i64) - 1_i64 - 1_i64) * dt / dy * (vn(1_i64 &
            :size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64 &
            , i64) - 1_i64 - 1_i64) - vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(vn, 2_i64, i64) - 2_i64 - 1_i64 &
            )) - dt / (2_i64 * rho * dy) * (p(1_i64:size(p, 1_i64, i64 &
            ) - 1_i64 - 1_i64, 2_i64:) - p(1_i64:size(p, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(p, 2_i64, i64) - 2_i64 - 1_i64)) &
            + nu * (dt / dx ** 2_i64 * (vn(2_i64:, 1_i64:size(vn, 2_i64 &
            , i64) - 1_i64 - 1_i64) - 2_i64 * vn(1_i64:size(vn, 1_i64, &
            i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - &
            1_i64) + vn(0_i64:size(vn, 1_i64, i64) - 2_i64 - 1_i64, &
            1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64)) + dt / dy ** &
            2_i64 * (vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, &
            2_i64:) - 2_i64 * vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - &
            1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) + vn( &
            1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 0_i64:size(vn, &
            2_i64, i64) - 2_i64 - 1_i64)))
      u(:, 0_i64) = 0_i64
      u(0_i64, :) = 0_i64
      u(size(u, 1_i64, i64) - 1_i64, :) = 0_i64
      u(:, size(u, 2_i64, i64) - 1_i64) = 1_i64
      v(:, 0_i64) = 0_i64
      v(:, size(v, 2_i64, i64) - 1_i64) = 0_i64
      v(0_i64, :) = 0_i64
      v(size(v, 1_i64, i64) - 1_i64, :) = 0_i64
    end do
    !$omp end do
    !$omp end sections
    !$omp end parallel

  end subroutine navier_openmp
  !........................................

end module mod_owwwg7hihh3d_owwwg7hihh3d
