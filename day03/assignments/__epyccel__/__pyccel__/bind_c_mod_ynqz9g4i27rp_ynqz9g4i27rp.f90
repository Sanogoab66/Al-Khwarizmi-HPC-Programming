module bind_c_mod_ynqz9g4i27rp_ynqz9g4i27rp

  use mod_ynqz9g4i27rp_ynqz9g4i27rp, only: threads_num

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

end module bind_c_mod_ynqz9g4i27rp_ynqz9g4i27rp
