module bind_c_mod_7x9tyob01g3s_7x9tyob01g3s

  use mod_7x9tyob01g3s_7x9tyob01g3s, only: factorial_itr

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_factorial_itr(n) bind(c) result(k)

    implicit none

    integer(i64), value :: n
    integer(i64) :: k

    k = factorial_itr(n)

  end function bind_c_factorial_itr
  !........................................

end module bind_c_mod_7x9tyob01g3s_7x9tyob01g3s
