module bind_c_mod_jtizepplwkkh_jtizepplwkkh

  use mod_jtizepplwkkh_jtizepplwkkh, only: threads_num

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_threads_num() bind(c) result(n)

    implicit none

    integer(i64) :: n

    n = threads_num()

  end function bind_c_threads_num
  !........................................

end module bind_c_mod_jtizepplwkkh_jtizepplwkkh
