module mod_mro64vg87wwm_mro64vg87wwm


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine matrix_prod(A, B, C, N, M) 

    implicit none

    real(f64), intent(inout) :: A(0:,0:)
    real(f64), intent(inout) :: B(0:,0:)
    real(f64), intent(inout) :: C(0:,0:)
    integer(i64), value :: N
    integer(i64), value :: M
    integer(i64) :: omp_num_threads
    integer(i64) :: i
    integer(i64) :: j
    integer(i64) :: k

    !$omp parallel
    omp_num_threads = 6_i64
    !$omp sections
    !$omp section
    do i = 0_i64, M - 1_i64, 1_i64
      do j = 0_i64, N - 1_i64, 1_i64
        A(j, i) = i + 1_i64 + (j + 1_i64)
      end do
    end do
    !$omp section
    do i = 0_i64, N - 1_i64, 1_i64
      do j = 0_i64, M - 1_i64, 1_i64
        B(j, i) = i + 1_i64 - (j + 1_i64)
      end do
    end do
    !$omp section
    do i = 0_i64, M - 1_i64, 1_i64
      do j = 0_i64, M - 1_i64, 1_i64
        C(j, i) = 0_i64
      end do
    end do
    !$omp end sections nowait
    !Matrix Production
    !$omp do private(j, k)
    do i = 0_i64, M - 1_i64, 1_i64
      do j = 0_i64, M - 1_i64, 1_i64
        do k = 0_i64, N - 1_i64, 1_i64
          C(j, i) = C(j, i) + A(k, i) * B(j, k)
        end do
      end do
    end do
    !$omp end do
    !$omp end parallel

  end subroutine matrix_prod
  !........................................

end module mod_mro64vg87wwm_mro64vg87wwm
