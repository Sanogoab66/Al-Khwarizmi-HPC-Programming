module mod_jtizepplwkkh_jtizepplwkkh


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function threads_num() result(n)

    use omp_lib, only: omp_get_num_threads

    implicit none

    integer(i64) :: n

    !complete your function
    n = omp_get_num_threads()
    return

  end function threads_num
  !........................................

end module mod_jtizepplwkkh_jtizepplwkkh